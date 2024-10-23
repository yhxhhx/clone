#pragma once

#ifndef _FORMTEMPLATECONTROLLER_H_
#define _FORMTEMPLATECONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/dto/FormTemplateDTO.h"
#include "domain/query/FormTemplateQuery.h"
#include "domain/vo/FormTemplateVO.h"
#include "domain/dto/PageDTO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

class FormTemplateController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(FormTemplateController);

public:
    // 添加宏定义来简化getAllTemplates的ENDPOINT_INFO
    ENDPOINT_INFO(getAllTemplates) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("formTemplate.get-all.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(FormTemplatePageJsonVO);
        API_DEF_ADD_PAGE_PARAMS();
    }

    // 使用宏定义来简化getAllTemplates的ENDPOINT
    ENDPOINT(API_M_GET, "/form/query-all 获取表单模版（分页）", getAllTemplates, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, FormTemplateQuery, queryParams);
        API_HANDLER_RESP_VO(executeGetAllTemplates(query));
    }

private:
    FormTemplatePageJsonVO::Wrapper executeGetAllTemplates(const FormTemplateQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _FORMTEMPLATECONTROLLER_H_