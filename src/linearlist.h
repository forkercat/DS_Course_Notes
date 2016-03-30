#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef char listData;

// Static Sequenced List --SSList

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

bool initSSList(SSList* list);

/*

SSList variables will be eliminated with whole program

int destroySSList(SSList* list);

 */

bool clearSSList(SSList* list);

int ifSSListIsEmpty(SSList list);

int16_t getLengthOfSSList(SSList list);

// Index start from 1 to length
listData getSSListElemAtIndex(SSList list, int16_t index);

// Return an array (in structure) of Indexes (multiple return value)
// which start from 1; results (indexes) ends with 0.
SSLMultiReVal locateSSListElemIndex(SSList list, listData elem);

bool ifElemIsInSSList(SSList list, listData elem);

// Multiple return value
SSLMultiReVal getSSListNextElemIndex(SSList list, listData elem);

// Multiple return value
SSLMultiReVal getSSListPrevElemIndex(SSList list, listData elem);

bool insertElemOnSSListAfterIndex(SSList* list, int16_t index, listData elem);

bool deleteElemOnSSListAtIndex(SSList* list, int16_t index);


// Dynamic Sequenced List --DSList

#define DSLInitSize 100
#define DSLAddSize 10

typedef struct dSList DSList;

typedef struct dSLMultiReVal DSLMultiReVal;

struct dSList {
    listData* data;
    int16_t length;
    int16_t size;
};

struct dSLMultiReVal {
    int16_t returnValue[INT16_MAX];
};

int initDSList(DSList* list);

int destroyDSList(DSList* list);

int clearDSList(DSList* list);

int ifDSListIsEmpty(DSList list);

int16_t getLengthOfDSList(DSList list);

listData getDSListElemAtIndex(DSList list, int16_t index);

DSLMultiReVal locateDSListElemIndex(DSList list, listData elem);

int ifElemIsInDSList(DSList list, listData elem);

int16_t getDSListNextElemIndex(DSList list, listData elem);

int16_t getDSListPrevElemIndex(DSList list, listData elem);

int insertElemOnDSListBeforeIndex(DSList* list, int16_t index, listData elem);

int deleteElemOnDSListAtIndex(DSList* list, int16_t index);

// Linked List without Head Node --LList

typedef struct lLNode LLNode;

struct lLnode {
    listData data;
    LLNode* next;
};

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

