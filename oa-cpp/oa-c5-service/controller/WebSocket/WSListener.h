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
 * WebSocket������,���������WebSocket�¼�
 */
class WSListener : public oatpp::websocket::WebSocket::Listener,public RocketClient::RConsumerListener
{
private:
	static constexpr const char* TAG = "Server_WSListener";
	// ��Ϣ������
	oatpp::data::stream::BufferOutputStream m_messageBuffer;
	// �û�ID
	std::string id;
	// �����������û��б�
	std::map<std::string, const WebSocket*>* conn_pool;

	RocketClient* rocketClient;
	//��Ϣ����
	string topic = "send";
	// ���÷�������ַ
	string namesrv;
public:
	// ��ȡID
	const std::string& getId();
	// �����ʼ��
	WSListener() {};
	WSListener(std::string id, std::map<std::string, const WebSocket*>* conn_pool);
	// ��������
	virtual ~WSListener();
	// ��ping֡�ϵ���
	void onPing(const WebSocket& socket, const oatpp::String& message) override;
	// ��pong֡�ϵ���
	void onPong(const WebSocket& socket, const oatpp::String& message) override;
	// ��close֡�ϵ���
	void onClose(const WebSocket& socket, v_uint16 code, const oatpp::String& message) override;
	// ��ÿ����Ϣ֡�ϵ��á����һ����Ϣ���ٴε��ã�size����0��ָ����Ϣ����
	void readMessage(const WebSocket& socket, v_uint8 opcode, p_char8 data, oatpp::v_io_size size) override;
	//��ʵ��
	void receiveMessage(std::string payload) override;
	// ��ͻ��˷�����Ϣ
	void SendMessage(string Id, string msg);
	//����RocketMQ
	void WbSubscribe();
};

#endif // !_WSLISTENER_H_

