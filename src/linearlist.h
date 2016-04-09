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

    bool (* const isEmpty)(SSList);

    int (* const getLength)(SSList);

    listData (* const getElemAtIndex)(SSList, int);

    SSLMultiReVal (* const locateElem)(SSList, listData);

    bool (* const isIn)(SSList, listData);

    // Get successor
    SSList (* const getSucc)(SSList, listData);

    // Get predecessor
    SSList (* const getPred)(SSList, listData);

    bool (* const insertElemAfterIndex)(SSList*, int, listData);

    bool (* const deleteElemAtIndex)(SSList*, int);
} SinglySequencedList;

extern SinglySequencedList const SSL;

// Dynamic Sequenced List --DSList

#define DSLInitSize 100
#define DSLAddSize 10

typedef struct {
    listData* data;
    int length;
    int size;
} DSList;

typedef struct {
    int length;
    int returnValue[INT_MAX];
} DSLMultiReVal;

typedef struct {
    bool (* const new)(DSList*);

    bool (* const clear)(DSList*);

    bool (* const delete)(DSList*);

    bool (* const isEmpty)(DSList);

    int (* const getLength)(DSList);

    listData (* const getElemAtIndex)(DSList, int);

    DSLMultiReVal (* const locateElem)(DSList, listData);

    bool (* const isIn)(DSList, listData);

    DSList (* const getSucc)(DSList, listData);

    DSList (* const getPred)(DSList, listData);

    bool (* const insertElemAfterIndex)(DSList*, int, listData);

    bool (* const deleteElemAtIndex)(DSList*, int);
} DynamicSequencedList;

extern DynamicSequencedList const DSL;
