// learn.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "practice/practice_test.h"

#ifdef _TEST_BOOST_
#include "test_smart_ptr.h"
#include "test_regex.h"
#include "test_atomic.h"
#include "test_chrono.h"
#include "test_bitset.h"
#include "test_array.h"
#include "test_stream.h"
#include "test_functional.h"

#include "test_conversion.h"
#include "test_string_aogo.h"
#include "test_format.h"
#include "test_tokenizer.h"

#include "test_bimap.h"
#include "test_circular_buffer.h"
#include "test_dynamic_bitset.h"
#include "test_property_tree.h"
#include "test_variant.h"

#include "test_searching_algorithms.h"
#include "test_clamp.h"
#include "test_hex.h"
#include "test_minmax.h"

#include "test_numeric_conversion.h"
#include "test_optional.h"
#include "test_tribool.h"
#include "test_program_options.h"

#include "test_preprocessor.h"
#endif // _TEST_BOOST_

#ifdef _TEST_MISC_
#include "test_protobuf.h"
#include "test_libcurl.h"
#endif // _TEST_MISC_

#include "test_lua.h"

#ifdef _TEST_UNITTEST_
#include "test_cipra.h"
#include "test_tut.h"
#endif // _TEST_UNITTEST_
#include "test_xde.h"

#ifdef _TEST_HP_SOCKET_
#include "test_hp_socket.h"
#endif // _TEST_HP_SOCKET_

#include "test_rapidxml.h"
#include "test_linq.h"
#include "test_json_rpc.h"
#include "test_json_cpp.h"

#include "test_flatbuffer.h"
#include "test_sqlite.h"

int _tmain(int argc, _TCHAR* argv[])
{
    //practice_test();
    //test_smart_ptr();
    //test_regex();
    //test_atomic();
    //test_chrono();
    //test_bitset();
    //test_array();
    //test_stream();
    //test_functional();

    //test_conversion();
    //test_string_aogo();
    //test_format();
    //test_tokenizer();

    //test_bimap();
    //test_circular_buffer();
    //test_dynamic_bitset();
    //test_property_tree();
    //test_variant();

    //test_searching_algorithms();
    //test_clamp();
    //test_hex();
    //test_minmax();

    //test_numeric_conversion();
    //test_optional();
    //test_tribool();
    //test_program_options();
    //test_preprocessor();

    //test_protobuf();
    //test_libcurl();
    //test_lua();
    //test_cipra();
    //test_tut();
    //test_xde();
    //test_hp_socket();
    //test_rapidxml();
    //test_linq();
    //test_json_cpp();
    //test_json_rpc();

    //test_flatbuffer();
    test_sqlite();

    getchar();
    return 0;
}
