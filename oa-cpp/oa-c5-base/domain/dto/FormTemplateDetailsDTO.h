#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FormTemplateDetailsDTO : public oatpp::DTO {

    DTO_INIT(FormTemplateDetailsDTO, DTO);
    API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("formTemplateDetails.field.xid"), true, "1"); // ��ģ��ID
    API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("formTemplateDetails.field.xcreateTime"), true, "2022"); // ����ʱ��
    API_DTO_FIELD(String, xsequence, ZH_WORDS_GETTER("formTemplateDetails.field.xsequence"), true, ""); // ���к�
    API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("formTemplateDetails.field.xupdateTime"), true, "2023"); // ����ʱ��
    API_DTO_FIELD(String, xdistributeFactor, ZH_WORDS_GETTER("formTemplateDetails.field.xdistributeFactor"), true, ""); // ��������
    API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("formTemplateDetails.field.xalias"), true, ""); // ����
    API_DTO_FIELD(String, xcategory, ZH_WORDS_GETTER("formTemplateDetails.field.xcategory"), true, "5"); // ����
    API_DTO_FIELD(String, xdata, ZH_WORDS_GETTER("formTemplateDetails.field.xdata"), true, ""); // ����
    API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("formTemplateDetails.field.xdescription"), true, ""); // ����
    API_DTO_FIELD(String, xicon, ZH_WORDS_GETTER("formTemplateDetails.field.xicon"), true, "7"); // ͼ��
    API_DTO_FIELD(String, xmobileData, ZH_WORDS_GETTER("formTemplateDetails.field.xmobileData"), true, ""); // �ƶ�����
    API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("formTemplateDetails.field.xname"), true, ""); // ����
    API_DTO_FIELD(String, xoutline, ZH_WORDS_GETTER("formTemplateDetails.field.xoutline"), true, ""); // ��Ҫ
};

#include OATPP_CODEGEN_END(DTO)