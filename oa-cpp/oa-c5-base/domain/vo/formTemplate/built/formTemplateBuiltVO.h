#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _FORMTEMPLATEBUILTVO_H_
#define _FORMTEMPLATEBUILTVO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class formTemplateBuiltVO : public oatpp::DTO
{
	DTO_INIT(formTemplateBuiltVO, DTO);
    API_DTO_FIELD(Int64, xid, ZH_WORDS_GETTER("formTemplate.field.xid"), true, 1);
    API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("formTemplate.field.xcreateTime"), true, "2022-01-01 00:00:00");
    API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("formTemplate.field.xupdateTime"), true, "2022-01-01 00:00:00");
    API_DTO_FIELD(String, xcategory, ZH_WORDS_GETTER("formTemplate.field.xcategory"), true, "5");
    API_DTO_FIELD(String, xicon, ZH_WORDS_GETTER("formTemplate.field.xicon"), true, "7");
    API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("formTemplate.field.xname"), true, "");

};



class formTemplateBuiltJsonVO : public JsonVO<formTemplateBuiltVO::Wrapper> {
	DTO_INIT(formTemplateBuiltJsonVO, JsonVO<formTemplateBuiltVO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_FORMTEMPLATEBUILTVO_H_