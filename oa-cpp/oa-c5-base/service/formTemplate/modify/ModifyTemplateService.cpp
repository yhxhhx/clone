#include "stdafx.h"
#include "ModifyTemplateService.h"
#include "../../../dao/formTemplate/modify/ModifyTemplateDAO.h"

bool ModifyTemplateService::updateData(const TempletChangeDTO::Wrapper& dto) {
	// ��װDO����
	formTemplateBuiltDO data;
	ZO_STAR_DOMAIN_FILED_DTO_TO_DO(data, dto, Id, xid, CreateTime, xcreateTime, Sequence, xsequence, UpdateTime, xupdateTime, DistributeFactor, xdistributeFactor, Alias, xalias, Category, xcategory, Data, xdata, Description, xdescription, Icon, xicon, MobileData, xmobileData, Name, xname, Outline, xoutline)
	// ִ�������޸�
	ModifyTemplateDAO dao;
	return dao.update(data) == 1;
}