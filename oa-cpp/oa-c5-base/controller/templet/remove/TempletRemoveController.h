#pragma once
#ifndef  _TEMPLETREMOVECONTROLLER_H_
#define  _TEMPLETREMOVECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/templet/remove/TempletRemoveDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TempletRemoveController : public oatpp::web::server::api::ApiController 
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TempletRemoveController);
public:
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeTemplet) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("templet.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "name", ZH_WORDS_GETTER("templet.remove.field.name"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/templet-delete/", removeTemplet, PATH(String, name), execRemoveSample(name));
private:
	// 3.3 演示删除数据
	StringJsonVO::Wrapper execRemoveSample(const String& name);
};

#include OATPP_CODEGEN_END(ApiController)

#endif