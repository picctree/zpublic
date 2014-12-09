#pragma once
#include "i_harold_server_observer.h"

///> http�������
class IHaroldServer
{
public:
    virtual bool StartServer()              = 0;
    virtual bool StopServer()               = 0;

    ///> ���typeΪ0��������ӵ��κ�����
    virtual bool InsertObserver(
        IHaroldServerObserver* pObserver,
        unsigned int type)                  = 0;

    ///> ���typeΪ0������ÿ�����Ͷ�ɾ��
    virtual bool RomoveObserver(
        IHaroldServerObserver* pObserver,
        unsigned int type = 0)              = 0;
};
