#pragma once
#ifndef _SEND_DTO_
#define _SEND_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SendDTO : public oatpp::DTO
{
	DTO_INIT(SendDTO, DTO);
	// 消息类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("send.field.type");
	}
	// 验证码
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("send.field.code");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_