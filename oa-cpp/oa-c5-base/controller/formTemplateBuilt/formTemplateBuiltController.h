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
public://����ӿ�
	

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addformTemplateBuilt) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("formTemplate.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/form-template/template-built", addformTemplateBuilt, BODY_DTO(formTemplateBuiltDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeAddformTemplateBuilt(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeformTemplateBuilt) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("formTemplate.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "xid", ZH_WORDS_GETTER("formTemplate.field.xid"), "2dr675d", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/form-template/template-delete/{xid}", removeformTemplateBuilt, PATH(UInt64, xid), executeremoveformTemplateBuilt(xid));


	
private:
	
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper executeAddformTemplateBuilt(const formTemplateBuiltDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper executeremoveformTemplateBuilt(const UInt64& xid);

};

#include OATPP_CODEGEN_END(ApiController)
#endif// !_FORMTEMPLATEBUILTCONTROLLER_H_