#include "snakegameh.h"
void snakegameh::Setup() {
	isGameOver = false;
	score = 0;

	width = 20;
	height = 12;

	dir = STOP;
	snakeHeadX = width / 2;
	snakeHeadY = height / 2;

	srand(time(NULL));
	foodX = rand() % width;
	foodY = rand() % height;

	snakeTailX.resize(100);
	snakeTailY.resize(100);
}
void snakegameh::Print () {
	system("cls");

	for (int i = 0; i < width + 2; i++) 	std::cout << "-";	std::cout << std::endl;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) std::cout << "!";
				
				if (i == snakeHeadY && j == snakeHeadX) 
					std::cout << "S";
				else if (i == foodY && j == foodX)
					std::cout << "%";
				else {
					bool isSnakeTailCoord = false;
					for (int k = 0; k < snakeTailLength; k++)	
					{
						if (snakeTailX[k] == j && snakeTailY[k] == i)
						{
							std::cout << "S";
							isSnakeTailCoord = true;
						}
					}
					if (!isSnakeTailCoord) 	std::cout << " ";
				}
					if (j == width - 1) std::cout << "!";	
				}
			std::cout << std::endl;
			}
		for (int i = 0; i < width + 2; i++)  
			std::cout << "-"; 
		std::cout << std::endl << std::endl;
		std::cout << "score: " << score;
		std::cout << std::endl << std::endl;
	}
void snakegameh::Input (){
	if (_kbhit())
	{
		switch (_getch()) {
		case 'w':dir = UP;
			break;
		case 's':dir = DOWN;
			break;
		case 'd':dir = RIGHT;
			break;
		case 'a':dir = LEFT;
			break;
		case 27: isGameOver = true;
			break;
		}
  }
}
void snakegameh::Logic() {
	int prevX = snakeTailX[0];
	int prevY = snakeTailY[0];
	int prev2X, prev2Y;

	snakeTailX[0] = snakeHeadX;
	snakeTailY[0] = snakeHeadY;

	for (int i = 1; i < snakeTailLength; i++) {
		prev2X = snakeTailX[i];
		prev2Y = snakeTailY[i];
		snakeTailX[i] = prevX;
		snakeTailY[i] = prevY;
	}
	switch (dir) {
	case LEFT:
		snakeHeadX--;
		break;
	case RIGHT:
		snakeHeadX++;
		break;
	case UP:
		snakeHeadY--;
		break;
	case DOWN:
		snakeHeadY++;
		break;
	}
	if (snakeHeadX >= width)
		snakeHeadX = 0;
	else if (snakeHeadX < 0) snakeHeadX = width - 1;
	if (snakeHeadY >= width)  snakeHeadY = 0;

	for (int i = 0; i < snakeTailLength; i++) {
		if (snakeTailX[i] == snakeHeadX && snakeTailY[i] == snakeHeadY) {
			isGameOver = true;
		}
		
	}
	if (snakeHeadX == foodX && snakeHeadY == foodY) {
		snakeTailLength++;
		score++;

		srand(time(NULL));
		foodX = rand() % width;
		foodY = rand() % height;

	}
	
}