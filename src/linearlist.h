#pragma once

#include <stdint.h>
#include <stddef.h>
#include <memory.h>

// Static Sequenced List --SSeList

typedef char listData;

#define sListSize 9999

typedef struct sSeList SSeList;

// Multiple return value
typedef struct sListMultiReValue SListMultiReValue;

struct sSeList {
    int16_t length;
    listData data[sListSize];
};

struct sListMultiReValue {
    int16_t returnValue[sListSize];
};

int initSList(SSeList* slist);

int destroySList(SSeList* slist);

int clearSList(SSeList* slist);

int ifSListIsEmpty(SSeList slist);

int16_t getLengthOfSList(SSeList slist);

// Index start from 1 to length
listData getSListElement(SSeList slist, int16_t index);

// return an array (multi return value) of Indexes which start from 1.
SListMultiReValue locateSListElement(SSeList slist, listData element);

int ifElementIsInSList(SSeList slist, listData element);

int16_t getSListNextElementIndex(SSeList slist, listData element);

int16_t getSListPrevElementIndex(SSeList slist, listData element);

int insertSListElemAfterIndex(SSeList* slist, int16_t index, listData element);

int deleteSListElemAtIndex(SSeList* slist, int16_t index);

// Dynamic Sequenced List --DSeList

// Static Linked List with Header --SLListH

#define SLLSize 9999

typedef struct sLLNode SLLNode;

// The space that SLListH relies on
typedef struct sLLSpace SLLSpace;

typedef struct sLListH SLListH;

struct sLLNode {
    int16_t next;
    listData data;
};

struct sLLSpace {
    int16_t availHead;
    SLLNode nodes[SLLSize];
};

SLLSpace initSLLSpace(void);

int initSLListH(SLLSpace* space, int16_t* head);

int destroySLListH(SLLSpace* space, int16_t* head);

int clearSLListH(SLLSpace* space, int16_t* head);

int ifSLListHIsEmpty(SLLSpace* space, int16_t* head);
