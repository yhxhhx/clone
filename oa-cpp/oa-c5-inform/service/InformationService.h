#pragma once
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
#ifndef _INFORMATION_SERVICE_
#define _INFORMATION_SERVICE_
#include <list>
#include "domain/vo/InformationVO.h"
#include "domain/query/InformationQuery.h"
#include "domain/dto/InformationDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class InformationService
{
public:
	// ��ѯ��������
	InformationUnconsumedMessagePageDTO::Wrapper listAll(const InformationUnconsumedMessageQuery::Wrapper& query);
	// �޸�����
	int modifyMessageStatus(const InformationMessageStatusModifyDTO::Wrapper& dto);
};

#endif // !_INFORMATION_SERVICE_

