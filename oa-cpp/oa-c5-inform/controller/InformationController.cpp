#include "InformationController.h"

InformationUnconsumedMessagePageJsonVO::Wrapper InformationController::execQueryUnconsumedMessage(const InformationUnconsumedMessageQuery::Wrapper& query) {
	// ����һ��Service
	InformationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
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
	//��Ӧ
	return  jvo;
}
