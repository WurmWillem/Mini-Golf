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
	Obstacles obstacles;

	bool Run();

	void Update();

	void LoadLevel(int level);
};