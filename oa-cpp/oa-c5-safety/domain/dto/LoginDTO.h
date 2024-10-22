#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 21:44:34

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
#ifndef _LOGIN_DTO_H_
#define _LOGIN_DTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LoginConfigDTO : public oatpp::DTO {
	DTO_INIT(LoginConfigDTO, DTO);

	DTO_FIELD(Boolean, enable_image_verification_codes);
	DTO_FIELD(Boolean, enable_SMS_verification_codes);
	DTO_FIELD(Boolean, enable_Two_factor_authentication);
	DTO_FIELD(Boolean, enable_scan_QR_code);
	DTO_FIELD(String, enable_auto_enrollment);
	DTO_FIELD(Boolean, enable_portal_page);
	DTO_FIELD(Boolean, enable_portal_page_as_the_home_of_the_system);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LOGIN_DTO_H_