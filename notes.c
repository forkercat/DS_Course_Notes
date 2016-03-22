// Linear Order List

#define ListSize 100
typedef struct {
    ListData data[ListSize];
    int length;
} SeqList;

InitList(&L);
DestroyList(&L);
ClearList(&L);
ListEmpty(L);
ListLength(L);
GetElem(L, i);
LocateElem(L, x);

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
    L.length--;
    for (int j = i - 1; j < L.length; j++)
        L.data[j] = L.data[j + 1];
    return 1;
}



