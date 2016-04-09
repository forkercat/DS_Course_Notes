#pragma once

#include <stdio.h>
//#include <string.h>
#include "linearlist.h"

#ifdef _WIN32

#define TESTMODULE printf("\n%s Start\n", __FUNCTION__)

#else

#define TESTMODULE printf("\n%s Start\n", __func__)

#endif

void TestStatus(bool (* test)(char**));

bool StaticSequencedListTest(char** position);

bool DynamicSequencedListTest(char** position);
