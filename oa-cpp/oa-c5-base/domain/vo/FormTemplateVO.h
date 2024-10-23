#pragma once

#ifndef _FORMTEMPLATEVO_H_
#define _FORMTEMPLATEVO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

#include "domain/dto/PageDTO.h"

class FormTemplateJsonVO : public JsonVO<FormTemplateDTO::Wrapper>
{
	DTO_INIT(FormTemplateJsonVO, JsonVO<FormTemplateDTO::Wrapper>);
};

class FormTemplatePageJsonVO :public JsonVO<FormTemplatePageDTO::Wrapper>
{
	DTO_INIT(FormTemplatePageJsonVO, JsonVO<FormTemplatePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _FORMTEMPLATEVO_H_
