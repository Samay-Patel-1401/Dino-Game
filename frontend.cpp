#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

extern bool toJump, gameOver;

int A[] = { 2,1,0,1,2 };

void obstacle(int x, int i);

void isSafe(int y, int* objx, int *objtype);

void jump(int *objx, int *objtype, int y)
{
	int a = 0;

	while (!gameOver && a < 5)
	{
		if (objx[0] < 0)
		{
			objx[0] = 50;
			objtype[0] = rand() % 4;
		}
		if (objx[1] < 0)
		{
			objx[1] = 50;
			objtype[1] = rand() % 4;
		}

		system("cls");
		printf("\n\n\n\n");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 51; j++)
			{
				if (A[a] == i && j == 10)
					printf("O");
				else if (i == 4)
					printf("=");
				else if (objx[0] == j && (i == 2 || i == 3))
					obstacle(objtype[0], i);
				else if (objx[1] == j && (i == 3 || i == 2))
					obstacle(objtype[1], i);
				else
					printf(" ");
			}
			printf("\n");
		}

		isSafe(A[a], objx, objtype);

		objx[0]--;
		objx[1]--;
		a++;
		this_thread::sleep_for(chrono::milliseconds(80));
	}

	toJump = false;
}

void draw()
{
	int y = 3;
	int objx[2] = { 25, 50 };
	int objtype[2] = { 0, 2 };

	while (!gameOver)
	{
		if (objx[0] < 0)
		{
			objx[0] = 50;
			objtype[0] = rand() % 4;
		}
		if (objx[1] < 0)
		{
			objx[1] = 50;
			objtype[1] = rand() % 4;
		}

		if (toJump)
		{
			jump(objx, objtype, y);			 
		}
		else
		{
			system("cls");
			printf("\n\n\n\n");
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 51; j++)
				{
					if (y == i && j == 10)
						printf("O");
					else if (i == 4)
						printf("=");
					else if (objx[0] == j && (i == 3 || i == 2))
						obstacle(objtype[0], i);
					else if (objx[1] == j && (i == 3 || i == 2))
						obstacle(objtype[1], i);
					else
						printf(" ");
				}
				printf("\n");
			}

			isSafe(y, objx, objtype);  

			objx[0]--;
			objx[1]--;
			this_thread::sleep_for(chrono::milliseconds(80));
		}
	}

	printf("\a\nYou Lost\n");
}