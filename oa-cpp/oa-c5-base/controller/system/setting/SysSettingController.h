#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/20 18:03:17

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
#ifndef _SYSTEMSETTINGCONTROLLER_H_
#define _SYSTEMSETTINGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/system/setting/SystemInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class SysSettingController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(SysSettingController);
public: 
	// �޸�ϵͳ���ƺ�ϵͳ������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("system.setting.put.summary"), modifySystemName, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/system-setting/system-info ", modifySystemName, BODY_DTO(SystemInfoDTO::Wrapper, dto), executeModifySystemInfo(dto));

	
private: // ����ӿ�ִ�к���
	//ִ���޸�ϵͳ����
	StringJsonVO::Wrapper executeModifySystemInfo(const SystemInfoDTO::Wrapper& dto);
};



#include OATPP_CODEGEN_END(ApiController)

#endif // !_SYSTEMSETTINGCONTROLLER_H_