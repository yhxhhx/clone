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
#ifndef _INFORMATION_DTO_H_
#define _INFORMATION_DTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class InformationUnconsumedMessageDTO : public oatpp::DTO
{
    DTO_INIT(InformationUnconsumedMessageDTO, DTO);
    //一些需要传回去的数据
    //数据描述信息....
    DTO_FIELD(Int64, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("Information.field.id");
    }
	//DTO_FIELD(Int64, name);
	//DTO_FIELD_INFO(name) {
	//	info->description = ZH_WORDS_GETTER("Information.field.name");
	//}
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("Information.field.createTime");
	}
	DTO_FIELD(String, sequence);
	DTO_FIELD_INFO(sequence) {
		info->description = ZH_WORDS_GETTER("Information.field.sequence");
	}
	DTO_FIELD(String,updateTime );
	DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("Information.field.updateTime");
	}
	DTO_FIELD(String, distributeFactor);
	DTO_FIELD_INFO(distributeFactor) {
		info->description = ZH_WORDS_GETTER("Information.field.distributeFactor");
	}
	DTO_FIELD(String, body);
	DTO_FIELD_INFO(body) {
		info->description = ZH_WORDS_GETTER("Information.field.body");
	}
	DTO_FIELD(oatpp::Boolean, consumed);
	DTO_FIELD_INFO(consumed) {
		info->description = ZH_WORDS_GETTER("Information.field.consumed");
	}
	DTO_FIELD(String, consumer);
	DTO_FIELD_INFO(consumer) {
		info->description = ZH_WORDS_GETTER("Information.field.consumer");
	}
	DTO_FIELD(String, instant);
	DTO_FIELD_INFO(instant) {
		info->description = ZH_WORDS_GETTER("Information.field.instant");
	}
	DTO_FIELD(String, person);
	DTO_FIELD_INFO(person) {
		info->description = ZH_WORDS_GETTER("Information.field.person");
	}
	DTO_FIELD(String, properties);
	DTO_FIELD_INFO(properties) {
		info->description = ZH_WORDS_GETTER("Information.field.properties");
	}
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("Information.field.title");
	}
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("Information.field.type");
	}

};

/**
 * 示例分页传输对象
 */
class InformationUnconsumedMessagePageDTO : public PageDTO<InformationUnconsumedMessageDTO::Wrapper>
{
	DTO_INIT(InformationUnconsumedMessagePageDTO, PageDTO<InformationUnconsumedMessageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_INFORMATION_DTO_H_