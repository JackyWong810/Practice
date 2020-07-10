#pragma once  
#include "header.h"
#define MAX 20  
typedef int SElemType;
typedef struct Stack {
    SElemType data[MAX];
    int top;
}Stack, * pStack;

//初始化  
void stackInit(pStack S);
//入栈  
bool stackPush(pStack S, SElemType e);
//出栈  
bool stackPop(pStack S, SElemType* e);
//空棧
bool stackEmpty(pStack S);
//栈的长度  
int stackLength(Stack S);
//棧的逆轉
Stack stackReverse(pStack S);
