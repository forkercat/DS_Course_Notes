#pragma once

#include <stdint.h>
#include <stddef.h>
#include <memory.h>
#include <stdlib.h>

// Static Sequenced List --SSList

typedef char listData;

#define SSLSize 9999

typedef struct sSList SSList;

// Multiple return value
typedef struct sSLMultiReVal SSLMultiReVal;

struct sSList {
    int16_t length;
    listData data[SSLSize];
};

struct sSLMultiReVal {
    int16_t returnValue[SSLSize];
};

int initSSList(SSList* list);

int destroySSList(SSList* list);

int clearSSList(SSList* list);

int ifSSListIsEmpty(SSList list);

int16_t getLengthOfSSList(SSList list);

// Index start from 1 to length
listData getSSListElemAtIndex(SSList list, int16_t index);

// return an array (multi return value) of Indexes which start from 1.
SSLMultiReVal locateSSListElem(SSList list, listData elem);

int ifElemIsInSSList(SSList list, listData elem);

int16_t getSSListNextElemIndex(SSList list, listData elem);

int16_t getSSListPrevElemIndex(SSList list, listData elem);

int insertSSListElemAfterIndex(SSList* list, int16_t index, listData elem);

int deleteSSListElemAtIndex(SSList* list, int16_t index);

// Dynamic Sequenced List --DSList

#define DSLInitSize 100
#define DSLAddSize 10

typedef struct dSList DSList;

struct dSList {
    listData* data;
    int16_t length;
    int16_t size;
};

int initDSList(DSList* list);

int destroyDSList(DSList* list);

int clearDSList(DSList* list);

int ifDSListIsEmpty(DSList list);

int16_t getLengthOfDSList(DSList list);

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
