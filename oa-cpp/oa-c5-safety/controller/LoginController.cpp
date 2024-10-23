#include "LoginController.h"

LoginConfigJsonVO::Wrapper LoginController::execLoginConfig()
{
	auto jvo = LoginConfigJsonVO::createShared();
	LoginService service;

	auto result_ = service.All();
	jvo->success(result_);
	return jvo;
}
