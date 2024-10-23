/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 17:07:08

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
#include "stdafx.h"
#include "InformationService.h"
#include "../dao/InformationDAO.h"

InformationUnconsumedMessagePageDTO::Wrapper InformationService::listAll(const InformationUnconsumedMessageQuery::Wrapper& query)
{
	//// 构建返回对象
	auto messages = InformationUnconsumedMessagePageDTO::createShared();
	
	InformationDAO dao;

	//// 分页查询数据
	//pages->total = count;
	//pages->calcPages();
	list<InformationUnconsumedMessageDO> result = dao.selectByName(query->name);
	cout <<endl<< result.size();
	// 将DO转换成DTO
	for (InformationUnconsumedMessageDO sub : result)
	{
		auto dto = InformationUnconsumedMessageDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, id, 
			                               createTime,createTime,
			                               sequence, sequence,
			                               updateTime, updateTime,
			                               distributeFactor, distributeFactor,
			                               body,body,
			                               consumed,consumed,
			                               consumer,consumer,
			                               instant,instant,
			                               person,person,
			                               properties, properties,
			                               title,title,
			                               type,type);
		cout << sub.getid() << endl;
		cout << sub.getcreateTime() << endl;
		cout << sub.getsequence() << endl;
		cout << sub.getupdateTime() << endl;
		messages->addData(dto);
	}
	return messages;
}

int InformationService::modifyMessageStatus(const InformationMessageStatusModifyDTO::Wrapper& dto)
{
	InformationMessageStatusModifyDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, id, id, consumed, target_status,person,name);
	//cout << dto->id << ' ' << dto->target_status << ' ' << (string)dto->name << endl;
	InformationDAO dao;
	return 	dao.modifyMessageStatus(data)==1;
}
