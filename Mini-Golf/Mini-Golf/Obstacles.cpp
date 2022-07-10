#include "Obstacles.h"

void Obstacles::Draw()
{
	for (const auto obstacle : obstacleList)
	{
		DrawRectangleRec(obstacle.rect, RAYWHITE);
	}
}

void Obstacles::Add(Obstacle obstacle)
{
	obstacleList.push_back(obstacle);
}

void Obstacles::CheckCollisionObstacles(Ball& ball) //This method is not finished yet.
{
	for (const auto obstacle : obstacleList)
	{
		//std::cout << obstacle.x << "\n";
		//std::cout << ball.posX - ball.radius << "\n";
		//std::cout << ball.posX + ball.radius << "\n";
		if (ball.posX + ball.radius > obstacle.x && ball.posX - ball.radius < obstacle.x)
		{
			ball.velocity.x *= -1;
		}
	}
}