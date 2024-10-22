/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 17:07:08

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
#ifndef _INFORMATIONCONTROLLER_H_
#define _INFORMATIONCONTROLLER_H_

//#include "domain/BaseJsonVO.h"
#include"../domain/query/InformationQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include"../service/InformationService.h"
#include"../domain/dto/InformationDTO.h"
#include"../domain/vo/InformationVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class InformationController : public oatpp::web::server::api::ApiController
{
    // ����������������
    API_ACCESS_DECLARE(InformationController);
public: // ����ӿ�
    //��ѯδ����ϢENDPOINT
    //��������
	ENDPOINT_INFO(unconsumed_message) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Information.get.unconsumedMessage"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(InformationUnconsumedMessagePageJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("Information.field.name"), "li ming", false);
	}
    //ENDPOINT()
    ENDPOINT(API_M_GET, "/information/unconsumed_message",unconsumed_message, QUERIES(QueryParams, queryParams)) 
    {
        //����ת��
        API_HANDLER_QUERY_PARAM(messageQuery, InformationUnconsumedMessageQuery, queryParams);
        //
        //return createResponse(Status::CODE_200, "OK");
        API_HANDLER_RESP_VO(execQueryUnconsumedMessage(messageQuery));
    }
	//��������
	ENDPOINT_INFO(modify_message_status) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Information.get.modifyMessageStatus"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("Information.field.name"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("Information.field.id"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(Boolean, "consumed", ZH_WORDS_GETTER("Information.field.consumed"), "1", false);
	}
    //�޸���Ϣ״̬ENDPOINT
	ENDPOINT(API_M_POST, "/information/modify_message_status", modify_message_status, BODY_DTO(InformationMessageStatusModifyDTO::Wrapper,dto))
	{
		//
		API_HANDLER_RESP_VO(execMessageStatusModify(dto));
	}


private: // ����ӿ�ִ�к���
    //
	InformationUnconsumedMessagePageJsonVO::Wrapper execQueryUnconsumedMessage(const InformationUnconsumedMessageQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execMessageStatusModify(const InformationMessageStatusModifyDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_INFORMATIONCONTROLLER_H_