#pragma once
#ifndef _WSINSTANCELISTENER_H_
#define _WSINSTANCELISTENER_H_
#include "oatpp-websocket/ConnectionHandler.hpp"
#include <map>

/**
 * 定义示例WS实例监听器
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
	// 定义一个连接对象池
	std::map<std::string, const WebSocket*> conn_pool;
	// 定义一个锁对象
	std::mutex instance_mutex;
public:
	// 当socket实例创建时调用
	void onAfterCreate(const WebSocket& socket, const std::shared_ptr<const ParameterMap>& params) override;
	// 当socket实例销毁前调用
	void onBeforeDestroy(const WebSocket& socket) override;
};

#endif // !_WSINSTANCELISTENER_H_