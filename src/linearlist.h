#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef char listData;

// Static Sequenced List --SSList

#define SSLSize 9999

typedef struct {
    listData data[SSLSize];
    int length;
} SSList;

// Multiple return value
typedef struct {
    int length;
    int returnValue[SSLSize];
} SSLMultiReVal;

typedef struct {

    bool (* const clear)(SSList*);

    bool (* const empty)(SSList);

    int (* const getLength)(SSList);

    listData (* const getElemAtIndex)(SSList, int);

    SSLMultiReVal (*const locateElem)(SSList, listData);

    bool (* const isIn)(SSList, listData);

    // Get successor
    SSList (* const getSucc)(SSList, listData);

    // Get predecessor
    SSList (* const getPred)(SSList, listData);

    bool (*const insertElemAfterIndex)(SSList*, int, listData);

    bool (*const deleteElemAtIndex)(SSList*, int);

} SinglySequencedList;

extern SinglySequencedList const SSL;

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

