#include "stdafx.h"

#include "WSListener.h"
#include "StringUtil.h"

#ifndef TEST_NS_ADDR
#define TEST_NS_ADDR "192.168.163.131:8848"
#endif

#ifndef TEST_NS_NAMESPACE
#define TEST_NS_NAMESPACE "oa-dev"
#endif

// 定义一个锁对象
std::mutex listener_mutex;

const std::string& WSListener::getId()
{
	return this->id;
}

WSListener::WSListener(std::string id, std::map<std::string, const WebSocket*>* conn_pool)
{
	this->id = id;
	this->conn_pool = conn_pool;
	// 获取配置，用于将未发送消息放到RocketMQ中的unsend主题中
	NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("third-services.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/third-services.yaml");
#endif
	this->namesrv = YamlHelper().getString(&node, "rocket-mq.name-server");
	this->rocketClient = new RocketClient(this->namesrv);
	this->WbSubscribe(); // 订阅和添加监听器
}

WSListener::~WSListener() {
	this->rocketClient->unsubscribe();
	this->rocketClient->removeAllListener();
	delete this->rocketClient;
}

void WSListener::onPing(const WebSocket& socket, const oatpp::String& message)
{
	OATPP_LOGD(TAG, "onPing");
	socket.sendPong(message);
}

void WSListener::onPong(const WebSocket& socket, const oatpp::String& message)
{
	OATPP_LOGD(TAG, "onPong");
}

void WSListener::onClose(const WebSocket& socket, v_uint16 code, const oatpp::String& message)
{
	OATPP_LOGD(TAG, "onClose code=%d", code);
}

void WSListener::readMessage(const WebSocket& socket, v_uint8 opcode, p_char8 data, oatpp::v_io_size size)
{
	// message transfer finished
	if (size == 0)
	{
		// 获取消息数据
		auto wholeMessage = m_messageBuffer.toString().getValue("");
		m_messageBuffer.setCurrentPosition(0);
		OATPP_LOGD(TAG, "onMessage message='%s'", wholeMessage.c_str());
		// 解析消息 => ID::消息内容
		std::vector<string> msgs = StringUtil::split(wholeMessage.c_str(), "::");
		// 群发消息ID=all表示群发
		if ("all" == msgs[0])
		{
			std::lock_guard<std::mutex> guard(listener_mutex);
			for (auto one : *conn_pool)
			{
				// 排除自己
				if (one.second == &socket)
				{
					continue;
				}
				// 发送消息
				one.second->sendOneFrameText(msgs[1]);
			}
		}
		// 指定发送
		else
		{
			std::lock_guard<std::mutex> guard(listener_mutex);
			auto iter = conn_pool->find(msgs[0]);
			if (iter != conn_pool->end())
			{
				iter->second->sendOneFrameText(msgs[1]);
			}
		}
		socket.sendOneFrameText("message send success");
	}
	// message frame received
	else if (size > v_int64(0))
	{
		m_messageBuffer.writeSimple(data, v_buff_size(size));
	}
}

void WSListener::SendMessage(string Id, string msg) {
	//群发
	if (Id == "all") {
		std::lock_guard<std::mutex> guard(listener_mutex);
		for (auto one : *conn_pool) {
			// 发送消息
			one.second->sendOneFrameText(msg);
		}
	}
	//单发
	else {
		std::lock_guard<std::mutex> guard(listener_mutex);
		auto iter = conn_pool->find(Id);
		//用户在线
		if (iter != conn_pool->end())
		{
			iter->second->sendOneFrameText(msg);
		}
		//用户不在线，放到unsend主题中
		else {
			string data = Id + msg;
			rocketClient->productMsgSync("unsend", data);
		}
	}
}

void WSListener::receiveMessage(std::string payload) {
	return;
}


void WSListener::WbSubscribe() {
	//订阅主题
	rocketClient->subscribe(topic);
	//添加消息监听器
	rocketClient->addListener(this);
}