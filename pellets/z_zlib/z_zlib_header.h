#pragma once

// �����zlib·�������·����ͻ,�붨�������,����stdafx.h�������zlib·��
#ifndef MY_COSTOM_ZLIB_DIR

#define ZLIB_WINAPI
#include "zlib/zlib.h"

#ifdef _DEBUG
#pragma comment(lib, "zlibstat_d.lib")
#else
#pragma comment(lib, "zlibstat.lib")
#endif

#endif
