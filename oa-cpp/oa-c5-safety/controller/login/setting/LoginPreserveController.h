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
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addlogin) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("login.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/templet-add/templet-info", addlogin, BODY_DTO(LoginSettingDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execPreserveLogin(dto));
	}

private:
	Uint64JsonVO::Wrapper execPreserveLogin(const LoginSettingDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif