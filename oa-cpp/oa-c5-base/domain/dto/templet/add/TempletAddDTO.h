#pragma once

#ifndef _TEMPLETADDEDTO_H_
#define _TEMPLETADDEDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class TempletAddDTO : public oatpp::DTO 
{
	DTO_INIT(TempletAddDTO, DTO);
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("templet.add.field.name"), true, "new templet");
	API_DTO_FIELD(String, classify, ZH_WORDS_GETTER("templet.add.field.classify"), true, "new class");
	API_DTO_FIELD(String, describe, ZH_WORDS_GETTER("templet.add.field.describe"), false, "");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TEMPLETADDDTO_H_