#include "InformationController.h"

InformationUnconsumedMessagePageJsonVO::Wrapper InformationController::execQueryUnconsumedMessage(const InformationUnconsumedMessageQuery::Wrapper& query) {
	// 定义一个Service
	InformationUnconsumedMessageService service;
	// 查询数据
	//auto result = service.listAll(query);
	// 响应结果
	auto jvo = InformationUnconsumedMessagePageJsonVO::createShared();
	//jvo->success("heh");
	return jvo;
}