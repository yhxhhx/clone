#pragma once
#ifndef _WSCONTROLLER_H_
#define _WSCONTROLLER_H_
#include "ApiHelper.h"
#include "oatpp-websocket/Handshaker.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- codegen begin
/**
 * 测试WebSocket访问端点创建
 */
class WSContorller : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(WSContorller);
private:
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, websocketConnectionHandler, "sendMessage");
public:
	ENDPOINT(API_M_GET, "chat", chat, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		auto response = oatpp::websocket::Handshaker::serversideHandshake(request->getHeaders(), websocketConnectionHandler);
		auto parameters = std::make_shared<oatpp::network::ConnectionHandler::ParameterMap>();
		(*parameters)["id"] = request->getQueryParameter("id");
		response->setConnectionUpgradeParameters(parameters);
		return response;
	};
};
#include OATPP_CODEGEN_END(ApiController) //<-- codegen begin
#endif // !_WSCONTROLLER_H_