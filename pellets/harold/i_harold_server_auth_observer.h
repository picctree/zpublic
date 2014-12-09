#pragma once
#include "i_harold_server_observer.h"

///> ��֤�۲���
///> Ĭ�϶�����MG_TRUE
///> OnAuth����>0 ��ֱ�ӷ���MG_TRUE������������AuthObserver
///> OnAuth����<0 ��ֱ�ӷ���MG_FALSE������������AuthObserver
///> OnAuth����=0 �����������AuthObserver
class IHaroldServerAuthObserver : public virtual IHaroldServerObserver
{
public:
    virtual unsigned int ObserverType() { return harold_observer_type_auth; }
    virtual int OnAuth(struct mg_connection *conn) = 0;
};
