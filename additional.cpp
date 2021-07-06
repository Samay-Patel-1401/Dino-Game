#include <iostream>
#include <conio.h>

using namespace std;

extern bool gameOver, toJump;

void setup()
{
	gameOver = false;
	toJump = false;

	cout << "Press space to jump and avoid the obstacles\n";
	cout << "Now Press Enter to Start.\n";
	_getch();

	system("cls");

	return;
}

void obstacle(int x, int i)
{
	if (x == 0)
		if (i == 2)
			printf("<");
		else
			printf(" ");
	else if (x == 1)
		if (i == 3)
			printf("<");
		else
			printf(" ");
	else if (x == 2)
		if (i == 3)
			printf("#");
		else
			printf(" ");
	else
		printf("#");
}

void isSafe(int y, int *objx, int *objtype)
{
	if (10 == objx[0])
	{
		if ((objtype[0] == 0) && (y == 2))
			gameOver = true;
		else if (objtype[0] == 1 && y == 3)
			gameOver = true;
		else if (objtype[0] == 2 && y == 3)
			gameOver = true;
		else if (objtype[0] == 3 && y > 1)
			gameOver = true;
	}
	else if (10 == objx[1])
	{
		if (objtype[1] == 0 && y == 2)
			gameOver = true;
		else if (objtype[1] == 1 && y == 3)
			gameOver = true;
		else if (objtype[1] == 2 && y == 3)
			gameOver = true;
		else if (objtype[1] == 3 && y > 1)
			gameOver = true;
	}
}

void input()
{
	while (!gameOver)
	{
		_getch();
		toJump = true;
	}
}

