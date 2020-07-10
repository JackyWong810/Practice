#include "stack.h"  

//初始化  
void stackInit(pStack S) {
    S->top = -1;
}

//入栈  
bool stackPush(pStack S, SElemType e) {
    if (S->top == MAX)
        return false;
    S->top++;
    S->data[S->top] = e;
    return true;
}

//出栈  
bool stackPop(pStack S, SElemType* e) {
    if (S->top == -1)
        return false;
    *e = S->data[S->top--];
    return true;
}

//空棧
bool stackEmpty(pStack S)
{
    return S->top + 1 == 0;
}

//栈的长度  
int stackLength(Stack S) {
    return S.top + 1;
}

//棧的逆轉
Stack stackReverse(pStack S)
{
    Stack S1;
    stackInit(&S1);
    SElemType e;
    while (!stackEmpty(S))
    {
        stackPop(S, &e);
        stackPush(&S1, e);
    }
    return S1;
}
