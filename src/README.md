# Implementation
[![Build Status](https://travis-ci.org/BigPa/DS_Course_Notes.svg?branch=master)](https://travis-ci.org/BigPa/DS_Course_Notes)
[![Build status](https://ci.appveyor.com/api/projects/status/f3c7txen2jte9k18?svg=true)](https://ci.appveyor.com/project/BigPa/ds-course-notes)

Implementation in ANSI C

## Progress

- [x] Static Sequenced List
- [ ] Dynamic Sequenced List
- [ ] Singly Linked List without Head Node
- [ ] Singly Linked List
- [ ] Static Linked List
- [ ] Doubly Circular Linked List
- [ ] Static Stack
- [ ] Linked Stack
- [ ] Linked Queue
- [ ] Circular Queue

## Table of contents

1. Linear List

## Functions

### Linear List

#### `new`

- To (create and) initialize a linear list object
- Parameter(s): **Pointer** to the object
- Return value: **Boolean** of "Object creation complete"
- Availibility:
  - Dynamic Sequenced List

#### `clear`
- To clear the content of linear list
- Parameter(s): **Pointer** to the object
- Return value: **Boolean** of "Content clear complete"
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `delete`
- To destroy (eliminate) a linear list object
- Parameter(s): **Pointer** to the object
- Return value: **Boolean** of "Elemination complete"
- Availibility:
  - Dynamic Sequenced List

#### `isEmpty`
- To check if a linear list is empty
- Parameter(s): Linear list object
- Return value: **Boolean** of "The list is Empty"
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `getLength`
- To get a linear list's length
- Parameter(s): Linear list object
- Return value: The length of the list
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `getElemAtIndex`
- To get (duplicate) the element on the linear list according to index <br>
  (Index **starts from 1 to the length of the list**)
- Parameter(s):
  - Linear list object
  - Index
- Return value: the element at the index on the list
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `locateElem`
- To get the index(es) of the element on the list
- Parameter(s):
  - Linear list object
  - Element
- Return value: A **struct** includes an array of indexes and a integer of the number of index <br>
  If the element is not on the list, the number of index will be `-1`
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `isIn`
- To check if the element is included in the linear list.
- Parameter(s):
  - Linear list object
  - Element
- Return value: **Boolean** of "The element is included in the list"
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `getSucc`
- To get the successor(s) of the element
- Parameter(s):
  - Linear list object
  - Element
- Return value: A struct includes an array of elements (successors) and a integer of the number of the successor(s)

  > The function returns multiple successors **only if the list has duplicate elements** <br>
  > Multiple successors sorted in lower index of original element to higher <br>
  > If the element is not on the list, the number of successor(s) will be `-1` <br>
  > If the element has no successor, the "successor" in the array will be `NULL` (In test case, it is `'\0'`)
  
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `getPred`
- To get the predecessor(s) of the element
- Parameter(s):
  - Linear list object
  - Element
- Return value: A struct includes an array of elements (successors) and a integer of the number of the successor(s)

  > The function returns multiple predecessors **only if the list has duplicate elements** <br>
  > Multiple successors sorted in lower index of original element to higher <br>
  > If the element is not on the list, the number of predcessor(s) will be `-1` <br>
  > If the element has no predecessor, the "predecessor" in the array will be `NULL` (In test case, it is `'\0'`)
  
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `insertElemAfterIndex`
- To insert element after the index provided
- Parameter(s):
  - **Pointer** to the linear list object
  - Index
  
  > From `0` to the length of the list <br>
  > If index is `0`, the element will be inserted at the head of the list <br>
  > If index is "the length of the list", the element will be inserted at the tail of the list

  - Element
- Return value: **Boolean** of "Insert complete"
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

#### `deleteElemAtIndex`
- To delete (remove) the element on the linear list at the index provided
- Parameter(s):
  - **Pointer** to the linear list object
  - Index
- Return value: **Boolean** of "Delete element successful"
- Availibility:
  - Static Sequenced List
  - Dynamic Sequenced List

