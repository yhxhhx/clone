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