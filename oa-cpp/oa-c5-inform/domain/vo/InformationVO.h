#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 21:44:34

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
#ifndef _INFORMATION_VO_
#define _INFORMATION_VO_

#include "../GlobalInclude.h"
#include "../dto/InformationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 未读消息显示JsonVO，用于响应给客户端的Json对象
 */
class InformationUnconsumedMessageJsonVO : public JsonVO<InformationUnconsumedMessageDTO::Wrapper> {
	DTO_INIT(InformationUnconsumedMessageJsonVO, JsonVO<InformationUnconsumedMessageDTO::Wrapper>);
};

/**
 * 未读消息分页显示JsonVO，用于响应给客户端的Json对象
 */
class InformationUnconsumedMessagePageJsonVO : public JsonVO<InformationUnconsumedMessagePageDTO::Wrapper> {
	DTO_INIT(InformationUnconsumedMessagePageJsonVO, JsonVO<InformationUnconsumedMessagePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_INFORMATION_VO_