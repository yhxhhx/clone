#pragma once

#ifndef _TEMPLETADDCONTROLLER_H_
#define _TEMPLETADDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/templet/add/TempletAddDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TempletAddController : public oatpp::web::server::api::ApiController 
{
	API_ACCESS_DECLARE(TempletAddController);
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addTemplet) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("templet.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/templet-add/templet-info", addTemplet, BODY_DTO(TempletAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddTemplet(dto));
	}

private:
	Uint64JsonVO::Wrapper execAddTemplet(const TempletAddDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_TEMPLETADDCONTROLLER_H_
