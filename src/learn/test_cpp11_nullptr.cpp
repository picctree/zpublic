#include "stdafx.h"
#include "test_cpp11_nullptr.h"

void type_gank(int i)
{
    cout << "int" << endl;
}

void type_gank(int* p)
{
    cout << "int*" << endl;
}

void test_cpp11_nullptr()
{
    ///> ���������int
    type_gank(NULL);

    ///> ������ȷ�������int*
    type_gank(nullptr);
}
