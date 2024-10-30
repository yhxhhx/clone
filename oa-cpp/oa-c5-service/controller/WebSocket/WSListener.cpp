#include "stdafx.h"

#include "WSListener.h"
#include "StringUtil.h"

#ifndef TEST_NS_ADDR
#define TEST_NS_ADDR "192.168.163.131:8848"
#endif

#ifndef TEST_NS_NAMESPACE
#define TEST_NS_NAMESPACE "oa-dev"
#endif

// ����һ��������
std::mutex listener_mutex;

const std::string& WSListener::getId()
{
	return this->id;
}

WSListener::WSListener(std::string id, std::map<std::string, const WebSocket*>* conn_pool)
{
	this->id = id;
	this->conn_pool = conn_pool;
	// ��ȡ���ã����ڽ�δ������Ϣ�ŵ�RocketMQ�е�unsend������
	NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("third-services.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/third-services.yaml");
#endif
	this->namesrv = YamlHelper().getString(&node, "rocket-mq.name-server");
	this->rocketClient = new RocketClient(this->namesrv);
	this->WbSubscribe(); // ���ĺ���Ӽ�����
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
		// ��ȡ��Ϣ����
		auto wholeMessage = m_messageBuffer.toString().getValue("");
		m_messageBuffer.setCurrentPosition(0);
		OATPP_LOGD(TAG, "onMessage message='%s'", wholeMessage.c_str());
		// ������Ϣ => ID::��Ϣ����
		std::vector<string> msgs = StringUtil::split(wholeMessage.c_str(), "::");
		// Ⱥ����ϢID=all��ʾȺ��
		if ("all" == msgs[0])
		{
			std::lock_guard<std::mutex> guard(listener_mutex);
			for (auto one : *conn_pool)
			{
				// �ų��Լ�
				if (one.second == &socket)
				{
					continue;
				}
				// ������Ϣ
				one.second->sendOneFrameText(msgs[1]);
			}
		}
		// ָ������
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
	//Ⱥ��
	if (Id == "all") {
		std::lock_guard<std::mutex> guard(listener_mutex);
		for (auto one : *conn_pool) {
			// ������Ϣ
			one.second->sendOneFrameText(msg);
		}
	}
	//����
	else {
		std::lock_guard<std::mutex> guard(listener_mutex);
		auto iter = conn_pool->find(Id);
		//�û�����
		if (iter != conn_pool->end())
		{
			iter->second->sendOneFrameText(msg);
		}
		//�û������ߣ��ŵ�unsend������
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
	//��������
	rocketClient->subscribe(topic);
	//�����Ϣ������
	rocketClient->addListener(this);
}