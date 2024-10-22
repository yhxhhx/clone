#pragma once
#ifndef _ADMINPWDCONTROLLER_H_
#define _ADMINPWDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/password/admin/AdminPwdVO.h"
#include "domain/dto/password/admin/AdminPwdDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AdminPwdController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(AdminPwdController);
public://����ӿ�
	//��ȡ����Ա�������ýӿ�
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAdminPwd) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("password.admin.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AdminPwdJsonVO);
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("password.admin.field.xid"), "2dr675d", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/safe-setting/admin-password", queryAdminPwd, QUERY(String, xid), API_HANDLER_AUTH_PARAME) {
		
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryAdminPwd(xid));
	}
	//�޸Ĺ���Ա�������ýӿ�
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("password.admin.put.summary"), modifyAdminPwd, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/safe-setting/admin-password", modifyAdminPwd, BODY_DTO(AdminPwdDTO::Wrapper, dto), executeModifyAdminPwd(dto));

private:
	//ִ�л�ȡ����Ա����
	AdminPwdJsonVO::Wrapper executeQueryAdminPwd(const String& xid);
	//ִ���޸Ĺ���Ա����
	StringJsonVO::Wrapper executeModifyAdminPwd(const AdminPwdDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif// !_ADMINPWDCONTROLLER_H_