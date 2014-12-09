/**
 * @file
 * @brief ��ά�����ɽӿ�
 */
#pragma once

#include <unknwn.h>

///> ��ά��Ĵ��������ȼ�
typedef enum __ZQrcodeLevel
{
    ZQrcodeLevel_Null            = 0,
    ZQrcodeLevel_l               = 1,           ///> ��
    ZQrcodeLevel_m               = 2,
    ZQrcodeLevel_q               = 3,
    ZQrcodeLevel_h               = 4,           ///> ��
}ZQrcodeLevel;

///> ��ά�������
typedef enum __ZQrcodeMode
{
    ZQrcodeMode_Null             = 0,
    ZQrcodeMode_Num              = 1,           ///> Numeric
    ZQrcodeMode_An               = 2,           ///> Alphabet-numeric
    ZQrcodeMode_8                = 3,           ///> 8-bit data
    ZQrcodeMode_Kanji            = 4,           ///> Kanji (shift-jis)
    ZQrcodeMode_Structre         = 5,           ///> Internal use only.
    ZQrcodeMode_ECI              = 6,           ///> ECI
    ZQrcodeMode_Fun1first        = 7,           ///> FNC1, first position.
    ZQrcodeMode_Fun1Second       = 8,           ///> FNC1, second position.
}ZQrcodeMode;

typedef struct __ZQRcodeData
{
    int            width;        ///> ��ά��Ŀ��
    BYTE*          data;         ///> ���� width * width
}ZQRcodeData;

[
    uuid("594f31d0-7f19-11d0-b194-00a0c90dc8bf")
]
interface IZQrCode : public IUnknown
{
    /**
    * @brief ���ɶ�ά��
    * @param[in] qrstr ��Ҫ���ɶ�ά�������
    * @param[in] level ��ά������ɾ���
    * @param[in] mode  ��ά�������ģʽ
    * @return �ɹ�����ZQRcodeData�ṹ�������, ʧ��NULL, ����ʹ��CloseQrcode�ͷ��ڴ�
    */
    virtual ZQRcodeData*     CreateQrcode(const char* qrstr, ZQrcodeLevel level, ZQrcodeMode mode) = 0;
    /**
    * @brief �ͷŶ�ά��ṹ
    * @param[in] qrfree ��Ҫ�ͷŵ�ZQRcodeDataָ��
    */
    virtual void             CloseQrcode(ZQRcodeData* qrfree) = 0;
};
