#pragma once

#ifndef _TEMPLETCHANGEDTO_H_
#define _TEMPLETCHANGEDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class TempletChangeDTO : public oatpp::DTO 
{
	DTO_INIT(TempletChangeDTO, DTO);
    // ���
    DTO_FIELD(UInt64, xid);
    DTO_FIELD_INFO(xid) {
        info->description = ZH_WORDS_GETTER("formTemplateDetails.field.xid");
    }
    API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("formTemplateDetails.field.xcreateTime"), true, "2022-01-01 00:00:00"); // ����ʱ��
    API_DTO_FIELD(String, xsequence, ZH_WORDS_GETTER("formTemplateDetails.field.xsequence"), true, "22"); // ���к�
    API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("formTemplateDetails.field.xupdateTime"), true, "2022-01-01 00:00:00"); // ����ʱ��
    API_DTO_FIELD(String, xdistributeFactor, ZH_WORDS_GETTER("formTemplateDetails.field.xdistributeFactor"), true, "44"); // ��������
    API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("formTemplateDetails.field.xalias"), true, "33"); // ����
    API_DTO_FIELD(String, xcategory, ZH_WORDS_GETTER("formTemplateDetails.field.xcategory"), true, "5"); // ����
    API_DTO_FIELD(String, xdata, ZH_WORDS_GETTER("formTemplateDetails.field.xdata"), true, "66"); // ����
    API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("formTemplateDetails.field.xdescription"), true, "77"); // ����
    API_DTO_FIELD(String, xicon, ZH_WORDS_GETTER("formTemplateDetails.field.xicon"), true, "7"); // ͼ��
    API_DTO_FIELD(String, xmobileData, ZH_WORDS_GETTER("formTemplateDetails.field.xmobileData"), true, "99"); // �ƶ�����
    API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("formTemplateDetails.field.xname"), true, "11"); // ����
    API_DTO_FIELD(String, xoutline, ZH_WORDS_GETTER("formTemplateDetails.field.xoutline"), true, "45"); // ��Ҫ
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TEMPLETCHANGEDTO_H_
