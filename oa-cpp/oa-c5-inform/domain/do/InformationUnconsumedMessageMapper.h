#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _INFORMATION_UNCONSUMED_MESSAGE_MAPPER_
#define _INFORMATION_UNCONSUMED_MESSAGE_MAPPER_

#include "Mapper.h"
#include "../domain/do/InformationDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class InformationUnconsumedMessageMapper : public Mapper<InformationUnconsumedMessageDO>
{
public:
	InformationUnconsumedMessageDO mapper(ResultSet* resultSet) const override
	{
		InformationUnconsumedMessageDO data;
		data.setid(resultSet->getUInt64(1));
		data.setcreateTime(resultSet->getString(2));
		data.setsequence(resultSet->getString(3));
		data.setupdateTime(resultSet->getString(4));
		data.setdistributeFactor(resultSet->getString(5));
		data.setbody(resultSet->getString(6));
		data.setconsumed(resultSet->getUInt(7));
		data.setconsumer(resultSet->getString(8));
		data.setinstant(resultSet->getString(9));
		data.setperson(resultSet->getString(10));
		data.setproperties(resultSet->getString(11));
		data.settitle(resultSet->getString(12));
		data.settype(resultSet->getString(13));
		return data;
	}
};

#endif // !_INFORMATION_UNCONSUMED_MESSAGE_MAPPER_