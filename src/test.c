#include "test.h"
#include "linearlist.h"

void TestStatus(bool (* test)(char**)) {
    char* position = NULL;
    if (test(&position))
        printf("\nSuccess!\n");
    else
        printf("\nFailed at %s.\n", position);
}

bool StaticSequencedListTest(char** position) {
    TESTMODULE;

//  getElemAtIndex OK
//  locateElem OK
//  isIn OK
//  getSucc OK
//  getPred OK

    SSList list;

//  clear
    *position = "Clear";
    SSL.clear(&list);
    if (list.length != 0)
        return false;

    *position = "Get element at out-of-range index";
    char c = '6';
    c = SSL.getElemAtIndex(list, 6);
    if (c != '\0')
        return false;

//  insertElemAfterIndex
    *position = "Insert elements";
    SSL.insertElemAfterIndex(&list, 0, 'B');
    SSL.insertElemAfterIndex(&list, 1, 'i');
    SSL.insertElemAfterIndex(&list, 2, 'g');
    SSL.insertElemAfterIndex(&list, 3, 'P');
    SSL.insertElemAfterIndex(&list, 4, 'a');
    if (list.length != 5 || list.data[0] != 'B' || list.data[1] != 'i' ||
        list.data[2] != 'g' || list.data[3] != 'P' || list.data[4] != 'a')
        return false;

    *position = "Insert element at out-of-range index";
    if (SSL.insertElemAfterIndex(&list, 999, 'c'))
        return false;
    if (SSL.insertElemAfterIndex(&list, -2, 'x'))
        return false;

    *position = "If element is on list";
    if (!SSL.isIn(list, 'g'))
        return false;
    if (SSL.isIn(list, 'z'))
        return false;

//  deleteElemAtIndex
    *position = "Delete elements";
    SSL.deleteElemAtIndex(&list, 3);
    if (list.length != 4 || list.data[2] != 'P' || list.data[3] != 'a')
        return false;

    SSL.insertElemAfterIndex(&list, 2, 'g');

    *position = "Get element at index";
    if (SSL.getElemAtIndex(list, 1) != 'B')
        return false;
    if (SSL.getElemAtIndex(list, 99) != '\0')
        return false;

    *position = "Overflow insert";
    SSL.clear(&list);
    int counter = 0;
    for (int i = 0; i < SSLSize * 2; ++i) {
        if (!SSL.insertElemAfterIndex(&list, 0, 'X'))
            break;
        ++counter;
    }
    if (counter != SSLSize)
        return false;

//  getLength
    *position = "Get length";
    if (SSL.getLength(list) != 5)
        return false;

    *position = "Empty check --false";
    if (SSL.isEmpty(list))
        return false;

    *position = "Get successor & predecessor";
    SSList temp = SSL.getSucc(list, 'B');
    if (temp.length != 1 || temp.data[0] != 'i')
        return false;

    temp = SSL.getSucc(list, 'a');
    if (temp.length != 1 || temp.data[0] != '\0')
        return false;

    temp = SSL.getPred(list, 'B');
    if (temp.length != 1 || temp.data[0] != '\0')
        return false;

    temp = SSL.getPred(list, 'g');
    if (temp.length != 1 || temp.data[0] != 'i')
        return false;

    SSL.insertElemAfterIndex(&list, 5, 'P');
    temp = SSL.getSucc(list, 'P');
    if (temp.length != 2 || temp.data[0] != 'a' || temp.data[1] != '\0')
        return false;

    *position = "Locate elements";
    SSLMultiReVal returnValue = SSL.locateElem(list, 'B');
    if (returnValue.length != 1 || returnValue.returnValue[0] != 1)
        return false;

    returnValue = SSL.locateElem(list, 'P');
    if (returnValue.length != 2 || returnValue.returnValue[0] != 4 ||
        returnValue.returnValue[1] != 6)
        return false;

//  isEmpty
    *position = "Empty check --true";
    SSL.clear(&list);
    if (!SSL.isEmpty(list))
        return false;

    return true;
}

bool DynamicSequencedListTest(char** position) {
    TESTMODULE;

    *position = "New list";
    DSList list;
    DSL.new(&list);
    if (list.length != 0 || list.size != DSLInitSize || list.data == NULL)
        return false;

    *position = "Clear list";
    DSL.clear(&list);
    if (list.length != 0)
        return false;

    *position = "Delete list";
    DSL.delete(&list);
    if (list.data!= NULL || list.length != 0 || list.size != 0)
        return false;

    DSL.new(&list);

    *position = "Insert elements";
    DSL.insertElemAfterIndex(&list, 0, 'B');
    DSL.insertElemAfterIndex(&list, 1, 'i');
    DSL.insertElemAfterIndex(&list, 2, 'g');
    DSL.insertElemAfterIndex(&list, 3, 'P');
    DSL.insertElemAfterIndex(&list, 4, 'a');
    if (list.length != 5 || list.data[0] != 'B' || list.data[1] != 'i' ||
        list.data[2] != 'g' || list.data[3] != 'P' || list.data[4] != 'a') {
        free(list.data);
        return false;
    }

    *position = "Insert elements at out-of-range index";
    if (DSL.insertElemAfterIndex(&list, 999, 'c')) {
        free(list.data);
        return false;
    }
    if (DSL.insertElemAfterIndex(&list, -2, 'x')) {
        free(list.data);
        return false;
    }

    *position = "Overflow insert";
    DSL.clear(&list);

    char ascii = 33;
    for (int i = 0; i < DSLInitSize + 1; ++i) {
        if (ascii == 127)
            ascii = 33;
        DSL.insertElemAfterIndex(&list, i, ascii++);
    }

    if (list.length != DSLInitSize + 1 ||
        list.size != DSLInitSize + DSLAddSize) {
        DSL.delete(&list);
        return false;
    }

    bool insertPass = true;
    ascii = 33;
    for (int i = 0; i < DSLInitSize + 1; ++i) {
        if (ascii == 127)
            ascii = 33;
        if (list.data[i] != ascii++) {
            insertPass = false;
            break;
        }
    }
    if (!insertPass) {
        DSL.delete(&list);
        return false;
    }

    *position = "Empty check --false";
    if (DSL.isEmpty(list)) {
        free(list.data);
        return false;
    }

    DSL.clear(&list);

    *position = "Empty check --true";
    if (!DSL.isEmpty(list)) {
        free(list.data);
        return false;
    }

    *position = "Delete list";
    DSL.delete(&list);
    if (list.data)
        return false;

    DSL.new(&list);


    *position = "Delete elements";

    ascii = 33;
    for (int i = 0; i < 26; ++i) {
        DSL.insertElemAfterIndex(&list, i, ascii++);
    }

    if (DSL.deleteElemAtIndex(&list, 666))
        return false;
    DSL.delete(&list);
    return true;
}
