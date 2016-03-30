#include "test.h"

void TestStatus(int (* test)(char**)) {
    char* position = NULL;
    if (!test(&position))
        printf("\nSuccess!\n");
    else
        printf("\nFailed at %s.\n", position);
}

int SSListTest(char** position) {
    TESTMODULE;
    SSList list1;

    *position = "Init";
    initSSList(&list1);
    if (list1.length != 0)
        return -1;

    *position = "get elem with out-of-range index";
    char c = getSSListElemAtIndex(list1, 6);
    if ((int) c != -1)
        return -1;

    *position = "Insert elems and check length";
    insertElemOnSSListBeforeIndex(&list1, 1, 'B');
    if (list1.length != 1 || list1.data[0] != 'B')
        return -1;

    return 0;
}

