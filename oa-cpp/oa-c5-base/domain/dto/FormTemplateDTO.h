#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FormTemplateDTO : public oatpp::DTO {
  
    DTO_INIT(FormTemplateDTO, DTO);
    API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("formTemplate.field.xid"),true,"1");
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("formTemplate.field.xcreateTime"), true,"2022");
    API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("formTemplate.field.xupdateTime"), true, "2023");
    API_DTO_FIELD(String, xcategory, ZH_WORDS_GETTER("formTemplate.field.xcategory"), true, "5");
    API_DTO_FIELD(String, xicon, ZH_WORDS_GETTER("formTemplate.field.xicon"), true, "7");
    API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("formTemplate.field.xname"), true, "");
};

class FormTemplatePageDTO : public PageDTO<FormTemplateDTO::Wrapper>
{
	DTO_INIT(FormTemplatePageDTO, PageDTO<FormTemplateDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)