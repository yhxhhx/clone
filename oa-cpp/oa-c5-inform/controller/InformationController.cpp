#include "InformationController.h"

InformationUnconsumedMessagePageJsonVO::Wrapper InformationController::execQueryUnconsumedMessage(const InformationUnconsumedMessageQuery::Wrapper& query) {
	// 定义一个Service
	InformationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = InformationUnconsumedMessagePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper InformationController::execMessageStatusModify(const InformationMessageStatusModifyDTO::Wrapper& dto)
{

	auto jvo = Uint64JsonVO::createShared();
	if (dto->id < 0) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	InformationService service;
	if (service.modifyMessageStatus(dto)) {
		jvo->init(UInt64(1), RS_SUCCESS);
	}
	else {
		jvo->init(2, RS_FAIL);
	}
	//响应
	return  jvo;
}
