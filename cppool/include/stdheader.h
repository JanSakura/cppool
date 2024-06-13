// JanSakura

#ifndef _CPPOOL_HEADER_H_
#define _CPPOOL_HEADER_H_

// cpp language common std
#ifdef __cplusplus
#include<iostream>

#include<cstdint>
#include<climits>

#include<string>

// STL
#include<vector>
#include<deque>
#include<list>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>

#include<algorithm>
#include<functional>
#include<random>

using ::std::cin;
using ::std::cout;
using ::std::endl;

using ::std::string;
using ::std::vector;
using ::std::deque;
using ::std::list;
using ::std::map;
using ::std::unordered_map;
using ::std::set;
using ::std::unordered_set;

using ::std::function;

// C language common std
#else

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<stdint.h>
#include<limits.h>
#include<stdbool.h>

#include<stddef.h>

#include<time.h>

#endif // __c

#ifdef _WIN32
#include<Windows.h>
#endif // _WIN32

#endif // _CPPOOL_HEADER_H_

