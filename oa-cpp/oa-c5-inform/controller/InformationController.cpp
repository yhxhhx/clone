#include "InformationController.h"

InformationUnconsumedMessagePageJsonVO::Wrapper InformationController::execQueryUnconsumedMessage(const InformationUnconsumedMessageQuery::Wrapper& query) {
	// ����һ��Service
	InformationUnconsumedMessageService service;
	// ��ѯ����
	//auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = InformationUnconsumedMessagePageJsonVO::createShared();
	//jvo->success("heh");
	return jvo;
}