#pragma once
#ifndef _WSINSTANCELISTENER_H_
#define _WSINSTANCELISTENER_H_
#include "oatpp-websocket/ConnectionHandler.hpp"
#include <map>

/**
 * ����ʾ��WSʵ��������
 */
class WSInstanceListener : public oatpp::websocket::ConnectionHandler::SocketInstanceListener
{
private:
	static constexpr const char* TAG = "Server_WSInstanceListener";
public:
	/**
	 * Counter for connected clients.
	 */
	static std::atomic<v_int32> SOCKETS;
	// ����һ�����Ӷ����
	std::map<std::string, const WebSocket*> conn_pool;
	// ����һ��������
	std::mutex instance_mutex;
public:
	// ��socketʵ������ʱ����
	void onAfterCreate(const WebSocket& socket, const std::shared_ptr<const ParameterMap>& params) override;
	// ��socketʵ������ǰ����
	void onBeforeDestroy(const WebSocket& socket) override;
};

#endif // !_WSINSTANCELISTENER_H_