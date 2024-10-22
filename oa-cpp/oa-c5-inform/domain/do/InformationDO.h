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
#ifndef _INFORMATION_DO_
#define _INFORMATION_DO_
#include "./DoInclude.h"


class InformationUnconsumedMessageDO
{
	// ±àºÅ
	CC_SYNTHESIZE(uint64_t, id_, id);
	//
	CC_SYNTHESIZE(string, create_time_, createTime);
	//
	CC_SYNTHESIZE(string, sequence_, sequence);
	//
	CC_SYNTHESIZE(string, update_time_, updateTime);
	//
	CC_SYNTHESIZE(string, distribute_factor_, distributeFactor);
	//
	CC_SYNTHESIZE(string, body_, body);
	//
	CC_SYNTHESIZE(bool, consumed_, consumed);
	//
	CC_SYNTHESIZE(string, consumer_, consumer);
	//
	CC_SYNTHESIZE(string, instant_, instant);
	//
	CC_SYNTHESIZE(string, person_, person);
	//
	CC_SYNTHESIZE(string, properties_, properties);
	//
	CC_SYNTHESIZE(string, title_, title);
	//
	CC_SYNTHESIZE(string, type_, type);

public:
	InformationUnconsumedMessageDO() {
		id_ = 0;
		create_time_ = "";
		sequence_ = "";
		update_time_ = "";
		distribute_factor_ = "";
		body_ = "";
		consumed_ = "";
		consumer_ = "";
		instant_ = "";
		person_ = "";
		properties_ = "";
		title_ = "";
		type_ = "";
	}
};

class InformationMessageStatusModifyDO {
	CC_SYNTHESIZE(string, person_, person);
	// ±àºÅ
	CC_SYNTHESIZE(uint64_t, id_, id);
	// ±àºÅ
	CC_SYNTHESIZE(bool, consumed_, consumed);

public:
	InformationMessageStatusModifyDO(){
		id_ = 0;
		consumed_ = "";
		person_ = "";
	}
};

#endif // !_INFORMATION_DO_
