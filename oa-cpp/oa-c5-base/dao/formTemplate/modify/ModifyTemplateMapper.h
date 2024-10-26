#pragma once

#ifndef _MODIFYTEMPLATE_MAPPER_
#define _MODIFYTEMPLATE_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/formTemplate/built/formTemplateBuiltDO.h"

class ModifyTemplateMAPPER : public Mapper<formTemplateBuiltDO> {
public:
	formTemplateBuiltDO mapper(ResultSet* resultSet) const override {
		formTemplateBuiltDO data;
		data.setId(resultSet->getUInt64(1));
		data.setCreateTime(resultSet->getString(2));
		data.setSequence(resultSet->getString(3));
		data.setUpdateTime(resultSet->getString(4));
		data.setDistributeFactor(resultSet->getString(5));
		data.setAlias(resultSet->getString(6));
		data.setCategory(resultSet->getString(7));
		data.setData(resultSet->getString(8));
		data.setDescription(resultSet->getString(9));
		data.setIcon(resultSet->getString(10));
		data.setMobileData(resultSet->getString(11));
		data.setUpdateTime(resultSet->getString(12));
		data.setOutline(resultSet->getString(13));
		return data;
	}
};

#endif // !_MODIFYTEMPLATE_MAPPER_
