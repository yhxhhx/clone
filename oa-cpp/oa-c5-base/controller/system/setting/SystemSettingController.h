#pragma once

#ifndef _SYSTEMSETTINGCONTROLLER_H_
#define _SYSTEMSETTINGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/system/setting/SystemInfoVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class SystemSettingController : public oatpp::web::server::api::ApiController 
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(SystemSettingController);
public: //定义接口
	//获取系统基本信息接口
	ENDPOINT_INFO(querySystemInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("system.setting.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SystemInfoJsonVO);
	}
	ENDPOINT(API_M_GET, "/system-setting/system-info", querySystemInfo,API_HANDLER_AUTH_PARAME) {
		String id = authObject->getPayload().getId();
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execuateQuerySystemInfo(id));
	}
private://定义接口执行函数
	//执行获取系统基本信息
	SystemInfoJsonVO::Wrapper SystemSettingController::execuateQuerySystemInfo(const String& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SYSTEMSETTINGCONTROLLER_H_
