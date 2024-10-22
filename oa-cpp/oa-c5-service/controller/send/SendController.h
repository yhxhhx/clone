#pragma once
#ifndef _SENDCONTROLLER_H_
#define _SENDCONTROLLER_H_

#include "domain/dto/send/sendDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SendController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
    // 2 定义控制器访问入口
    API_ACCESS_DECLARE(SendController);

public:
    // 3.1 定义发送消息接口描述
    ENDPOINT_INFO(sendMessage) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("send.post.summary"));
        // 定义默认授权参数
        API_DEF_ADD_AUTH();
        API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("send.field.type"), "11111111111", false);
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("send.field.code"), "000000", false);
    }

    // 3.2 定义发送消息接口处理
    ENDPOINT(API_M_POST, "/message/send", sendMessage, BODY_DTO(SendDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 校验传入参数
        if (dto->message->empty() || dto->code->empty()) {
            return createResponse(Status::CODE_400, "Message and code must not be empty.");
        }
        // 调用执行函数响应结果
        API_HANDLER_RESP_VO(execSendMessage(dto));
    }

private:
    // 3.3 执行发送消息的具体逻辑
    MessageSendJsonVO::Wrapper execSendMessage(const SendDTO::Wrapper& dto) {
        // 这里通常会调用服务类执行消息发送逻辑
        auto result = MessageSendJsonVO::createShared();
        result->success("Message sent successfully.");
        return result;
    }
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_