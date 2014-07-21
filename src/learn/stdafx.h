#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdint.h>

#include <assert.h>

///> Function call with parameters that may be unsafe - this call relies
///> on the caller to check that the passed values are correct. To disable
///> this warning, use -D_SCL_SECURE_NO_WARNINGS. See documentation on how
///> to use Visual C++ 'Checked Iterators'
#pragma warning(disable:4996)

///> ���ļ����������ڵ�ǰ����ҳ(936)�б�ʾ���ַ���
///> �뽫���ļ�����Ϊ Unicode ��ʽ�Է�ֹ���ݶ�ʧ
#pragma warning(disable:4819)

///> ����ʼ����: �ӡ�std::streamsize��ת������size_t�������ܶ�ʧ����
#pragma warning(disable:4244)

#ifdef _TEST_HP_SOCKET_
// /> winsock2�İ�����Ҫ��windows.h֮ǰ
// #include <winsock2.h>
// #include <ws2tcpip.h>
// #include <mswsock.h>
#define _WINSOCK_SUPPORT
#include "hp_socket/GeneralHelper.h"
#endif

///> zpublic��
#include "zpublic.hpp"

///> ��׼����
#include <tuple>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <list>
using std::string;

///> ����������
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::wcout;
using std::cerr;
using std::wcerr;

///> ����ָ��
#include <memory>

///> ������ʽ
#include <regex>

///> ԭ�Ӳ���
#include <atomic>

///> ʱ��
#include <chrono>
#include <ratio>
#include <ctime>

///> λ����
#include <bitset>

///> functional
#include <functional>

#define _TEST_BOOST_
#ifdef _TEST_BOOST_
///> Conversion
///> Polymorphic and lexical casts.
#include <boost/cast.hpp>
#include <boost/lexical_cast.hpp>

///> String Algo
///> String algorithms library.
#include <boost/algorithm/string.hpp>

///> Format
///> The format library provides a class for formatting arguments 
///> according to a format-string, as does printf, but with two major 
///> differences: format sends the arguments to an internal stream, and so
///> is entirely type-safe and naturally supports all user-defined types; 
///> the ellipsis (...) can not be used correctly in the strongly typed 
///> context of format, and thus the function call with arbitrary arguments
///> is replaced by successive calls to an argument feeding operator%.
#include <boost/format.hpp>

///> Tokenizer
///> Break of a string or other character sequence into a series of tokens.
#include <boost/tokenizer.hpp>

///> Bimap
///> Bidirectional maps library for C++. With Boost.Bimap you can create
///> associative containers in which both types can be used as key.
#include <boost/bimap.hpp>

///> Circular Buffer
///> A STL compliant container also known as ring or cyclic buffer.
#include <boost/circular_buffer.hpp>

///> Dynamic Bitset
///> The dynamic_bitset class represents a set of bits. It provides
///> accesses to the value of individual bits via an operator[] and
///> provides all of the bitwise operators that one can apply to builtin
///> integers, such as operator& and operator<<. The number of bits in the
///> set is specified at runtime via a parameter to the constructor of the
///> dynamic_bitset.
#include <boost/dynamic_bitset.hpp>

///> Property Tree
///> A tree data structure especially suited to storing configuration data.
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/info_parser.hpp>

///> Variant
///> Safe, generic, stack-based discriminated union container.
#include <boost/variant.hpp>

///> Algorithm
///> A collection of useful generic algorithms.
#include <boost/algorithm/searching/boyer_moore.hpp>
#include <boost/algorithm/searching/boyer_moore_horspool.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>
#include <boost/algorithm/clamp.hpp>
#include <boost/algorithm/hex.hpp>
#include <boost/algorithm/minmax.hpp>
#include <boost/algorithm/minmax_element.hpp>

///> Numeric Conversion:
///> Optimized Policy-based Numeric Conversions.
#include <boost/numeric/conversion/converter.hpp>
#include <boost/numeric/conversion/bounds.hpp>

///> Optional
///> Discriminated-union wrapper for optional values.
#include <boost/optional.hpp>

///> Tribool
///> 3-state boolean type library.
#include <boost/logic/tribool.hpp>

///> Program Options
///> �{��רTһ need lib �{��ߨT��һ
///> The program_options library allows program developers to obtain
///> program options, that is (name, value) pairs from the user, via
///> conventional methods such as command line and config file.
#include <boost/program_options.hpp>

///> Preprocessor metaprogramming tools including repetition and recursion.
#include <boost/preprocessor.hpp>

#endif // _TEST_BOOST_

#ifdef _TEST_MISC_
///> Protocol Buffers
#ifdef _DEBUG
#pragma comment(lib, "libprotobuf_d.lib")
#else
#pragma comment(lib, "libprotobuf.lib")
#endif

///> libcurl
#ifdef _DEBUG
#pragma comment(lib, "libcurl_d.lib")
#else
#pragma comment(lib, "libcurl.lib")
#endif
#define CURL_STATICLIB
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "winmm.lib")
#include <libcurl/curl.h>

#endif // _TEST_MISC_

///> lua
#include <luasrc/lua.hpp>

///> ltest
#include "ltest/ltest.h"

///> XDE v1.02
///> eXtended length disassembler engine, based on LDE/ADE engines
extern "C"
{
///> warning C4013: ��memset��δ���壻�����ⲿ���� int
///> warning C4018: ��<��: �з���/�޷��Ų�ƥ��
#pragma warning(disable:4013 4018)
#include "xde102/xde.h" 
#pragma warning(default:4013 4018) ///> ����û�ã���xde.c�ľ����赥�������ļ�
}

///> json
#include <json/json.h>