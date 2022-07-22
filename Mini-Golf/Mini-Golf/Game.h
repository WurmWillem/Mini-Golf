#pragma once
#include "ball.h"
#include "Hole.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "Obstacle.h"
#include "Obstacles.h"
#include "LevelUI.h"

class Game
{
public:

	std::vector<Ball> balls;
	std::vector<Hole> holes;
	std::vector<int> scores;
	Obstacles obstacles;

	float strokesForPar;

	bool endApplication;

	bool RunLevel(int level);

	bool Update();

	void LoadLevel(int level);

	bool ShowUI();

	void ResetGame(int level);

	void SaveScore(int level, Ball& ball);
};