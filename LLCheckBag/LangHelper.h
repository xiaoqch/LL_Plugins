#pragma once
#include <lbpch.h>
#include <stl/langPack.h>

extern LangPack LangP;

void initLang(const std::string& langPack);

#ifndef _TRS
#define _TRS(x) (LangP.trans<do_hash((x))>(x))
#endif

#ifndef _TR
#define _TR(x) (LangP.trans<do_hash((x))>(x).c_str())
#endif