#pragma once
#ifndef _SENDCONTROLLER_H_
#define _SENDCONTROLLER_H_

#include "domain/dto/send/sendDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SendController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
    // 2 ����������������
    API_ACCESS_DECLARE(SendController);

public:
    // 3.1 ���巢����Ϣ�ӿ�����
    ENDPOINT_INFO(sendMessage) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("send.post.summary"));
        // ����Ĭ����Ȩ����
        API_DEF_ADD_AUTH();
        API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("send.field.type"), "11111111111", false);
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("send.field.code"), "000000", false);
    }

    // 3.2 ���巢����Ϣ�ӿڴ���
    ENDPOINT(API_M_POST, "/message/send", sendMessage, BODY_DTO(SendDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // У�鴫�����
        if (dto->message->empty() || dto->code->empty()) {
            return createResponse(Status::CODE_400, "Message and code must not be empty.");
        }
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execSendMessage(dto));
    }

private:
    // 3.3 ִ�з�����Ϣ�ľ����߼�
    MessageSendJsonVO::Wrapper execSendMessage(const SendDTO::Wrapper& dto) {
        // ����ͨ������÷�����ִ����Ϣ�����߼�
        auto result = MessageSendJsonVO::createShared();
        result->success("Message sent successfully.");
        return result;
    }
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_