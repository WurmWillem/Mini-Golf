#pragma once
#include "ball.h"
#include "Hole.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "Obstacle.h"
#include "Obstacles.h"

class Game
{
public:

	std::vector<Ball> balls;
	std::vector<Hole> holes;
	std::vector<int> scores;
	Obstacles obstacles;

	bool RunLevel(int level);

	void Update();

	void LoadLevel(int level);

	bool ShowUI();

	std::vector<int> LoadScores();
};