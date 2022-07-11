#pragma once
#include <Vector>
#include "Obstacle.h"
#include"Ball.h"

class Obstacles
{
private:
	std::vector<Obstacle> obstacles;
	
	std::vector<Obstacle> obstacleList;

public:
	void Draw();
	void Add(Obstacle obstacle);
	void CheckCollisionObstacles(Ball& ball);
};

	bool BallTouchesXofObstacle(Ball& ball, Obstacle& obstacle);
	bool BallTouchesYofObstacle(Ball& ball, Obstacle& obstacle);

	bool BallisBetweenYofObstacle(Ball& ball, Obstacle& obs);
	bool BallisBetweenXofObstacle(Ball& ball, Obstacle& obs);
};

