#pragma once

#ifndef _MODIFYTEMPLATE_DAO_
#define _MODIFYTEMPLATE_DAO_
#include "BaseDAO.h"

#include "../../../domain/do/formTemplate/built/formTemplateBuiltDO.h"

class ModifyTemplateDAO : public BaseDAO {
public:
	// ÐÞ¸ÄÊý¾Ý
	int update(const formTemplateBuiltDO& uObj);
};

#endif // !_MODIFYTEMPLATE_DAO_
