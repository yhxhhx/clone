#pragma once

#ifndef  _TEMPLETMANAGECONTROLLER_H_
#define  _TEMPLETMANAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/templet/change/TempletChangeDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TempletManageController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TempletManageController);
public: // 定义接口

	// 修改表单模板接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("templet.put.summary"), modifyTempletInfo, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/templet-manage/templet-info", modifyTempletInfo, BODY_DTO(TempletChangeDTO::Wrapper, dto), executeModifyTempletInfo(dto));


private: // 定义接口执行函数
	// 执行修改表单模板
	StringJsonVO::Wrapper executeModifyTempletInfo(const TempletChangeDTO::Wrapper& dto);
};



#include OATPP_CODEGEN_END(ApiController)

#endif // ! _TEMPLETMANAGECONTROLLER_H_
