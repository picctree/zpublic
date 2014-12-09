#include "stdafx.h"
#include "test_cpp11_tuple.h"
#include <tuple>

std::tuple<int, int, int, bool> GetXyz()
{
    return std::make_tuple(1, 2, 3, true);
}

void test_cpp11_tuple()
{
    ///> vs��tupleò�Ƹ�c++��׼���÷����в�ͬ
    auto r = GetXyz();
    
    cout<< std::get<0>(r)
        << std::get<1>(r)
        << std::get<2>(r)
        << std::get<3>(r)
        << endl;
}
