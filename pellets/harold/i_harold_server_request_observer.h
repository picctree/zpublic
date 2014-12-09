#pragma once
#include "i_harold_server_observer.h"

///> ����۲���
///> Ĭ�϶�����MG_TRUE
///> OnRequest����1 ��ֱ�ӷ���MG_TRUE������������RequestObserver
///> OnRequest����2 ��ֱ�ӷ���MG_FALSE������������RequestObserver
///> OnRequest����3 ��ֱ�ӷ���MG_MORE������������RequestObserver
///> OnRequest����0 �����������RequestObserver(����ֵ)
class IHaroldServerRequestObserver : public virtual IHaroldServerObserver
{
public:
    virtual unsigned int ObserverType() { return harold_observer_type_request; }
    virtual int OnRequest(struct mg_connection *conn) = 0;
};
