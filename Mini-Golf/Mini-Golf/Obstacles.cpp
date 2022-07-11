#include "Obstacles.h"

void Obstacles::Draw()
{
	for (const auto obstacle : obstacles)
	{
		DrawRectangleRec(obstacle.rect, RAYWHITE);
    
	for (int i = 0; i < obstacleList.size(); i++)
	{
		DrawRectangleRec(obstacleList[i].rect, RAYWHITE);
	}
}

void Obstacles::Add(Obstacle obstacle)
{
	obstacles.push_back(obstacle);
}

void Obstacles::CheckCollisionObstacles(Ball &ball) //This method is not finished yet.
{
	for (const auto obstacle : obstacles)
	{
		//std::cout << obstacle.x << "\n";
		std::cout << ball.posX - ball.radius << "\n";
		std::cout << ball.posX + ball.radius << "\n";
		if (ball.posX + ball.radius > obstacle.x && ball.posX - ball.radius < obstacle.x)
		{
			ball.velocity.x *= -1;
		}
	}
}
	obstacleList.push_back(obstacle);
}

void Obstacles::CheckCollisionObstacles(Ball& ball) //This method is not finished yet.
{
	for (int i = 0; i < obstacleList.size(); i++)
	{
		Obstacle obs = obstacleList[i];

		
		if (BallTouchesXofObstacle(ball, obs) && BallisBetweenYofObstacle(ball, obs))
		{
			ball.velocity.x *= -1;
		}
		if (BallTouchesYofObstacle(ball, obs) && BallisBetweenXofObstacle(ball, obs))
		{
			ball.velocity.y *= -1;
		}
		//std::cout << BallisBetweenYofObstacle(ball, obs) << "\n";
		//std::cout << ball.posX - ball.radius << "\n";
		//std::cout << obs.x + obs.width << "\n";
	}
}

bool Obstacles::BallTouchesXofObstacle(Ball& ball, Obstacle& obs)
{
	if (ball.posX + ball.radius > obs.x && ball.posX - ball.radius < obs.x + obs.width)
	{
		return true;
	}
	return false;
}

bool Obstacles::BallTouchesYofObstacle(Ball& ball, Obstacle& obs)
{
	if (ball.posY + ball.radius > obs.y && ball.posY - ball.radius < obs.y + obs.height)
	{
		return true;
	}
	return false;
}

bool Obstacles::BallisBetweenYofObstacle(Ball& ball, Obstacle& obs)
{
	if (ball.posY + ball.radius > obs.y && ball.posY - ball.radius < obs.y + obs.height)
	{
		return true;
	}
	return false;
}

bool Obstacles::BallisBetweenXofObstacle(Ball& ball, Obstacle& obs)
{
	if (ball.posX + ball.radius > obs.x && ball.posX - ball.radius < obs.x + obs.width)
	{
		return true;
	}
	return false;
}
