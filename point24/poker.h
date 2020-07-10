#pragma once
#include "stack.h"
typedef struct
{
	int number;//數字
	int flag;//記號
}Deck;
//隨機獲取4個數字（1-13），返回Deck
Deck *getNumber();
//判斷用戶輸入的數字和隨機出的數字是否相同
bool isSame(Stack* S, Deck cards[]);
//打印Deck的number
void printDeck(Deck cards[]);
