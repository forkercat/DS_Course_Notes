#include "refcnt.h"

void* Alloc(size_t size) {
    // Memory allocation
    MemoryObject* memoryObject = (MemoryObject*) calloc(
            sizeof(MemoryObject) + size, 1);
    char* pointer = (char*) memoryObject;

    // Get the first memory address that the user expects to get.
    pointer += sizeof(MemoryObject);

    memoryObject->retainCount = 1;
    memoryObject->data = pointer;
    return (void*) pointer;
}

void Retain(void* pointer) {
    MemoryObject* memoryObject;
    char* charPointer;
    charPointer = (char*) pointer;
    // Get the first memory address that user allocated.
    charPointer -= sizeof(MemoryObject);
    memoryObject = (MemoryObject*) charPointer;
    memoryObject->retainCount++;
}

void Release(void* pointer) {
    MemoryObject* memoryObject;
    char* charPointer;
    charPointer = (char*) pointer;
    // Get the first memory address that user allocated.
    charPointer -= sizeof(MemoryObject);
    memoryObject = (MemoryObject*) charPointer;
    memoryObject->retainCount--;
    if (memoryObject->retainCount == 0) {
        free(memoryObject);
    }
}