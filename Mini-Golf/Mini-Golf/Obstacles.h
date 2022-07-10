#pragma once
#include <Vector>
#include "Obstacle.h"
#include"Ball.h"

class Obstacles
{
private:
	std::vector<Obstacle> obstacleList;

public:
	void Draw();
	void Add(Obstacle obstacle);
	void CheckCollisionObstacles(Ball& ball);
};

