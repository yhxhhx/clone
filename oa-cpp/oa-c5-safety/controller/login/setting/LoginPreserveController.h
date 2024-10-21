#pragma once

#ifndef  _LOGINPRESERVECONTROLLER_H_
#define  _LOGINPRESERVECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/login/setting/LoginSettingDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class LoginPreserveController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(LoginPreserveController);
public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addlogin) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("login.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/templet-add/templet-info", addlogin, BODY_DTO(LoginSettingDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execPreserveLogin(dto));
	}

private:
	Uint64JsonVO::Wrapper execPreserveLogin(const LoginSettingDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif