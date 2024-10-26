#pragma once
#ifndef _MODIFYTEMPLATE_SERVICE_
#define _MODIFYTEMPLATE_SERVICE_
#include<list>
#include "../../../domain/dto/templet/change/TempletChangeDTO.h"
#include "../../../domain/do/formTemplate/built/formTemplateBuiltDO.h"

class ModifyTemplateService {
public:
	// ÐÞ¸ÄÊý¾Ý
	bool updateData(const TempletChangeDTO::Wrapper& dto);
};

#endif // !_MODIFYTEMPLATE_SERVICE_
