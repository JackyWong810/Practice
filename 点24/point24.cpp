#include "calculation.h"
#include "poker.h"

Stack S, S1;
Deck* ptrCards;

void mainloop();
void tureORfalse();

int main()
{
	printf("**************************************************\n");
	printf("*     Welcome to play our game : 24 points!      *\n");
	printf("*     The input format as follows:               *\n");
	printf("*                 (1+3)*(10-4)                   *\n");
	printf("*     Eneter \"close\" to exit the game.           *\n");
	printf("* Note: Square brackets must be English symbols. *\n");
	printf("**************************************************\n");
	mainloop();
}

void mainloop()
{
	while (true)
	{
		stackInit(&S1);
		stackInit(&S);
		ptrCards = getNumber();
		printDeck(ptrCards);
		tureORfalse();
	}
}

void tureORfalse()
{
	int result = 0;
	char formula[50];
	char Close[] = "close";
	printf("Enter formula:");
	scanf_s("%s", &formula);
	if (!strcmp(formula, Close))
	{
		printf("Close");
		exit(0);
	}
	S = splitFormula(&S1, formula);
	if (isSame(&S1, ptrCards))
	{
		result = calculation(&S, formula);
		printf("result--->%d\n", result);
		if (result == 24)
			printf("True\n");
		else
			printf("False\n");
		printf("===========================\n");
	}
	else
	{
		printf("not found deck number!\n");
		printf("Re-enter the formula.\n");
		tureORfalse();
	}
}
