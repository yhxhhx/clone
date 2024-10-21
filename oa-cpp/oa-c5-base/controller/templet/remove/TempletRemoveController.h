#pragma once
#ifndef  _TEMPLETREMOVECONTROLLER_H_
#define  _TEMPLETREMOVECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/templet/remove/TempletRemoveDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TempletRemoveController : public oatpp::web::server::api::ApiController 
{
	// ����������������
	API_ACCESS_DECLARE(TempletRemoveController);
public:
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeTemplet) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("templet.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "name", ZH_WORDS_GETTER("templet.remove.field.name"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/templet-delete/", removeTemplet, PATH(String, name), execRemoveSample(name));
private:
	// 3.3 ��ʾɾ������
	StringJsonVO::Wrapper execRemoveSample(const String& name);
};

#include OATPP_CODEGEN_END(ApiController)

#endif