# 栈和队列
[定义](/doc/definitions.pdf)

# 目录
- 基本操作

# 基本操作
- 栈
  - 压栈
  - 出栈
  - 取顶部栈
  - 清空栈
  - 判断栈是否为空栈
  - 判断栈是否为满栈
- 队列

# 静态顺序栈
## 结构定义
```c++
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;             

typedef char StackData;

typedef struct {	                       
    StackData* base;
    StackData* top;
    int stacksize;
} SeqStack;
```
## 初始化栈
```c++
void InitStack(SeqStack *S) {   //置空栈
S->base =( StackData *)malloc(STACK_INIT_SIZE * 			                                                            sizeof(StackData));
if (!S->base) exit(OVERFLOW);
S->top = S->base ; 
S->stacksize= STACK_INIT_SIZE ;
Return  OK;
}
```
## 压栈
```c++
Status Push(SeqStack *S, StackData x) {
    if (StackFull(S)) {
    	S->base =(StackData*) realloc(S->base,
    			      (S->stacksize + STACKINCREMENT) * sizeof(StackData));
    	if(!S->base)
    	    exit(overflow);
    	S->top = S->base + S->stacksize;
    	S->stacksize += STACKINCREMENT;
    }
    *(S->top++) = x;
    return ok;
}
```
## 出栈
```c++
int pop(SeqStack *S, StackData &x) {
    if (StackEmpty(S))
        return 0;
	  x = *(--S->top);
    return 1;
}
```
## 取顶部栈
```c++
int Gettop(SeqStack* S, StackData& x) {
    if (StackEmpty(S))
        return 0;
    (S->top)--;
	  x = *(S->top++);
  	return 1;
}
```
## 清空栈
```c++
void InitStack(SeqStack *S) {   //置空栈
S->base =( StackData *)malloc(STACK_INIT_SIZE * 			                                                            sizeof(StackData));
if (!S->base) exit(OVERFLOW);
S->top = S->base ; 
S->stacksize= STACK_INIT_SIZE ;
Return  OK;
}
```
## 判断栈是否为空栈
```c++
int StackEmpty(SeqStack* S) {
	  if (S->top == S->base)
	      return 1;
    else
        return 0;
}
```
## 判断栈是否为满栈
```c++
int StackFull(SeqStack* S) {
	  if(S->top - S->base == S->StackSize)
	      return 1;
	  else
	      return 0;
}
```
