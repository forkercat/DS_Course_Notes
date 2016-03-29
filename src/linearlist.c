#include "linearlist.h"

int initSList(SSeList* slist) {
    if (!slist)
        return -1;
    slist->length = 0;
    return 0;
}

int destroySList(SSeList* slist) {
    if (!slist)
        return -1;
    slist->length = 0;
    return 0;
}

int clearSList(SSeList* slist) {
    if (!slist)
        return -1;
    slist->length = 0;
    return 0;
}

int ifSListIsEmpty(SSeList slist) {
    return !slist.length;
}

int16_t getLengthOfSList(SSeList slist) {
    return slist.length;
}


listData getSListElement(SSeList slist, int16_t index) {
    if (index >= 1 && index <= slist.length)
        return slist.data[index - 1];
    else
        return -1;
}

SListMultiReValue locateSListElement(SSeList slist, listData element) {
    SListMultiReValue retVal;
    int16_t temp[sListSize] = {0};
    memcpy(retVal.returnValue, temp, sizeof(retVal.returnValue));
    int16_t counter = 0;
    for (int i = 0; i < sListSize; ++i) {
        if (slist.data[i] == element) {
            retVal.returnValue[counter] = (int16_t) (i + 1);
            ++counter;
        }
    }
    return retVal;
}

int ifElementIsInSList(SSeList slist, listData element) {
    int16_t i = 0;
    int found = 0;
    while (i < slist.length && !found) {
        if (slist.data[i] != element)
            ++i;
        else
            found = 1;
    }
    return found;
}

int16_t getSListNextElementIndex(SSeList slist, listData element) {
    int16_t i = 0;
    while (i < slist.length && slist.data[i] != element)
        ++i;
    if (i < slist.length - 1)
        return (int16_t) (i + 1);
    else
        return -1;
}

int16_t getSListPrevElementIndex(SSeList slist, listData element) {
    int16_t i = 0;
    while (i < slist.length && slist.data[i] != element)
        ++i;
    if (i > 0 && i < slist.length)
        return (int16_t) (i - 1);
    else
        return -1;
}

int insertSListElemAfterIndex(SSeList* slist, int16_t index, listData element) {
    if (!slist || index < 1 || index > slist->length + 1 ||
        slist->length == sListSize)
        return 0;
    else {
        for (int16_t i = slist->length; i > index; --i)
            slist->data[i] = slist->data[i - 1];
        slist->data[index + 1] = element;
        ++slist->length;
        return -1;
    }
}

int deleteSListElemAtIndex(SSeList* slist, int16_t index) {
    if (!slist || index < 1 || index > slist->length + 1)
        return 0;
    else {
        for (int16_t i = (int16_t) (index - 1); i < slist->length; ++i)
            slist->data[i] = slist->data[i + 1];
        --slist->length;
        return -1;
    }
}

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