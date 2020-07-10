#include "poker.h"

//隨機獲取4個數字（1-13），返回Deck
Deck *getNumber()
{
	static Deck cards[4];
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		cards[i].number = rand() % 13 + 1;
		cards[i].flag = 0;
	}
	return cards;
}

//判斷用戶輸入的數字和隨機出的數字是否相同
bool isSame(Stack* S, Deck cards[])
{
	//相同返回true，否則返回false
	SElemType e;
	int n = 0;
	while (!stackEmpty(S))
	{
		stackPop(S, &e);
		for (int i = 0; i < 4; i++)
		{
			if (e == cards[i].number)
				if (cards[i].flag == 0)
					cards[i].flag = 1;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		n += cards[i].flag;
	}
	if (n == 4)
		return true;
	return false;
}

void printDeck(Deck cards[])
{
	for (int i = 0; i < 4; i++)
	{
		printf("%d\t", cards[i].number);
	}
	printf("\n");
}
