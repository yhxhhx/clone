#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _ADMINPWDVO_H_
#define _ADMINPWDVO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class AdminPwdVO : public oatpp::DTO
{
	DTO_INIT(AdminPwdVO, DTO);
	// 数据唯一标识
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("password.admin.field.xid"),true,"1ue458s");
	// 姓名
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("password.admin.field.xname"), true, "admin123");
	// 工号
	API_DTO_FIELD(String, xnumber, ZH_WORDS_GETTER("password.admin.field.xnumber"), true, "123");
	// 旧密码
	API_DTO_FIELD(String, xoldpassword, ZH_WORDS_GETTER("password.admin.field.xoldpassword"), true, "123");
	// 新密码
	API_DTO_FIELD(String, xnewpassword, ZH_WORDS_GETTER("password.admin.field.xnewpassword"), true, "456");
	// 确认密码
	API_DTO_FIELD(String, xconfirmpassword, ZH_WORDS_GETTER("password.admin.field.xconfirmpassword"), true, "456");
	//修改密码时间
	API_DTO_FIELD(String, xchangePasswordTime, ZH_WORDS_GETTER("password.admin.field.xchangePasswordTime"), true, "2025/06/09");
	//最近登录时间
	API_DTO_FIELD(String, xpasswordExpiredTime, ZH_WORDS_GETTER("password.admin.field.xpasswordExpiredTime"), true, "2025/06/09");

};



class AdminPwdJsonVO : public JsonVO<AdminPwdVO::Wrapper> {
	DTO_INIT(AdminPwdJsonVO, JsonVO<AdminPwdVO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_ADMINPWDVO_H_