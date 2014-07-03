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
#pragma once
#include "win_utils_header.h"

namespace zl
{
namespace WinUtils
{

    class Register
    {
    public:
        Register()
            : hKey_(NULL)
            , bIsAttach_(FALSE)
        {
        }

        ~Register()
        {
            Close();
        }

    public:
        void Attach(HKEY hKey)
        {
            Close();
            hKey_ = hKey;
            bIsAttach_ = TRUE;
        }

        HKEY Detach(void)
        {
            bIsAttach_ = FALSE;
            HKEY hKey = hKey_;
            hKey_ = NULL;
            return hKey;
        }

        BOOL Open(HKEY hRootKey, LPCTSTR szSubKey, BOOL bReadOnly = TRUE, REGSAM samDesired = KEY_READ | KEY_WRITE)
        {
            Close();
            LONG lRetCode = 0;
            if (bReadOnly)
            {
                lRetCode = ::RegOpenKeyEx(hRootKey,
                    szSubKey,
                    0,
                    samDesired,
                    &hKey_);
            }
            else
            {
                lRetCode = ::RegCreateKeyEx(hRootKey,
                    szSubKey,
                    0L,
                    NULL,
                    REG_OPTION_NON_VOLATILE,
                    KEY_ALL_ACCESS, NULL, 
                    &hKey_, NULL);
            }
            if (lRetCode != ERROR_SUCCESS)
            {
                return FALSE;
            }
            return TRUE;
        }

        BOOL CreateVolatileReg(HKEY hRootKey, LPCTSTR szSubKey)
        {
            Close();
            if (::RegCreateKeyEx(hRootKey,
                szSubKey,
                0L,
                NULL,
                REG_OPTION_VOLATILE,
                KEY_ALL_ACCESS,
                NULL,
                &hKey_,
                NULL) != ERROR_SUCCESS)
            {
                return FALSE;
            }
            return TRUE;
        }

        BOOL DeleteKey(LPCTSTR szName)
        {
            if (ERROR_SUCCESS == ::RegDeleteTree(hKey_, szName))
            {
                return TRUE;
            }
            return FALSE;
        }

        BOOL DeleteValue(LPCTSTR szName)
        {
            if (ERROR_SUCCESS == ::RegDeleteValue(hKey_, szName))
            {
                return TRUE;
            }
            return FALSE;
        }

        void Close(void)
        {
            if (!bIsAttach_ && hKey_)
            {
                ::RegCloseKey(hKey_);
                hKey_ = NULL;
            }
            else
            {
                hKey_ = NULL;
            }
        }

        BOOL Read(LPCTSTR pszValueName, DWORD& dwValue)
        {
            if (pszValueName == NULL
                || hKey_ == NULL)
            {
                return FALSE;
            }

            DWORD dwDest = 0;
            DWORD dwType = 0;
            DWORD dwSize = sizeof (DWORD);
            if (::RegQueryValueEx(hKey_,
                pszValueName,
                NULL,
                &dwType,
                (BYTE *)&dwDest,
                &dwSize) == ERROR_SUCCESS)
            {
                if (dwType == REG_DWORD)
                {
                    dwValue = dwDest;
                    return TRUE;
                }
            }
            return FALSE;
        }

        BOOL Read(LPCTSTR pszValueName, CString& strValue)
        {
            if (pszValueName == NULL
                || hKey_ == NULL)
            {
                return FALSE;
            }

            BOOL bReturn = FALSE;
            DWORD dwType;
            DWORD dwSize = 0;
            do
            {
                if (::RegQueryValueEx(hKey_,
                    pszValueName,
                    NULL,
                    &dwType,
                    NULL,
                    &dwSize) != ERROR_SUCCESS)
                {
                    break;
                }
                if (dwType != REG_SZ
                    && dwType != REG_EXPAND_SZ)
                {
                    break;
                }
                strValue.Empty();
                LPTSTR pBuffer = strValue.GetBuffer(dwSize / 2 + 1);
                if (!pBuffer)
                {
                    break;
                }
                if (::RegQueryValueEx(hKey_,
                    pszValueName,
                    NULL,
                    &dwType,
                    (BYTE*)pBuffer,
                    &dwSize) == ERROR_SUCCESS)
                {
                    pBuffer[dwSize / 2] = 0;
                    bReturn = TRUE;
                }
                strValue.ReleaseBuffer();
            } while (FALSE);
            return bReturn;
        }

        BOOL Read(LPCTSTR pszValueName, BYTE* pBuffer, DWORD& dwSize)
        {
            if (pszValueName == NULL
                || hKey_ == NULL)
            {
                return FALSE;
            }

            BOOL bReturn = FALSE;
            LONG lRetCode = 0;
            DWORD dwType = 0;
            if (::RegQueryValueEx(hKey_,
                pszValueName,
                NULL,
                &dwType,
                pBuffer,
                &dwSize) != ERROR_SUCCESS)
            {
                return FALSE;
            }
            return TRUE;
        }

        BOOL Write(LPCTSTR pszValueName, DWORD dwValue)
        {
            if (pszValueName == NULL
                || hKey_ == NULL)
            {
                return FALSE;
            }

            BOOL bReturn = FALSE;
            if (::RegSetValueEx(hKey_,
                pszValueName,
                NULL,
                REG_DWORD,
                (CONST BYTE*)&dwValue,
                sizeof(DWORD)) != ERROR_SUCCESS)
            {
                return FALSE;
            }
            return TRUE;
        }

        BOOL Write(LPCTSTR pszValueName, LPCTSTR pszValue)
        {
            if (pszValueName == NULL
                || hKey_ == NULL
                || pszValue == NULL)
            {
                return FALSE;
            }
            if (::RegSetValueEx(hKey_,
                pszValueName,
                NULL,
                REG_SZ,
                (CONST BYTE*) pszValue,
                ((int)_tcslen(pszValue) + 1) * sizeof(TCHAR)) != ERROR_SUCCESS)
            {
                return FALSE;
            }
            return TRUE;
        }

        BOOL WriteExpandString(LPCTSTR pszValueName, LPCTSTR pszValue)
        {
            if (pszValueName == NULL
                || hKey_ == NULL
                || pszValue == NULL)
            {
                return FALSE;
            }
            if (::RegSetValueEx(hKey_,
                pszValueName,
                NULL,
                REG_EXPAND_SZ,
                (CONST BYTE*) pszValue,
                ((int)_tcslen(pszValue) + 1) * sizeof(TCHAR)) != ERROR_SUCCESS)
            {
                return FALSE;
            }
            return TRUE;
        }

        BOOL Write(LPCTSTR pszValueName, BYTE* pBuffer, DWORD dwSize)
        {
            if (pszValueName == NULL
                || hKey_ == NULL
                || pBuffer == NULL)
            {
                return FALSE;
            }
            if (::RegSetValueEx(hKey_,
                pszValueName,
                NULL,
                REG_BINARY,
                pBuffer,
                dwSize) != ERROR_SUCCESS)
            {
                return FALSE;
            }
            return TRUE;
        }

    private:
        HKEY hKey_;
        BOOL bIsAttach_;
    };

}
}