#pragma once
#ifndef _ADMINPWDCONTROLLER_H_
#define _ADMINPWDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/password/admin/AdminPwdVO.h"
#include "domain/dto/password/admin/AdminPwdDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AdminPwdController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(AdminPwdController);
public://定义接口
	//获取管理员密码设置接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryAdminPwd) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("password.admin.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AdminPwdJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("password.admin.field.xid"), "2dr675d", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/safe-setting/admin-password", queryAdminPwd, QUERY(String, xid), API_HANDLER_AUTH_PARAME) {
		
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryAdminPwd(xid));
	}
	//修改管理员密码设置接口
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("password.admin.put.summary"), modifyAdminPwd, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/safe-setting/admin-password", modifyAdminPwd, BODY_DTO(AdminPwdDTO::Wrapper, dto), executeModifyAdminPwd(dto));

private:
	//执行获取管理员密码
	AdminPwdJsonVO::Wrapper executeQueryAdminPwd(const String& xid);
	//执行修改管理员密码
	StringJsonVO::Wrapper executeModifyAdminPwd(const AdminPwdDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif// !_ADMINPWDCONTROLLER_H_