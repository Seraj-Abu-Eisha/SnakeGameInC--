#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

class snakegameh
{

private:
	bool isGameOver;
	int width, height;
	int snakeHeadX, snakeHeadY;
	int foodX, foodY;
	int score;

	std::vector<int> snakeTailX, snakeTailY;
	int snakeTailLength;
	enum eDirection 
	{
		STOP =0,
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};
	eDirection dir;
public:
	bool getIsGameOver() { return isGameOver; }
	void Setup();
	void Print();
	void Input();
	void Logic();
	
};

