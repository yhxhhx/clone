#ifndef _LOGIN_DTO_
#define _LOGIN_DTO_

#include"../GlobalInclude.h"

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

#endif
