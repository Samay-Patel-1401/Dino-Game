#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

extern bool toJump, gameOver;

int A[] = { 2,1,0,1,2 };

void obstacle(int x, int i);

void isSafe(int y, int* objx, int *objtype);

void jump(int *objx, int *objtype, int &score)
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

		system("clear");
		printf("\n\n\nscore : %d\n",score/10);
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
		score++;
		this_thread::sleep_for(chrono::milliseconds(90));
	}

	toJump = false;
}

void draw()
{
	int score = 0;
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
			jump(objx, objtype, score);			 
		}
		else
		{
			system("clear");
			printf("\n\n\nscore : %d\n",score/10);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 51; j++)
				{
					if (3 == i && j == 10)
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

			isSafe(3, objx, objtype);  

			objx[0]--;
			objx[1]--;
			score++;
			this_thread::sleep_for(chrono::milliseconds(125));
		}
	}

	printf("\a\nYou Lost\n");
}