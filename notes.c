#include <stdio.h>

/*
    SeqList - Static
*/

typedef char ListData;

#define ListSize 100
typedef struct {
    ListData data[ListSize];
    int length;
} SeqList;

void InitList(SeqList &L)
{
    L.length = 0;
}

void DestroyList(SeqList &L)
{
    L.length = 0;
}

void ClearList(SeqList &L)
{
    L.length = 0;
}

int ListEmpty(SeqList L)
{
    return !L.length;
}

int ListLength(SeqList L)
{
    return L.length;
}

ListData GetElem(SeqList L, int i)
{
    if (i >= 1 && i <= L.length) {
        return L.data[i-1];
    } else {
        return NULL;
    }
}

int LocateElem(SeqList L, ListData x)
{
    int i = 0;
    while (i < L.length && L.data[i] != x) i++; // locating
    if (i < L.length)
        return i;
    else
        return -1;
}

int IsIn(SeqList L, ListData x)
{
    int i = 0, found = 0;
    while (i < L.length && !found)
        if (L.data[i] != x)
            i++;
        else
            found = 1;
    return found;
}

int NextElem(SeqList L, ListData x)
{
    int i = 0;
    while (i < L.length && L.data[i] != x) i++;
    if ((i >= 0) && (i < L.length - 1)) 
        return i + 1;
    else
        return -1;
}

int PriorElem(SeqList L, ListData x)
{
    int i = 0;
    while (i < L.length && L.data[i] != x) i++;
    if (i > 0 && i < L.length)
        return i - 1;
    else
        return -1;
}

int ListInsert(SeqList &L, int i, ListData x)
{
    if (i < 1 || i > L.length + 1 || L.length == ListSize)
        return 0;
    else {
        for (int j = L.length; j > i - 1; j--)
            L.data[j] = L.data[j - 1];
        L.data[i - 1] = x;
        L.length++;
        return 1;
    }
}

int ListDelete(SeqList &L, int i)
{
    if (i < 1 || i > L.length)
        return 0;
    for (int j = i - 1; j < L.length; j++)
        L.data[j] = L.data[j + 1];
    L.length--;
    return 1;
}

/*
    SqList - Dynamic
*/

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 5

typedef struct {
    ListData *data;
    int length;
    int listsize;
} SqList;

int InitList(SqList &L)
{
    L.data = (ListData *)malloc(LIST_INIT_SIZE * sizeof(ListData));

    if (!L.data)
        exit(0);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;
}

int DestroyList(SqList &L)
{
    free(L.data);
    L.length = 0;
    L.listsize = 0;
    return 1;
}

int ClearList(SqList &L)
{
    L.length = 0;
    return 1;
}

int ListEmpty(Sqlist L)
{
    return !L.length;
}

int ListLength(SqList L)
{
    return L.length;
}

ListData GetElem(Sqlist L, int i)
{
    if (i >= 1 && i <= L.length) {
        return *(L.data + i - 1);
    } else {
        return NULL;
    }
}

int LocateElem(SqList L, ListData x)
{
    int i = 0;
    while (i < L.length && *(L.data + i) != x) i++;
    if (i < L.length) return i;
    else return -1;
}

int IsIn(SqList L, ListData x)
{
    int i = 0, found = 0;
    while (i < L.length && !found)
        if (*(L.data + i) != x)
            i++;
        else
            found = 1;
    return found;
}

int NextElem(Sqlist L, ListData x)
{
    // ignore the same above
}

int PriorElem(Sqlist L, ListData x)
{
    // ignore the same above
}

int ListInsert(SqList &L, int i, ListData e)
{
    ListData *newbase, *q, *p;
    if (i < 1 || i > L.length + 1)
        return 0;
    if (L.length == L.listsize) {
        newbase = (ListData *)realloc(L.data, (L.listsize + LISTINCREMENT) * sizeof(ListData));
        if (!newbase) exit(0);
        L.data = newbase;
        L.listsize += LISTINCREMENT;
    }

    q = L.data + i - 1; // insert position
    for (p = L.data + L.length - 1; p >= q; --p) {
        *(p + 1) = *p; // move 2 right
    }
    *q = e;
    L.length++;
    return 1;
}

int ListDelete(Sqlist &L, int i)
{
    ListData *p, *q;
    if (i < 1 || i > L.length) return 0;
    p = L.data + i - 1; // delete position
    q = L.data + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p; // move 2 left
    L.length--;
    return 1;
}














