#include "linearlist.h"

// Static Sequenced List --SSList

static bool clearSSList(SSList* list) {
    if (!list)
        return false;
    list->length = 0;
    return true;
}

static bool ifSSListIsEmpty(SSList list) {
    if (list.length)
        return false;
    else
        return true;
}

static int getLengthOfSSList(SSList list) {
    return list.length;
}

static listData getSSListElemAtIndex(SSList list, int index) {
    if (index >= 1 && index <= list.length)
        return list.data[index - 1];
    else
        return '\0';
}

static SSLMultiReVal locateSSListElemIndex(SSList list, listData elem) {
    SSLMultiReVal result = {0};
    int16_t counter = 0;
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] == elem) {
            result.returnValue[counter++] = (int16_t) (i + 1);
            result.length++;
        }
    }
    return result;
}

static bool ifElemIsInSSList(SSList list, listData elem) {
    int i = 0;
    bool found = false;
    while (i < list.length && !found) {
        if (list.data[i] != elem)
            ++i;
        else
            found = true;
    }
    return found;
}

static bool insertElemOnSSListAfterIndex(SSList* list, int index,
                                         listData elem) {
    if (!list || index < 0 || index > list->length ||
        list->length == SSLSize)
        return false;
    else {
        for (int i = list->length; i > index; --i)
            list->data[i] = list->data[i - 1];
        list->data[index] = elem;
        ++list->length;
        return true;
    }
}

static bool deleteElemOnSSListAtIndex(SSList* list, int index) {
    if (!list || index < 1 || index > list->length)
        return false;
    else {
        for (int i = index - 1; i < list->length; ++i)
            list->data[i] = list->data[i + 1];
        --list->length;
        return true;
    }
}

static SSList getSSListNextElem(SSList list, listData elem) {
    SSList result;
    int counter = 0;
    SSL.clear(&result);
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] == elem) {
            if (i != list.length - 1)
                SSL.insertElemAfterIndex(&result, counter++, list.data[i + 1]);
            else
                SSL.insertElemAfterIndex(&result, counter++, '\0');
        }
    }
    return result;
}

static SSList getSSListPrevElem(SSList list, listData elem) {
    SSList result;
    int counter = 0;
    SSL.clear(&result);
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] == elem) {
            if (i != 0)
                SSL.insertElemAfterIndex(&result, counter++, list.data[i - 1]);
            else
                SSL.insertElemAfterIndex(&result, counter++, '\0');
        }
    }
    return result;
}

SinglySequencedList const SSL = {
        clearSSList,
        ifSSListIsEmpty,
        getLengthOfSSList,
        getSSListElemAtIndex,
        locateSSListElemIndex,
        ifElemIsInSSList,
        getSSListNextElem,
        getSSListPrevElem,
        insertElemOnSSListAfterIndex,
        deleteElemOnSSListAtIndex
};

// Dynamic Sequenced List --DSList

static bool initDSList(DSList* list) {
    if (!list)
        return false;
    list->data = (listData*) calloc(DSLInitSize, sizeof(listData));
    if (!list->data)
        return false;
    list->length = 0;
    list->size = DSLInitSize;
    return true;
}

static bool destroyDSList(DSList* list) {
    if (!list)
        return false;
    free(list->data);
    list->data = NULL;
    list->length = 0;
    list->size = 0;
    return true;
}

static bool clearDSList(DSList* list) {
    if (!list)
        return false;
    list->length = 0;
    return true;
}

static bool ifDSListIsEmpty(DSList list) {
    if (!list.length)
        return true;
    else
        return false;
}

static int getLengthOfDSList(DSList list) {
    return list.length;
}

static listData getDSListElemAtIndex(DSList list, int index) {
    if (index >= 1 && index <= list.length)
        return list.data[index - 1];
    else
        return '\0';
}

static bool ifElemIsInDSList(DSList list, listData elem) {
    int16_t i = 0;
    bool found = false;
    while (i < list.length && !found) {
        if (list.data[i] != elem)
            ++i;
        else
            found = true;
    }
    return found;
}

static DSLMultiReVal locateDSListElemIndex(DSList list, listData elem) {
    DSLMultiReVal returnValue = {0};
    returnValue.length = 0;
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] == elem) {
            returnValue.returnValue[returnValue.length++] = i + 1;
        }
    }
    return returnValue;
}

static bool insertElemOnDSListAfterIndex(DSList* list, int index,
                                         listData elem) {
    if (!list || index < 0 || index > list->length)
        return false;
    if (list->length == list->size) {
        listData* newData = (listData*) realloc(list->data,
                                                (list->size + DSLAddSize) *
                                                sizeof(listData));
        if (!newData)
            return false;
        list->data = newData;
        list->size += DSLAddSize;
    }
    for (int i = list->length; i > index; --i)
        list->data[i] = list->data[i - 1];
    list->data[index] = elem;
    ++list->length;
    return true;
}

static DSList getDSListPrevElem(DSList list, listData elem) {
    DSList temp;
    if (!DSL.new(&temp)) {
        temp.length = -1;
        return temp;
    }
    int i = 0;
    while (i < list.length && list.data[i] != elem)
        ++i;
    if (i < list.length - 1) {
        insertElemOnDSListAfterIndex(&temp, temp.length++, list.data[i]);
    }
    else {
        insertElemOnDSListAfterIndex(&temp, temp.length++, '\0');
    }
    return temp;
}

static DSList getDSListNextElem(DSList list, listData elem) {
    DSList temp;
    if (!DSL.new(&temp)) {
        temp.length = -1;
        return temp;
    }
    int i = 0;
    while (i < list.length && list.data[i] != elem)
        ++i;
    if (i < list.length - 1) {
        insertElemOnDSListAfterIndex(&temp, temp.length++, list.data[i + 2]);
    }
    else {
        insertElemOnDSListAfterIndex(&temp, temp.length++, '\0');
    }
    return temp;
}

static bool deleteElemOnDSListAtIndex(DSList* list, int index) {
    if (!list || index < 1 || index > list->length)
        return false;
    for (int i = index - 1; i != list->length; ++i)
        list->data[i] = list->data[i + 1];
    --list->length;
    return true;
}

DynamicSequencedList const DSL = {
        initDSList,
        clearDSList,
        destroyDSList,
        ifDSListIsEmpty,
        getLengthOfDSList,
        getDSListElemAtIndex,
        locateDSListElemIndex,
        ifElemIsInDSList,
        getDSListNextElem,
        getDSListPrevElem,
        insertElemOnDSListAfterIndex,
        deleteElemOnDSListAtIndex
};
