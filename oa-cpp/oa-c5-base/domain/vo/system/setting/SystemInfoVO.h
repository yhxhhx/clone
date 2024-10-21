#pragma once

#ifndef _SYSTEMINFO_H_
#define _SYSTEMINFO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//系统基本信息显示对象
class SystemInfoVO : public oatpp::DTO 
{
	DTO_INIT(SystemInfoVO, DTO);
	//系统名称
	API_DTO_FIELD(String, sysname, ZH_WORDS_GETTER("system.setting.field.sysname"),true,"01oa");
	//系统副标题
	API_DTO_FIELD(String, systitle, ZH_WORDS_GETTER("system.setting.field.systitle"),true,"01");
	//语言环境
	API_DTO_FIELD(String, language, ZH_WORDS_GETTER("system.setting.field.language"),true,"Chinese");
	//当前系统版本
	API_DTO_FIELD(String, version, ZH_WORDS_GETTER("system.setting.field.version"),true,"1.0");
};

//系统基本信息显示JsonVO，用于响应给客户端的Json对象
class SystemInfoJsonVO : public JsonVO<SystemInfoVO::Wrapper>
{
	DTO_INIT(SystemInfoJsonVO, JsonVO<SystemInfoVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _SYSTEMINFO_H_