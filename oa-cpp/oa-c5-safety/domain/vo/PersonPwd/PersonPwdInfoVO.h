#pragma once
#ifndef _PERSONPWDINFOVO_H_
#define _PERSONPWDINFOVO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * //个人密码信息显示对象
 */
class PersonPwdInfoVO : public oatpp::DTO {

	DTO_INIT(PersonPwdInfoVO, DTO);
	//传递的数据:数据唯一标识id，工号number，密码password
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("safety.personpassword.field.id"), true, "abc123");
	API_DTO_FIELD(String, number, ZH_WORDS_GETTER("safety.personpassword.field.number"), true, "123456");
	API_DTO_FIELD(String, password, ZH_WORDS_GETTER("safety.personpassword.field.password"), true, "123456");
	API_DTO_FIELD(String, datetime, ZH_WORDS_GETTER("safety.personpassword.field.datetime"), true, "20241020");

};

//个人密码信息显示JsonVO，用于相应给客户端的Json对象
class PersonPwdInfoJsonVO : public JsonVO<PersonPwdInfoVO::Wrapper> {
	DTO_INIT(PersonPwdInfoJsonVO, JsonVO<PersonPwdInfoVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // _PERSONPWDINFOVO_H_