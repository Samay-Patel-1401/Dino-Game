#include <conio.h>
#include <thread>
#include <iostream>

using namespace std;

bool toJump, gameOver;

void setup();

void draw();

void input();

int main()
{
	setup();

	thread run(draw);

	input();

	run.join();

	return 0;
}