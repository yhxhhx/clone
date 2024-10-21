#pragma once

#ifndef _TEMPLETCHANGEDTO_H_
#define _TEMPLETCHANGEDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class TempletChangeDTO : public oatpp::DTO 
{
	DTO_INIT(TempletChangeDTO, DTO);
	API_DTO_FIELD(String,design, ZH_WORDS_GETTER("templet.basic.field.design"),false,"");
	API_DTO_FIELD(String,name, ZH_WORDS_GETTER("templet.basic.field.name"),true,"new created");
	API_DTO_FIELD(String,describe, ZH_WORDS_GETTER("templet.basic.field.describe"), false, "");
	API_DTO_FIELD(String,classify, ZH_WORDS_GETTER("templet.basic.field.classify"), false, "");
	API_DTO_FIELD(String,read, ZH_WORDS_GETTER("templet.basic.field.read"),true,"yes/no");
	API_DTO_FIELD(String,type, ZH_WORDS_GETTER("templet.basic.field.type"),true,"blue and clean");
	API_DTO_FIELD(String,ico, ZH_WORDS_GETTER("templet.basic.field.ico"), false, "");
	API_DTO_FIELD(String,print, ZH_WORDS_GETTER("templet.basic.field.print"),true,"none");
	API_DTO_FIELD(String,script, ZH_WORDS_GETTER("templet.basic.field.script"), false, "");
	API_DTO_FIELD(String,style, ZH_WORDS_GETTER("templet.basic.field.style"),true,"{background - color:#f0f0f0");
	API_DTO_FIELD(String,property, ZH_WORDS_GETTER("templet.basic.field.property"),true,"{}");
	API_DTO_FIELD(String,css, ZH_WORDS_GETTER("templet.basic.field.css"),false,"");
	API_DTO_FIELD(String, language, ZH_WORDS_GETTER("templet.basic.field.language"), false, "");
	API_DTO_FIELD_DEFAULT(String, interface, ZH_WORDS_GETTER("templet.commit.field.interface"));
	API_DTO_FIELD(String, write, ZH_WORDS_GETTER("templet.commit.field.write"),true,"yes/no");
	API_DTO_FIELD(String, width, ZH_WORDS_GETTER("templet.commit.field.width"),true,"xx px");
	API_DTO_FIELD(String, length, ZH_WORDS_GETTER("templet.commit.field.length"), true, "xx px");
	API_DTO_FIELD(String, operate, ZH_WORDS_GETTER("templet.commit.field.operate"),false,"");
	API_DTO_FIELD(String, tip, ZH_WORDS_GETTER("templet.commit.field.tip"),true,"yes/no");
	API_DTO_FIELD(String, location, ZH_WORDS_GETTER("templet.commit.field.location"),false," ");
	API_DTO_FIELD(UInt64, time, ZH_WORDS_GETTER("templet.commit.field.time"), true, 5);
	API_DTO_FIELD(String, after, ZH_WORDS_GETTER("templet.commit.field.after"),false,"");
	API_DTO_FIELD(String, suggestion, ZH_WORDS_GETTER("templet.commit.field.suggestion"), false, "");
	API_DTO_FIELD(String, route, ZH_WORDS_GETTER("templet.commit.field.route"), false, "");
	API_DTO_FIELD(String, roam, ZH_WORDS_GETTER("templet.commit.field.roam"), false, "");
	API_DTO_FIELD(String, other, ZH_WORDS_GETTER("templet.commit.field.other"), false, "");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TEMPLETCHANGEDTO_H_
