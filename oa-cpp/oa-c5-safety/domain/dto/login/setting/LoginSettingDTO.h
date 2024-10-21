#pragma once
#ifndef _LOGINSETTINGDTO_H_
#define _LOGINSETTINGDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LoginSettingDTO : public oatpp::DTO
{
	DTO_INIT(LoginSettingDTO, DTO);
	API_DTO_FIELD(String, usrname, ZH_WORDS_GETTER("login.field.usrname"), true, "");
	API_DTO_FIELD(String, usrpw, ZH_WORDS_GETTER("login.field.usrpw"), true, "");

};

#include OATPP_CODEGEN_END(DTO)

#endif // 