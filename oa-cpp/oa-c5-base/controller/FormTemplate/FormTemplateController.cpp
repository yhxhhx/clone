#include "FormTemplateController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>

FormTemplatePageJsonVO::Wrapper FormTemplateController::executeGetAllTemplates(const FormTemplateQuery::Wrapper& query)
{
    // 创建一个JsonVO对象
    auto vo = FormTemplatePageJsonVO::createShared();
    // 创建一个分页对象
    auto page = FormTemplatePageDTO::createShared();
    page->pageIndex = query->pageIndex;
    page->pageSize = query->pageSize;
    page->total = 20;
    page->calcPages();

    // 模拟计算分页数据
    int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
    int64_t end = start + page->pageSize.getValue(1);
    // 边界值处理
    if (start >= page->total.getValue(0) || start < 0) {
        vo->fail(page);
        return vo;
    }
    if (end > page->total.getValue(0)) end = page->total.getValue(0);
    // 模拟生成测试数据
    vo->success(page);
    return vo;
}