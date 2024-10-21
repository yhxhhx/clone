#pragma once
#ifndef _TEMPLETREMOVEEDTO_H_
#define _TEMPLETREMOVEEDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class TempletRemoveDTO : public oatpp::DTO 
{
	DTO_INIT(TempletRemoveDTO, DTO);
	API_DTO_FIELD(String, confirm, ZH_WORDS_GETTER("templet.remove.field.confirm"), true, "yes/no");
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_TEMPLETREMOVEDTO_H_