#pragma once

#include <stdio.h>
#include <string.h>
#include "linearlist.h"

#ifdef _WIN32

#define TESTMODULE printf("\n%s Start\n", __FUNCTION__)

#else

#define TESTMODULE printf("\n%s Start\n", __func__)

#endif

void TestStatus(int (  * test)(char**));

int SSListTest(char** position);

