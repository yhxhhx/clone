#pragma once

#ifndef _SYSTEMINFORM_DTO_
#define _SYSTEMINFORM_DTO_
#include "domain\GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SystemInformDTO :public oatpp::DTO {
	DTO_INIT(SystemInformDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("system.field.id");
	}
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("system.field.title");
	}
	DTO_FIELD(String, description);
	DTO_FIELD_INFO(description) {
		info->description = ZH_WORDS_GETTER("system.field.description");
	}
	DTO_FIELD(String, addDescription);
	DTO_FIELD_INFO(addDescription) {
		info->description = ZH_WORDS_GETTER("system.field.addDescription");
	}
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("system.field.status");
	}
	DTO_FIELD(String, time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("system.field.time");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SYSTEMINFORM_DTO_