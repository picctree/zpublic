#include "stdafx.h"
#include "test_cpp11_auto.h"


void test_cpp11_auto()
{
    ///> ��ƿװ�¾ƣ�auto�ؼ��ֱ����¶���
    auto i = 3;
    cout<<i<<endl;

    std::vector<std::pair<int, float>> vec1 = {{1,1.1}, {2,2.2}};
    
    for (auto i : vec1)
    {
        cout << i.first << i.second << endl;
    }
}

