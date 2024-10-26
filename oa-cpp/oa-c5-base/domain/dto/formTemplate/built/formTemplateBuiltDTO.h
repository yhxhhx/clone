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
#ifndef _FORMTEMPLATEBUILTDTO_H_
#define _FORMTEMPLATEBUILTDTO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class formTemplateBuiltDTO : public oatpp::DTO
{
	DTO_INIT(formTemplateBuiltDTO, DTO);
    API_DTO_FIELD(Int64, xid, ZH_WORDS_GETTER("formTemplateDetails.field.xid"), true, 19865); // 表单模板ID
    API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("formTemplateDetails.field.xcreateTime"), true, "2022-01-01 00:00:00"); // 创建时间
    API_DTO_FIELD(String, xsequence, ZH_WORDS_GETTER("formTemplateDetails.field.xsequence"), true, "22"); // 序列号
    API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("formTemplateDetails.field.xupdateTime"), true, "2022-01-01 00:00:00"); // 更新时间
    API_DTO_FIELD(String, xdistributeFactor, ZH_WORDS_GETTER("formTemplateDetails.field.xdistributeFactor"), true, "44"); // 分配因子
    API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("formTemplateDetails.field.xalias"), true, "33"); // 别名
    API_DTO_FIELD(String, xcategory, ZH_WORDS_GETTER("formTemplateDetails.field.xcategory"), true, "5"); // 分类
    API_DTO_FIELD(String, xdata, ZH_WORDS_GETTER("formTemplateDetails.field.xdata"), true, "66"); // 数据
    API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("formTemplateDetails.field.xdescription"), true, "77"); // 描述
    API_DTO_FIELD(String, xicon, ZH_WORDS_GETTER("formTemplateDetails.field.xicon"), true, "7"); // 图标
    API_DTO_FIELD(String, xmobileData, ZH_WORDS_GETTER("formTemplateDetails.field.xmobileData"), true, "99"); // 移动数据
    API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("formTemplateDetails.field.xname"), true, "11"); // 名称
    API_DTO_FIELD(String, xoutline, ZH_WORDS_GETTER("formTemplateDetails.field.xoutline"), true, "45"); // 概要
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_FORMTEMPLATEBUILTDTO_H_