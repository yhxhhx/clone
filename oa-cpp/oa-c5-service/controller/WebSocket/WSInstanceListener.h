#pragma once

#ifndef _WSINSTANCELISTENER_H_
#define _WSINSTANCELISTENER_H_
#include "oatpp-websocket/ConnectionHandler.hpp"
#include "oatpp-websocket/WebSocket.hpp"

/**
 * 定义WS实例监听器
 */
class WSInstanceListener : public oatpp::websocket::ConnectionHandler::SocketInstanceListener
{
private:
	static constexpr const char* TAG = "Server_WSInstanceListener";
public:
	//连接客户端的计数器
	static std::atomic<v_int32> SOCKETS;

public:
	// 当websocket实例创建时调用
	void onAfterCreate(const WebSocket& socket, const std::shared_ptr<const ParameterMap>& params) override;
	// 当websocket实例销毁前调用
	void onBeforeDestroy(const WebSocket& socket) override;
};

#endif // !_WSINSTANCELISTENER_H_