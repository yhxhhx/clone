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