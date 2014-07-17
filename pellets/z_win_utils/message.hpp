/*************************************************************************
 *                                                                       *
 *  I|*j^3Cl|a   "+!*%                  qt          Nd   gW              *
 *  l]{y+l?MM*  !#Wla\NNP               NW          MM   I|              *
 *        PW    ?E|    tWg              Wg  sC!     AW           ~@v~    *
 *       NC     ?M!    yN|  WW     MK   MW@K1Y%M@   RM   #Q    QP@tim    *
 *     CM|      |WQCljAE|   MD     Mg   RN     cM~  NM   WQ   MQ         *
 *    #M        aQ?         MW     M3   Mg      Q(  HQ   YR  IM|         *
 *   Dq         {Ql         MH    iMX   Mg     MM   QP   QM   Eg         *
 * !EWNaPRag2$  +M"          $WNaHaN%   MQE$%EXW    QQ   CM    %M%a$D    *
 *                                                                       *
 *               Website: https://github.com/zpublic/zpublic             *
 *                                                                       *
 ************************************************************************/

/**
 * @file
 * @brief ������Ϣ���
 */


#pragma once
#include "win_utils_header.h"

namespace zl
{
namespace WinUtils
{
    /**
     * @brief UIPI��Ϣ��������ز���
     */
    class ZLMessage
    {
        inline UINT RegisterMessage(LPCTSTR lpMsgName)
        {
            return ::RegisterWindowMessage(lpMsgName);
        }

        typedef BOOL (__stdcall *ChangeWindowMessageFilterType)(UINT, DWORD);
    #define MSGFLT_ADD		1	// ChangeWindowMessageFilter �����ĵڶ��������������Ϣ
    #define MSGFLT_REMOVE	2	// ChangeWindowMessageFilter �����ĵڶ����������Ƴ���Ϣ

        /**
         * @brief ��UIPI��Ϣ����������ӻ�ɾ��һ����Ϣ
         * @param[in] uMsg   ָ�����������ӻ�ӹ�����ɾ����ָ����Ϣ
         * @param[in] dwOper ָ����������
         * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
         * @see ChangeWindowMessageFilter
         */
        static BOOL ChangeMessageFilter(UINT uMsg, DWORD dwOper = MSGFLT_ADD)
        {
            BOOL bRet = FALSE;
            static HMODULE hModule = NULL;
            static ChangeWindowMessageFilterType pChangeWindowMessageFilterType = NULL;
            if (pChangeWindowMessageFilterType == NULL)
            {
                hModule = ::LoadLibrary(TEXT("user32.dll"));
                if (hModule == NULL)
                    goto Exit0;
                pChangeWindowMessageFilterType = (ChangeWindowMessageFilterType)::GetProcAddress(hModule, "ChangeWindowMessageFilter");
                if (pChangeWindowMessageFilterType == NULL)
                    goto Exit0;
            }
            bRet = pChangeWindowMessageFilterType(uMsg, dwOper);
    Exit0:
            return bRet;
        }
    };


}
}
