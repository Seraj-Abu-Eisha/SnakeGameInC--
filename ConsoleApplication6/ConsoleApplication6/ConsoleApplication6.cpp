#include <cmath>
#include "snakegameh.h"
#include <iostream>
using namespace std;
int main()
{
	snakegameh snake;
	snake.Setup();

	while (!snake.getIsGameOver()) {
		snake.Print();
		snake.Input();
		snake.Logic();
		Sleep(10);
	}
	return 0;
}