#pragma once
#ifndef _PERSONPWDINFODTO_H_
#define _PERSONPWDINFODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class PersonPwdInfoDTO : public oatpp::DTO
{
	DTO_INIT(PersonPwdInfoDTO, DTO);

	//数据记录id和工号number也需要上传。
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("safety.personpassword.field.id"),true,"abc123");
	API_DTO_FIELD(String, number, ZH_WORDS_GETTER("safety.personpassword.field.number"),true,"000001");

	//可以修改上传的部分,主要包括旧密码，新密码，第二次输入新密码
	API_DTO_FIELD(String, oldpassword, ZH_WORDS_GETTER("safety.personpassword.field.oldpassword"), true, "12345");
	API_DTO_FIELD(String, password, ZH_WORDS_GETTER("safety.personpassword.field.password"), true, "123456");
	API_DTO_FIELD(String, password2, ZH_WORDS_GETTER("safety.personpassword.field.password2"), true, "123456");


};


#include OATPP_CODEGEN_END(DTO)
#endif // _PERSONPWDINFODTO_H_