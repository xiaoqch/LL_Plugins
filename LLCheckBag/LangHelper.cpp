#include "pch.h"
#include "LangHelper.h"

LangPack LangP;

void initLang(const std::string& langPack)
{
	LangP.load(langPack);
}
