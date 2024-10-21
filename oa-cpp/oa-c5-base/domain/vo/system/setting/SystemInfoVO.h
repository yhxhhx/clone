#pragma once

#ifndef _SYSTEMINFO_H_
#define _SYSTEMINFO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//ϵͳ������Ϣ��ʾ����
class SystemInfoVO : public oatpp::DTO 
{
	DTO_INIT(SystemInfoVO, DTO);
	//ϵͳ����
	API_DTO_FIELD(String, sysname, ZH_WORDS_GETTER("system.setting.field.sysname"),true,"01oa");
	//ϵͳ������
	API_DTO_FIELD(String, systitle, ZH_WORDS_GETTER("system.setting.field.systitle"),true,"01");
	//���Ի���
	API_DTO_FIELD(String, language, ZH_WORDS_GETTER("system.setting.field.language"),true,"Chinese");
	//��ǰϵͳ�汾
	API_DTO_FIELD(String, version, ZH_WORDS_GETTER("system.setting.field.version"),true,"1.0");
};

//ϵͳ������Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class SystemInfoJsonVO : public JsonVO<SystemInfoVO::Wrapper>
{
	DTO_INIT(SystemInfoJsonVO, JsonVO<SystemInfoVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _SYSTEMINFO_H_