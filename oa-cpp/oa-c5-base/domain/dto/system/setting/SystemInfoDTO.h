#pragma once


 /*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/20 16:51:59

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
#ifndef _SYSTEMINFODTO_H_
#define _SYSTEMINFODTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SystemInfoDTO : public oatpp::DTO
{
	DTO_INIT(SystemInfoDTO, DTO);
	//id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sys.setting.field.id"));
	//系统名称
	API_DTO_FIELD_DEFAULT(String,name, ZH_WORDS_GETTER("sys.setting.field.systemname"));
	//系统副标题
	API_DTO_FIELD_DEFAULT(String,subtitle, ZH_WORDS_GETTER("sys.setting.field.systemsubtitle"));
	
	
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SYSTEMINFODTO_H_