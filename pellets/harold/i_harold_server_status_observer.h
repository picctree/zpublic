#pragma once
#include "i_harold_server_observer.h"

enum emHaroldServerStatus
{
    HaroldServerStatusStartBegin        = 1,
};

///> ״̬�۲���
///> ���Լ�ص���������ת�ĸ����ڲ�״̬
class IHaroldServerStatusObserver : public virtual IHaroldServerObserver
{
public:
    virtual unsigned int ObserverType() { return harold_observer_type_status; }
    virtual void OnStatus(emHaroldServerStatus status, void* pData) = 0;
};
