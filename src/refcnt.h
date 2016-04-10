// Implementation of Reference Counting

#pragma once

#include <stddef.h>
#include <stdlib.h>

typedef struct {
    unsigned int retainCount;
    void* data;
} MemoryObject;

void* Alloc(size_t size);

void Retain(void* pointer);

void Release(void* pointer);

