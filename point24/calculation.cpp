#include "calculation.h" 

//拆解公式
Stack splitFormula(Stack*S1,char formula[])
{
    Stack S;
    stackInit(&S);
    SElemType e;
    int i = 0;
    //循環字符串formula
    while (formula[i] != '\0')
    {
        int j = 0;
        char b[10] = "";
        while (formula[i] != '+' && formula[i] != '-' && formula[i] != '*' && formula[i] != '/' && formula[i] != '(' && formula[i] != ')' && formula[i] != '\0')
        {
            //找出數字並將其變成int類型，然後壓棧到S
            b[j] = formula[i];
            j++;
            i++;
            if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == '(' || formula[i] == ')' || formula[i] == '\0')
            {
                e = atoi(b);
                stackPush(&S, e);
                stackPush(S1, e);
                break;
            }
        }
        //if (formula[i] == '\0')break;

        if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == '(' || formula[i] == ')')
        {
            //符號變成int類型並壓棧到S
            e = formula[i];
            stackPush(&S, e);
        }
        if(formula[i]!='\0')
            i++;
    }
    //返回棧的逆轉
    return stackReverse(&S);
}
//計算括號
Stack calBrackets(Stack* S)
{
    Stack S1;
    stackInit(&S1);
    SElemType e;
    //循環棧S直到棧S為空
    while (!stackEmpty(S))
    {
        stackPop(S, &e);
        //檢查式子有括號進行括號内的計算，括號内的值壓棧到S1，沒括號則直接壓棧到S1
        if (e == 40)
        {
            //計算括號内的值然後壓棧到S1
            Stack S2;
            stackInit(&S2);
            stackPop(S, &e);
            while (e != 41)
            {
                stackPush(&S2, e);
                stackPop(S, &e);
            }
            S2 = stackReverse(&S2);
            //計算公式，先乘除后加減
            e = calAddSub(&calMulDiv(&S2));
            //結果壓棧
            stackPush(&S1, e);
        }
        else
            stackPush(&S1, e);
    }
    
    S1 = stackReverse(&S1);
    return S1;
}
//計算乘除
Stack calMulDiv(Stack* S)
{
    Stack S1;
    stackInit(&S1);
    SElemType e;
    stackPop(S, &e);
    stackPush(&S1, e);
    do
    {
        stackPop(S, &e);
        if (e == 42 || e == 47)
        {
            if (e == 42)
            {
                SElemType new_e;
                stackPop(S, &e);
                stackPop(&S1, &new_e);
                new_e *= e;
                stackPush(&S1, new_e);
            }
            if (e == 47)
            {
                SElemType new_e;
                stackPop(S, &e);
                stackPop(&S1, &new_e);
                new_e /= e;
                stackPush(&S1, new_e);
            }
        }
        else
            stackPush(&S1, e);

    } while (!stackEmpty(S));
    return stackReverse(&S1);
}
//計算加減
int calAddSub(Stack* S)
{
    SElemType e;
    stackPop(S, &e);
    int result = e;
    while (!stackEmpty(S))
    {
        stackPop(S, &e);
        if (e == 43 || e == 45)
        {
            if (e == 43)
            {
                stackPop(S, &e);
                result += e;
            }
            if (e == 45)
            {
                stackPop(S, &e);
                result -= e;
            }
        }
    }
    return result;
}
//公式的計算
int calculation(Stack* S,char formula[])
{
    int result = 0;
    result = calAddSub(&calMulDiv(&calBrackets(S)));
    return result;
}

