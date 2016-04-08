#include "test.h"
#include "linearlist.h"

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

    *position = "Clear";
    SSL.clear(&list);
    if (list.length != 0)
        return -1;

    *position = "Get element at out-of-range index";
    char c = '6';
    c = SSL.getElemAtIndex(list, 6);
    if (c != '\0')
        return -1;

    *position = "Insert elements";
    SSL.insertElemAfterIndex(&list, 0, 'B');
    SSL.insertElemAfterIndex(&list, 1, 'i');
    SSL.insertElemAfterIndex(&list, 2, 'g');
    SSL.insertElemAfterIndex(&list, 3, 'P');
    SSL.insertElemAfterIndex(&list, 4, 'a');
    if (list.length != 5 || list.data[0] != 'B' || list.data[1] != 'i' ||
        list.data[2] != 'g' || list.data[3] != 'P' || list.data[4] != 'a')
        return -1;

    if (SSL.insertElemAfterIndex(&list, 999, 'c'))
        return -1;
    if (SSL.insertElemAfterIndex(&list, -2, 'x'))
        return -1;

    *position = "Empty check --false";
    if (SSL.empty(list))
        return -1;

    *position = "Get successor & predecessor";
    SSList temp = SSL.getSucc(list, 'B');
    if (temp.length != 1 || temp.data[0] != 'i')
        return -1;

    temp = SSL.getSucc(list, 'a');
    if (temp.length != 1 || temp.data[0] != '\0')
        return -1;

    temp = SSL.getPred(list, 'B');
    if (temp.length != 1 || temp.data[0] != '\0')
        return -1;

    temp = SSL.getPred(list, 'g');
    if (temp.length != 1 || temp.data[0] != 'i')
        return -1;

    SSL.insertElemAfterIndex(&list, 5, 'P');
    temp = SSL.getSucc(list, 'P');
    if (temp.length != 2 || temp.data[0] != 'a' || temp.data[1] != '\0')
        return -1;

    *position = "Locate elements";
    SSLMultiReVal returnValue = SSL.locateElem(list, 'B');
    if (returnValue.length != 1 || returnValue.returnValue[0] != 1)
        return -1;

    returnValue = SSL.locateElem(list, 'P');
    if (returnValue.length != 2 || returnValue.returnValue[0] != 4 ||
        returnValue.returnValue[1] != 6)
        return -1;

    *position = "Empty check --true";
    SSL.clear(&list);
    if (!SSL.empty(list))
        return -1;

    *position = "Overflow insert";
    int counter = 0;
    for (int i = 0; i < SSLSize * 2; ++i) {
        if (!SSL.insertElemAfterIndex(&list, 0, 'X'))
            break;
        ++counter;
    }
    if (counter != SSLSize)
        return -1;

    return 0;
}

int DSListTest(char** position) {
    TESTMODULE;
    *position = "Init";
    DSList list;
    initDSList(&list);
    if (!list.data || list.length != 0 || list.size != DSLInitSize)
        return -1;


    return 0;
}
