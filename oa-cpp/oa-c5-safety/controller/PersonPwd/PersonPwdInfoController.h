#pragma once
#ifndef _PERSONSEPWDINFOCONTROLLER_H_
#define _PERSONSEPWDINFOCONTROLLER_H_

#include"domain/vo/BaseJsonVO.h"
#include"domain/vo/PersonPwd/PersonPwdInfoVO.h"
#include "domain/dto/PersonPwd/PersonPwdInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PersonPwdInfoController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(PersonPwdInfoController);

public:
	// 获取个人密码信息接口
	ENDPOINT_INFO(queryPersonPwdInfo) {
		// 获取用户密码
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("safety.personpassword.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonPwdInfoJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("safety.personpassword.field.id"), "abc123", true);
	}
	ENDPOINT(API_M_GET, "/safety-setting/person-password", queryPersonPwdInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryPersonPwdInfo(id));
	}

	// 修改个人密码信息接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("safety.personpassword.put.summary"), modifyPersonPwdInfo, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/safety-setting/person-password", modifyPersonPwdInfo, BODY_DTO(PersonPwdInfoDTO::Wrapper, dto), executeModifyPersonPwdInfo(dto));

private:
	//执行获取密码
	PersonPwdInfoJsonVO::Wrapper executeQueryPersonPwdInfo(const String& id);
	//执行修改密码
	StringJsonVO::Wrapper executeModifyPersonPwdInfo(const PersonPwdInfoDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif
