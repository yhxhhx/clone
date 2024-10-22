#pragma once
#ifndef _LOGINSETTINGDTO_H_
#define _LOGINSETTINGDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LoginSettingDTO : public oatpp::DTO
{
	DTO_INIT(LoginSettingDTO, DTO);
	API_DTO_FIELD(String,image, ZH_WORDS_GETTER("login.base.field.image"), true, "yes/no");
	API_DTO_FIELD(String,text, ZH_WORDS_GETTER("login.base.field.text"), true, "yes/no");
	API_DTO_FIELD(String, dbcase, ZH_WORDS_GETTER("login.base.field.dbcase"), true, "yes/no");
	API_DTO_FIELD(String,QRCode, ZH_WORDS_GETTER("login.base.field.QRCode"), true, "yes/no");
	API_DTO_FIELD(String, atlogin, ZH_WORDS_GETTER("login.base.field.atlogin"), true, "yes/no");
	API_DTO_FIELD(String,doorlogin, ZH_WORDS_GETTER("login.base.field.doorlogin"), true, "yes/no");
	API_DTO_FIELD(String,doorpage, ZH_WORDS_GETTER("login.base.field.doorpage"), true, "yes/no");
	
	API_DTO_FIELD(String,off, ZH_WORDS_GETTER("login.more.field.off"), true, "yes/no");
	API_DTO_FIELD(UInt64,times, ZH_WORDS_GETTER("login.more.field.times"), true, 5);
	API_DTO_FIELD(UInt64,time, ZH_WORDS_GETTER("login.more.field.time"), true, 15);
	API_DTO_FIELD(String,pctime, ZH_WORDS_GETTER("login.more.field.pctime"), false, "");
	API_DTO_FIELD(String,apptime, ZH_WORDS_GETTER("login.more.field.apptime"), false, "");
	API_DTO_FIELD(String,token, ZH_WORDS_GETTER("login.more.field.token"), true, "x-token");
	API_DTO_FIELD(String,code, ZH_WORDS_GETTER("login.more.field.code"), true, "yes/no");
	API_DTO_FIELD(String,HttpOnly, ZH_WORDS_GETTER("login.more.field.HttpOnly"), true, "yes/no");
	API_DTO_FIELD(String,Secure, ZH_WORDS_GETTER("login.more.field.Secure"), true, "yes/no");
	
	API_DTO_FIELD(String,ldap, ZH_WORDS_GETTER("login.more.field.ldap"), true, "yes/no");
	API_DTO_FIELD(String,address, ZH_WORDS_GETTER("login.more.field.address"), false, "");
	API_DTO_FIELD(String,BaseDN, ZH_WORDS_GETTER("login.more.field.BaseDN"), false, "");
	API_DTO_FIELD(String,nature, ZH_WORDS_GETTER("login.more.field.nature"), false, "");
	API_DTO_FIELD(String,user, ZH_WORDS_GETTER("login.more.field.user"), false, "");
	API_DTO_FIELD(String,password, ZH_WORDS_GETTER("login.more.field.password"), false, "");


};

#include OATPP_CODEGEN_END(DTO)

#endif // 