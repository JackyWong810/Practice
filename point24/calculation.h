#pragma once 
#include "stack.h"
//拆解公式
Stack splitFormula(Stack*S1,char formula[]);
//計算括號
Stack calBrackets(Stack* S);
//計算乘除
Stack calMulDiv(Stack* S);
//計算加減
int calAddSub(Stack* S);
//公式計算
int calculation(Stack* S, char formula[]);
