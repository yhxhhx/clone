#include "stdafx.h"
#include "TempletManageController.h"
#include "service/formTemplate/modify/ModifyTemplateService.h"

Uint64JsonVO::Wrapper TempletManageController::executeModifyTempletInfo(const TempletChangeDTO::Wrapper& dto) {
	//定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//参数校验
	if (!dto->xid || dto->xid <= 0) {
		jvo -> init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->xcreateTime || !dto->xsequence || !dto->xupdateTime || !dto->xdescription || !dto->xalias || !dto->xcategory || !dto->xdata || !dto->xdescription || !dto->xicon || !dto->xmobileData || !dto->xname || !dto->xoutline)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->xcreateTime->empty() || dto->xsequence->empty() || dto->xupdateTime->empty() || dto->xdescription->empty() || dto->xalias->empty() || dto->xcategory->empty() || dto->xdata->empty() || dto->xdescription->empty() || dto->xicon->empty() || dto->xmobileData->empty() || dto->xname->empty() || dto->xoutline->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//定义一个Service
	ModifyTemplateService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else {
		jvo->fail(dto->xid);
	}
	// 响应结果
	return jvo;
}