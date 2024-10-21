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
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addTemplet) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("templet.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/templet-add/templet-info", addTemplet, BODY_DTO(TempletAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddTemplet(dto));
	}

private:
	Uint64JsonVO::Wrapper execAddTemplet(const TempletAddDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_TEMPLETADDCONTROLLER_H_
