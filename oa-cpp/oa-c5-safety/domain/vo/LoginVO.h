#ifndef _LOGIN_VO_
#define _LOGIN_VO_


#include"../GlobalInclude.h"
#include"../dto/LoginDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)


class LoginConfigJsonVO :public JsonVO<LoginConfigDTO::Wrapper> {
public:
	DTO_INIT(LoginConfigJsonVO, JsonVO<LoginConfigDTO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)

#endif
