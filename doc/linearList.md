# 线性表

[定义](/doc/definitions.pdf)

## 目录
- [基本操作](/doc/linearList.md#基本操作)
- [静态存储顺序表](/doc/linearList.md#静态存储顺序表)
- [动态存储顺序表](/doc/linearList.md#动态存储顺序表)
- [单向无头结点链表](/doc/linearList.md#单向无头结点链表)
- [单向链表](/doc/linearList.md#单向链表)
- [静态链表](/doc/linearList.md#静态链表)
- [双向循环链表](/doc/linearList.md#双向循环链表)

## [基本操作](/doc/linearList.md#目录)

- 初始化表为空表
- 销毁表
- 清空表
- 检查是否为空表
- 获取表的长度
- 获取指定下标的元素
- 获取指定元素的下标
- 判断元素是否在表中
- 获取直接前驱
- 获取直接后继
- 在指定下标之前插入元素
- 删除指定下标的元素

## [静态存储顺序表](/doc/linearList.md#目录)

### 结构定义
```c++
typedef char ListData;

#define ListSize 100

typedef struct {
    ListData data[ListSize];
    int length;
} SeqList;
```

### 初始化表
```c++
void InitList (SeqList &L) {                                                         
    L.length = 0;
}
```

### 销毁表
```c++
void DestroyList(SeqList &L) {
    L.length = 0;
}
```

### 清空表
```c++
void ClearList(Seqlist &L) {
    L.length = 0;
}
```

### 检查是否为空表
```c++
int ListEmpty(SeqList &L) {
    return !L.length;
}
```

### 获取表的长度
```c++
int ListLength(SeqList L) {
    return L.length;
}
```

### 获取指定下标的元素
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

### 获取指定元素的下标
```c++
int LocateElem(SeqList L, ListData x) {
    int i = 0;
    while (i < L.length && L.data[i] != x) i++; // locating
    if (i < L.length)
        return i;
    else
        return -1;
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

### 获取直接前驱
```c++
int PriorElem(SeqList L, ListData x) {
    int i = 0;
    while (i < L.length && L.data[i] != x) i++;
    if (i > 0 && i < L.length)
        return i - 1;
    else
        return -1;
}
```

### 获取直接后继
```c++
int NextElem(SeqList L, ListData x) {
    int i = 0;
    while (i < L.length && L.data[i] != x) i++;
    if (i < L.length - 1) 
        return i + 1;
    else
        return -1;
}
```

### 在指定下标之前插入元素
```c++
int ListInsert(SeqList &L, int i, ListData x) {
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
```

### 删除指定下标的元素
```c++
int ListDelete(SeqList &L, int i) {
    if (i < 1 || i > L.length)
        return 0;
    for (int j = i - 1; j < L.length - 1; j++)
        L.data[j] = L.data[j + 1];
    L.length--;
    return 1;
}
```
## [动态存储顺序表](/doc/linearList.md#目录)

### 结构定义
```c++
tyoedef char ListData

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 5

typedef struct {
    ListData *data;
    int length;
    int listsize;
} SqList;
```
### 初始化表为空表
```c++
int InitList(SqList &L) {
    L.data = (ListData *)malloc(LIST_INIT_SIZE * sizeof(ListData));

    if (!L.data)
        exit(0);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;
}
```
### 销毁表
```c++
int DestroyList(SqList &L) {
    free(L.data);
    L.length = 0;
    L.listsize = 0;
    return 1;
}
```
### 清空表
```c++
int ClearList(SqList &L) {
    L.length = 0;
    return 1;
}
```
### 检查是否为空表
```c++
int ListEmpty(Sqlist L) {
    return !L.length;
}
```
### 获取表的长度
```c++
int ListLength(SqList L) {
    return L.length;
}
```
### 获取指定下标的元素
```c++
ListData GetElem(Sqlist L, int i) {
    if (i >= 1 && i <= L.length) {
        return *(L.data + i - 1);
    } 
    else {
        return NULL;
    }
}
```
### 获取指定元素的下标
```c++
int LocateElem(SqList L, ListData x) {
    int i = 0;
    while (i < L.length && *(L.data + i) != x) i++;
    if (i < L.length)
        return i;
    else 
        return -1;
}
```
### 判断元素是否在表中
```c++
int IsIn(SqList L, ListData x) {
    int i = 0, found = 0;
    while (i < L.length && !found)
        if (*(L.data + i) != x)
            i++;
        else
            found = 1;
    return found;
}
```
### 获取直接前驱
```c++
int PriorElem(Sqlist L, ListData x) {
    int i = 0;
    while (i < L.length && *(L.data + i) != x) i++;
    if (i > 0 && i < L.length)
        return i - 1;
    else
        return -1;
}
```
### 获取直接后继
```c++
int NextElem(Sqlist L, ListData x) {
    int i = 0;
    while (i < L.length && *(L.data + i) != x) i++;
    if (i < L.length - 1) return i + 1;
    else return -1;
}
```
### 在指定下标之前插入元素
```c++
int ListInsert(SqList &L, int i, ListData e) {
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
```
### 删除指定下标的元素
```c++
int ListDelete(Sqlist &L, int i) {
    ListData *p, *q;
    if (i < 1 || i > L.length) return 0;
    p = L.data + i - 1; // delete position
    q = L.data + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p; // move 2 left
    L.length--;
    return 1;
}
```
## [单向无头结点链表](/doc/linearList.md#目录)
### 结构定义
```c++
typedef char ListData;

typedef struct node {
    ListData data;
    struct node* next;
} ListNode;

typedef ListNode* LinkList;
```
### 初始化表为空表
```c++
void InitList(LinkList &first) {
    first = NULL;
}
```
### 销毁表
```c++
void DestroyList(LinkList &first) {
    ListNode *q;
    while (first) {
        q = first;
        first = first->next;
        free(q);
    }
}
```
### 清空表
```c++
void ClearList(LinkList &first) {
    ListNode* q;
    while (first) {
        q = first;
        first = first->next;
        free(q);
    }
}
```
### 检查是否为空表
```c++
int ListEmpty(LinkList first) {
    return !first;
}
```
### 获取表的长度
```c++
int ListLength(LinkList first) {
    LinkList p;
    p = first;
    int count = 0;
    while (p) {
        p = p->next;
        ++count;
    }
    return count;
}
```
### 获取指定下标的元素
```c++
ListData GetElem(LinkList first, int i) {
    LinkList p;
    int j;
    p = first;
    j = 1;
    while (p && (j < i)) {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return NULL;
    return p->data;
}
```
### 获取指定元素的下标
```c++
LinkList LocateElem(LinkList first, ListData x) {
    ListNode* p = first;
    while (p && (p->data != x))
        p = p->next;
    return p;
}
```
### 判断元素是否在表中
```c++
int IsIn(LinkList first, ListData x) {
    ListNode* p = first;
    while (p && (p->data != x))
        p = p->next;
    return !(p == NULL);
}
```
### 获取直接前驱
```c++
LinkList PriorElem(LinkList first, ListData x) {
    LinkList p = first;
    while (p && p->next && (p->next->data != x))
        p = p->next;
    if (!p || !p->next)
        return NULL;
    return p;
}
```
### 获取直接后继
```c++
LinkList NextElem(LinkList first, ListData x) {
    LinkList p=first;
    while(p && p→data != x)                            
        p = p→next;
    if (!p || !p→next) 
        return NULL;
return p→next;                    
}
```
### 在指定下标之前插入元素
```c++
int ListInsert (LinkList &first, int i, ListData x) {
    newnode = (ListNode *) malloc (sizeof(ListNode));
    newnode→data = x;                                  
    if (i==1) {                                     
        newnode→next = first;                
        first = newnode;
        return  1; 
    }  
    p = first; k = 1;
    while (p && k < i-1) {
        p = p→next;
        k++;
    }
    if ( !p || i<1) ) {	
    printf ( “无效的插入位置!\n” );         
        free(newnode);
        return 0;
    }
    newnode→next = p→next; 		          
    p→next = newnode;                  
    return 1; 
}
```
### 删除指定下标的元素
```c++
int ListDelete(LinkList &first, int i) { 
    if (first && i == 1) {
        q = first;
        first = first->next;
    }
    else {
        p = first;
        k = 1;       
        while (p && k < i-1) { 
            p = p→next;
            k++;
        }
        if ( !p  || !(p->next) || i<1 ) { 
            printf (“无效的删除位置!\n”);
            return 0;
        }
        else {
            q = p->next;
            p->next = q->next;
        }
    }
    free (q); 
    return 1;
}
```
## [单向链表](/doc/linearList.md#目录)
### 结构定义
```c++
typedef char ListData;

typedef struct node {
    ListData data;
    struct node* next;
} ListNode;

typedef ListNode* LinkList;
```
### 初始化表为空表
```c++
void InitList(LinkList &first) {
    first = (ListNode *) malloc(sizeof(ListNode));
    first→next=NULL;
}
```
### 销毁表
```c++
void DestroyList(LinkList &first) {
    ListNode *q;
    while (first) {
 	     q =first；first= first→next;
	     free( q );        //释放 
    }  
}
```
### 清空表
```c++
void clear(LinkList &first) {
    ListNode p, *q = first->next;
    while (q) {
 	    p=q; q=q→next;
	    free(p);         
    }
    first->next=NULL;
}
```
### 检查是否为空表
```c++
int ListEmpty(LinkList first) {
    return  !(first→next) ;    
}
```
### 获取表的长度
```c++
int ListLength(LinkList first) {
    LinkList p,q;
    p = first->next;
    int count = 0;
    while(p) {
        p = p->next;
        count++;
    }
    return count;   
}
```
### 获取指定下标的元素
```c++
ListData GetElem(LinkList first, int i) {
    LinkList p; 
    int j;
    p=first→next;  j=1;
    while (p&&(j<i))  {                            //找第i个元素
        p=p->next;
        ++j;
    }
    if (!p || j > i) 
        return NULL;                           //第i个元素不存在
    return p->data;
}
```
### 获取指定元素的下标
```c++
ListNode* LocateElem(LinkList first, ListData x) {
    ListNode* p = first->next;
    while (p && (p->data != x))
         p = p->next;
    return p;     
}
```
### 判断元素是否在表中
```c++
int IsIn(LinkList first, ListData x) {
    ListNode* p = first->next;
    while (p && (p->data != x))  
        p = p→next;
    return !(p == NULL);     
}
```
### 获取直接前驱
```c++
LinkList PriorElem(LinkList first, ListData x) {
    LinkList p = first->next;
    while(p && p->next && (p->next->data != x))
        p = p->next;
    if (!p || !p->next) 
        return NULL;
    return  p;
}
```
### 获取直接后继
```c++
LinkList NextElem(LinkList first, ListData x) {
    LinkList p = first->next;
    while(p && p->data != x)
        p = p->next;
    if (!p || ! p->next)
        return NULL;
    return  p→next;                    
}
```
### 在指定下标之前插入元素
```c++
int ListInsert (LinkList first, ListData x, int i) {
    p = first; k = 0;
    while (p && k < i -1) {
        p = p->next;
        k++;
    }
    if (!p  || i < 1) {	
        printf(“无效的插入位置!\n”);
        return 0;
    }                                               
    newnode = (ListNode *) malloc(sizeof(ListNode));
    newnode->data = x;  
    newnode->next = p->next;
    p->next = newnode;
    return 1;   	
}
```
### 删除指定下标的元素
```c++
int ListDelete(LinkList first, int i) {
	p = first; k = 0;
    while (p && k++ < i - 1)
        p = p->next;
 	if (!p || !(p->next) || i < 1) 
	    return 0;
   	q = p->next;	 
	p->next = q->next;
    free(q);
    return 1;
}
```
## [静态链表](/doc/linearList.md#目录)
### 结构定义
```c++
typedef char ListData;
const int MaxSize = 100;

typedef struct node {
    ListData  data;
    int link;
} SNode;

typedef struct {
    SNode  Nodes[MaxSize];
    int newptr;
} SLinkList;
```
### 表空间初始化
```c++
void InitSpace(SLinkList &Space) {
    Space.newptr = 0;
    for (int i = 0; i < MaxSize - 1; i++)
    Space.Nodes[i].link = i + 1;
    Space.Nodes[MaxSize - 1].link = -1;
}
```
### 初始化表为空表
```c++
void InitList(SLinkList &Space，int &Slink) {
    if (Space.newptr != -1) {
    	Slink = Space.newptr;
    	Space.newptr = Space.Nodes[Space.newptr].link;
    }
    Space.Nodes[Slink].link=-1;
}
```
### 销毁表
```c++
void DestroyList(SLinkList &Space, int &Slink) {
    q = Slink;
    while (Space.Nodes[Slink].link != -1)
    	Slink = Space.Nodes[Slink].link;
    Space.Nodes[Slink].link = Space.newptr;
    Space.newptr = q;
    Slink = -1;
}
```
### 清空表
### 检查是否为空表
### 获取表的长度
### 获取指定下标的元素
### 获取指定元素的下标
### 判断元素是否在表中
### 获取直接前驱
### 获取直接后继
### 在指定下标之前插入元素
### 删除指定下标的元素

## [双向循环链表](/doc/linearList.md#目录)
### 结构定义
### 初始化表为空表
### 销毁表
### 清空表
### 检查是否为空表
### 获取表的长度
### 获取指定下标的元素
### 获取指定元素的下标
### 判断元素是否在表中
### 获取直接前驱
### 获取直接后继
### 在指定下标之前插入元素
### 删除指定下标的元素
