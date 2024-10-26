#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _FORMTEMPLATEBUILT_DO_
#define _FORMTEMPLATEBUILT_DO_
#include "../../DoInclude.h"

/**
 * 示例数据库实体类
 */
class formTemplateBuiltDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, xid, Id);
	CC_SYNTHESIZE(string, xcreateTime, CreateTime);
	CC_SYNTHESIZE(string, xsequence, Sequence);
	CC_SYNTHESIZE(string, xupdateTime, UpdateTime);
	CC_SYNTHESIZE(string, xdistributeFactor, DistributeFactor);
	CC_SYNTHESIZE(string, xalias, Alias);
	CC_SYNTHESIZE(string, xcategory, Category);
	CC_SYNTHESIZE(string, xdata, Data);
	CC_SYNTHESIZE(string, xdescription, Description);
	CC_SYNTHESIZE(string, xicon, Icon);
	CC_SYNTHESIZE(string, xmobileData, MobileData);
	CC_SYNTHESIZE(string, xname, Name);
	CC_SYNTHESIZE(string, xoutline, Outline);

public:
	formTemplateBuiltDO() {
		xid = 0;
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = "";
		xalias = "";
		xcategory = "";
		xdata = "";
		xdescription = "";
		xicon = "";
		xmobileData = "";
		xname = "";
		xoutline = "";
	}
};

#endif // !_FORMTEMPLATEBUILT_DO_