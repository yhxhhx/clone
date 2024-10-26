#pragma once
#ifndef _FORMTEMPLATEBUILTCONTROLLER_H_
#define _FORMTEMPLATEBUILTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/formTemplate/built/formTemplateBuiltVO.h"
#include "domain/dto/formTemplate/built/formTemplateBuiltDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class formTemplateBuiltController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(formTemplateBuiltController);
public://定义接口
	

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addformTemplateBuilt) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("formTemplate.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/form-template/template-built", addformTemplateBuilt, BODY_DTO(formTemplateBuiltDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeAddformTemplateBuilt(dto));
	}

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeformTemplateBuilt) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("formTemplate.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "xid", ZH_WORDS_GETTER("formTemplate.field.xid"), "2dr675d", true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/form-template/template-delete/{xid}", removeformTemplateBuilt, PATH(UInt64, xid), executeremoveformTemplateBuilt(xid));


	
private:
	
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper executeAddformTemplateBuilt(const formTemplateBuiltDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper executeremoveformTemplateBuilt(const UInt64& xid);

};

#include OATPP_CODEGEN_END(ApiController)
#endif// !_FORMTEMPLATEBUILTCONTROLLER_H_