#pragma once

#ifndef _SYSTEMSETTINGCONTROLLER_H_
#define _SYSTEMSETTINGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/system/setting/SystemInfoVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class SystemSettingController : public oatpp::web::server::api::ApiController 
{
	//����������������
	API_ACCESS_DECLARE(SystemSettingController);
public: //����ӿ�
	//��ȡϵͳ������Ϣ�ӿ�
	ENDPOINT_INFO(querySystemInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("system.setting.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SystemInfoJsonVO);
	}
	ENDPOINT(API_M_GET, "/system-setting/system-info", querySystemInfo,API_HANDLER_AUTH_PARAME) {
		String id = authObject->getPayload().getId();
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execuateQuerySystemInfo(id));
	}
private://����ӿ�ִ�к���
	//ִ�л�ȡϵͳ������Ϣ
	SystemInfoJsonVO::Wrapper SystemSettingController::execuateQuerySystemInfo(const String& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SYSTEMSETTINGCONTROLLER_H_
