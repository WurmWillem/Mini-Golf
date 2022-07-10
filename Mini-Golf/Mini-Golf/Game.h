#pragma once
#include "ball.h"
#include "Hole.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

class Game
{
public:
	//std::vector<Obstacle> obstacles;

	std::vector<Ball> balls;
	std::vector<Hole> holes;

	bool Run();

	void Update(Ball& ball, Hole &hole);

	void LoadLevel(int level);
};