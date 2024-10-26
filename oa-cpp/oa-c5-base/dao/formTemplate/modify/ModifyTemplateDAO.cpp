#include "stdafx.h"
#include "ModifyTemplateDAO.h"
#include "ModifyTemplateMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}


int ModifyTemplateDAO::update(const formTemplateBuiltDO & uObj) {
	string sql = "UPDATE `sys_templateform` SET `xid`=?,`xcreateTime`=?,`xsequence`=?,`xupdateTime`=?,`xdistributeFactor`=?,`xalias`=?,`xcategory`=?,`xdata`=?,`xdescription`=?,`xicon`=?,`xmobileData`=?,`xname`=?,`xoutline`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%ull%s%s%s%s%s%s%s%s%s%s%s%s", uObj.getId(), uObj.getCreateTime(), uObj.getSequence(), uObj.getUpdateTime(), uObj.getDistributeFactor(), uObj.getAlias(), uObj.getCategory(), uObj.getData(), uObj.getDescription(), uObj.getIcon(), uObj.getMobileData(), uObj.getName(), uObj.getOutline());
}