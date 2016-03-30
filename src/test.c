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
    SSList list;

    *position = "Init";
    initSSList(&list);
    if (list.length != 0)
        return -1;

    *position = "get elem with out-of-range index";
    char c = getSSListElemAtIndex(list, 6);
    if ((int) c != -1)
        return -1;

    *position = "Insert elements and check length";
    insertElemOnSSListAfterIndex(&list, 0, 'B');
    insertElemOnSSListAfterIndex(&list, 1, 'i');
    if (list.length != 2 || list.data[0] != 'B' || list.data[1] != 'i')
        return -1;

    *position = "Get length";
    if (getLengthOfSSList(list) != 2)
        return -1;

    *position = "Empty check --false";
    if (ifSSListIsEmpty(list))
        return -1;

    *position = "Delete element and check length";
    deleteElemOnSSListAtIndex(&list, 1);
    if (list.length != 1 || list.data[0] != 'i')
        return -1;

    *position = "If element on list";
    if (ifElemIsInSSList(list, 'B') == 1 || ifElemIsInSSList(list, 'i') == 0)
        return -1;

    // In SSList, there is no difference in clear & destroy operation
    *position = "Clear & Destroy list";
    for (int i = 0; i < 1000; ++i)
        insertElemOnSSListAfterIndex(&list, 0, 'X');
    clearSSList(&list);
    if (list.length != 0)
        return -1;

    *position = "Empty check --true";
    if (!ifSSListIsEmpty(list))
        return -1;

    clearSSList(&list);

    *position = "Get prev & next";
    insertElemOnSSListAfterIndex(&list, 0, 'g');
    insertElemOnSSListAfterIndex(&list, 0, 'i');
    insertElemOnSSListAfterIndex(&list, 0, 'B');
    if (getSSListNextElemIndex(list, 'i') != 3 ||
        getSSListPrevElemIndex(list, 'i') != 1)
        return -1;

    clearSSList(&list);

    *position = "Overflow insert";
    int16_t i = 0;
    for (; i < SSLSize * 2; ++i) {
        if (!insertElemOnSSListAfterIndex(&list, 0, '$'))
            break;
    }
    if (i != SSLSize)
        return -1;

    *position = "Locate elements";
    clearSSList(&list);
    insertElemOnSSListAfterIndex(&list, 0, 'X');
    insertElemOnSSListAfterIndex(&list, 0, '\0');
    insertElemOnSSListAfterIndex(&list, 0, 'X');
    insertElemOnSSListAfterIndex(&list, 0, 'X');
    insertElemOnSSListAfterIndex(&list, 0, '\0');
    insertElemOnSSListAfterIndex(&list, 0, 'X');
    insertElemOnSSListAfterIndex(&list, 0, 'X');
    SSLMultiReVal result = locateSSListElemIndex(list, '\0');
    if (result.returnValue[0] != 3 || result.returnValue[1] != 6 ||
        result.returnValue[2] != 0)
        return -1;

    return 0;
}

