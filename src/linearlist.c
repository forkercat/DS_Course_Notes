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

// Still in Progress

// Dynamic Sequenced List --DSList

int initDSList(DSList* list) {
    if (!list)
        return -1;
    list->data = (listData*) malloc(DSLInitSize * sizeof(listData));
    if (!list->data)
        return -1;
    list->length = 0;
    list->size = DSLInitSize;
    return 0;
}

int destroyDSList(DSList* list) {
    if (!list)
        return -1;
    free(list->data);
    list->data = NULL;
    list->length = 0;
    list->size = 0;
    return 0;
}

int clearDSList(DSList* list) {
    if (!list)
        return -1;
    list->length = 0;
    return 0;
}

int ifDSListIsEmpty(DSList list) {
    return (int) !list.length;
}

int16_t getLengthOfDSList(DSList list) {
    return list.length;
}

listData getDSListElemAtIndex(DSList list, int16_t index) {
    if (index >= 1 && index <= list.length)
        return list.data[index - 1];
    else
        return -1;
}

DSLMultiReVal locateDSListElemIndex(DSList list, listData elem) {
    DSLMultiReVal returnValue = {0};
    int16_t counter = 0;
    for (int16_t i = 0; i < list.length; ++i) {
        if (list.data[i] == elem) {
            returnValue.returnValue[counter] = (int16_t) (i + 1);
            ++counter;
        }
    }
    return returnValue;
}


int ifElemIsInDSList(DSList list, listData elem) {
    int16_t i = 0;
    int found = 0;
    while (i < list.length && !found) {
        if (list.data[i] != elem)
            ++i;
        else
            found = 1;
    }
    return found;
}

int16_t getDSListNextElemIndex(DSList list, listData elem) {
    int16_t i = 0;
    while (i < list.length && list.data[i] != elem)
        ++i;
    if (i < list.length - 1)
        return (int16_t) (i + 2);
    else
        return -1;
}

int16_t getDSListPrevElemIndex(DSList list, listData elem) {
    int16_t i = 0;
    while (i < list.length && list.data[i] != elem)
        ++i;
    if (i > 0)
        return i;
    else
        return -1;
}

int insertElemOnDSListBeforeIndex(DSList* list, int16_t index, listData elem) {
    if (!list || index < 1 || index > list->length)
        return -1;
    if (list->length == list->size) {
        listData* newdata = (listData*) realloc(list->data,
                                                (list->size + DSLAddSize) *
                                                sizeof(listData));
        if (!newdata)
            return -1;
        list->data = newdata;
        list->size += DSLAddSize;
    }
    for (int16_t i = list->length; i > index; --i)
        list->data[i] = list->data[i - 1];
    list->data[index - 1] = elem;
    return 0;
}

int deleteElemOnDSListAtIndex(DSList* list, int16_t index) {
    if (!list || index < 1 || index > list->length)
        return -1;
    for (int16_t i = (int16_t) (index - 1); i < list->length - 1; ++i)
        list->data[i] = list->data[i + 1];
    --list->length;
    return 0;
}

/*
SLLSpace initSLLSpace() {
    SLLSpace temp;
    temp.availHead = 0;
    for (int16_t i = 0; i < SLLSize - 1; ++i)
        temp.nodes[i].next = (int16_t) (i + 1);
    temp.nodes[SLLSize - 1].next = -1;
    return temp;
}

int initSLListH(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    if (space->availHead != -1) {
        *head = space->availHead;
        space->availHead = space->nodes[space->availHead].next;
    }
    else
        return -1;
    space->nodes[(size_t) head].next = -1;
    return 0;
}

int destroySLListH(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    int16_t cursor = *head;
    while (space->nodes[cursor].next != -1)
        cursor = space->nodes[cursor].next;
    space->nodes[cursor].next = space->availHead;
    space->availHead = *head;
    *head = -1;
    return 0;
}

int clearSLListH(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    int16_t cursor = *head;
    while (space->nodes[cursor].next != -1)
        cursor = space->nodes[cursor].next;
    space->nodes[cursor].next = space->availHead;
    space->availHead = space->nodes[*head].next;
    space->nodes[*head].next = -1;
    return 0;
}

int ifSLListHIsEmpty(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    return (space->nodes[*head].next == -1);
}

int16_t getLengthOfSLListH(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    int16_t cursor = *head, counter = 0;
    while (space->nodes[cursor].next != -1)
        cursor = space->nodes[cursor].next;
}

listData getElementAtIndex(SLLSpace* space, int16_t head, int16_t index) {
    if (!space || head == -1 || index < 1)
        return 0;

}
*/
