#include "InformationDAO.h"



list<InformationUnconsumedMessageDO> InformationDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM msg_message WHERE xconsumed = 0 AND xperson = ? ";
	InformationUnconsumedMessageMapper mapper;
	return sqlSession->executeQuery<InformationUnconsumedMessageDO, InformationUnconsumedMessageMapper>(sql, mapper,"%s",name);
}
