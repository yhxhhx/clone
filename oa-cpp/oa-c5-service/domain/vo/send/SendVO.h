#pragma once
#ifndef _SEND_VO_
#define _SEND_VO_

#include "../../GlobalInclude.h"
#include "../../dto/send/SendDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class SendJsonVO : public JsonVO<SendDTO::Wrapper> {
	DTO_INIT(SendJsonVO, JsonVO<SendDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_