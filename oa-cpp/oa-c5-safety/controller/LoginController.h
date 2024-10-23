/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 17:07:08

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _LOGIN_CONTROLLER_
#define _LOGIN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"../domain/GlobalInclude.h"

#include"../domain/vo/LoginVO.h"
#include"../domain/dto/LoginDTO.h"
#include"../service/LoginService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class LoginController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(LoginController);
public: // ����ӿ�
	//��������
	ENDPOINT_INFO(login_config) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Login.Basic_configuration.login_config"));
		API_DEF_ADD_RSP_JSON_WRAPPER(LoginConfigJsonVO);
	}
	ENDPOINT(API_M_GET, "/safety/login_config", login_config)
	{
		API_HANDLER_RESP_VO(execLoginConfig());
	}

private: // ����ӿ�ִ�к���
	//
	LoginConfigJsonVO::Wrapper execLoginConfig();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LOGIN_CONTROLLER_