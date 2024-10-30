#pragma once

#ifndef _WSLISTENER_H_
#define _WSLISTENER_H_
#include "oatpp-websocket/WebSocket.hpp"
#include "oatpp-websocket/ConnectionHandler.hpp"
#include <map>
#include "RocketClient.h"
#include "domain\dto\System\inform\SystemInformDTO.h"
#include <iostream>
#include <mutex>
#include <thread>
#include "Macros.h"
#include "NacosClient.h"

/**
 * WebSocket侦听器,侦听传入的WebSocket事件
 */
class WSListener : public oatpp::websocket::WebSocket::Listener,public RocketClient::RConsumerListener
{
private:
	static constexpr const char* TAG = "Server_WSListener";
	// 消息缓冲区
	oatpp::data::stream::BufferOutputStream m_messageBuffer;
	// 用户ID
	std::string id;
	// 加入聊天室用户列表
	std::map<std::string, const WebSocket*>* conn_pool;

	RocketClient* rocketClient;
	//消息主题
	string topic = "send";
	// 配置服务器地址
	string namesrv;
public:
	// 获取ID
	const std::string& getId();
	// 构造初始化
	WSListener() {};
	WSListener(std::string id, std::map<std::string, const WebSocket*>* conn_pool);
	// 析构函数
	virtual ~WSListener();
	// 在ping帧上调用
	void onPing(const WebSocket& socket, const oatpp::String& message) override;
	// 在pong帧上调用
	void onPong(const WebSocket& socket, const oatpp::String& message) override;
	// 在close帧上调用
	void onClose(const WebSocket& socket, v_uint16 code, const oatpp::String& message) override;
	// 在每个消息帧上调用。最后一条消息将再次调用，size等于0以指定消息结束
	void readMessage(const WebSocket& socket, v_uint8 opcode, p_char8 data, oatpp::v_io_size size) override;
	//空实现
	void receiveMessage(std::string payload) override;
	// 向客户端发送消息
	void SendMessage(string Id, string msg);
	//订阅RocketMQ
	void WbSubscribe();
};

#endif // !_WSLISTENER_H_

