// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include "z_qrcode.h"
#include "pellets/z_com/z_com.h"

ZL_BEGIN_OBJECT_MAP()
    ZL_OBJECT_ENTRY(IZQrCode, ZQrCode)
ZL_END_OBJECT_MAP()

ZL_USE_DEFAULT_COM_PROCEX
