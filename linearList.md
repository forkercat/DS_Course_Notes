# 线性表

## 基本操作

- 生成线性表
- 销毁线性表
- 查找元素
- 插入元素
- 删除元素
- 遍历

## 静态存储顺序线性表

### 结构定义
```c++

typedef char ListData;

#define ListSize 100

typedef struct tagOfSeqlist Seqlist;

struct tagOfSeqlist {
    ListData data[ListSize];
    int length;
}; 
```

### 初始化表
```c++
void InitList(SeqList &L) {
    L->length = 0;
}
```

### 销毁表
```c++
void DestroyList(SeqList &L) {
    L->length = 0;
}
```

### 清空表
```c++
void ClearList(Seqlist &L) {
    L.length = 0;
}
```

### 判断是否为空表
```c++
int ifListIsEmpty(SeqList &L) {
    return !L.length;
}
```

### 获取表的长度
```c++
int getLengthOfList(SeqList &L) {
    return L.length;
}
```

### 获取元素
```c++
ListData GetElem(SeqList L, int i) {
    if (i >=1 && i <= L.length) {
        return L.data[i - 1];
    }
    else {
        return NULL;
    }
}
```

### 定位元素
```c++
int LocateElem(SeqList L, int i) {
    if (i >= 1 && i <= L.length) {
        return L.data[i - 1];
    }
    else {
        return NULL;
    }
}
```

### 判断元素是否在表中
```c++
int IsIn(SeqList L, ListData x) {
    for (int i = 0; i < L.length && L.data[i] != x; ++i) {}
    if (i < L.length - 1) {
        return i + 1;
    }
    else {
        return -1;
    }
}
```

### 寻找特定元素之前的元素的下标
```c++
int NextElem(SeqList L, ListData x) {
    for (int i = 0; i < L.length && L.data[i] != x; ++i) {}
    if (i < L.length - 1) {
        return i + 1;
    }
    else {
        return -1;
    }
}
```

### 寻找特定元素之后的元素的下标
```c++
int NextElem(SeqList L, ListData x) {
    for (int i = 0; i < L.length && L.data[i] != x; ++i) {}
    if (i < L.length - 1) {
        return i - 1;
    }
    else {
        return -1;
    }
}
```

### 在指定下标之后插入元素
```c++
int ListInsert(SeqList &L, int index, ListData e) {
    Listdata *newbase, *p, *q;
    if (index < 1 || index > L.length + 1)
        return -1;
    if (L.length == L.listsize) {
        newbase = (Listdata*) realloc(L.data, (L.listsize + LISTINCREMENT)
                * sizeof(ListData));
        if (!newbase)
            return -1;
        L.data = newbase;
        L.listsize += LISTINCREMENT;
    }
    q = L.data + i - 1; // insert position
    for (p = L.data + L.length - 1; p >= q; --p) {
        *(p + 1) = *p; // move 2 right
    }
    *q = e;
    L.length++;
    return 0;
}
```

### 删除指定下标的元素
```c++
int DeleteElem(SqList &L, int index) {
    Listdata *p, *q;
    if (index < 1 || index > L.length)
        return -1;
    p = L.data + i - 1;
    q = L.data + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p;
    --L.length;
    return 0;
}
```
