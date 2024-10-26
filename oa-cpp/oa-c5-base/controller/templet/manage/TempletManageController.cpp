#include "stdafx.h"
#include "TempletManageController.h"
#include "service/formTemplate/modify/ModifyTemplateService.h"

Uint64JsonVO::Wrapper TempletManageController::executeModifyTempletInfo(const TempletChangeDTO::Wrapper& dto) {
	//���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//����У��
	if (!dto->xid || dto->xid <= 0) {
		jvo -> init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->xcreateTime || !dto->xsequence || !dto->xupdateTime || !dto->xdescription || !dto->xalias || !dto->xcategory || !dto->xdata || !dto->xdescription || !dto->xicon || !dto->xmobileData || !dto->xname || !dto->xoutline)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->xcreateTime->empty() || dto->xsequence->empty() || dto->xupdateTime->empty() || dto->xdescription->empty() || dto->xalias->empty() || dto->xcategory->empty() || dto->xdata->empty() || dto->xdescription->empty() || dto->xicon->empty() || dto->xmobileData->empty() || dto->xname->empty() || dto->xoutline->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//����һ��Service
	ModifyTemplateService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else {
		jvo->fail(dto->xid);
	}
	// ��Ӧ���
	return jvo;
}