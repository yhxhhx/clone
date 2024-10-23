#include "InformationDAO.h"



list<InformationUnconsumedMessageDO> InformationDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM msg_message WHERE xconsumed = 0 AND xperson = ? ";
	InformationUnconsumedMessageMapper mapper;
	return sqlSession->executeQuery<InformationUnconsumedMessageDO, InformationUnconsumedMessageMapper>(sql, mapper,"%s",name);
}


int InformationDAO::modifyMessageStatus(const InformationMessageStatusModifyDO& DO)
{
	string sql = "update msg_message set xconsumed=? where xid=? AND xperson =?";
	cout << DO.getconsumed() << ' ' << DO.getid() << ' ' << DO.getperson() << endl;
	return sqlSession->executeUpdate(sql, "%d%d%s", DO.getconsumed(), DO.getid(), DO.getperson());
}
