#include "Obstacles.h"

void Obstacles::Draw()
{
	for (int i = 0; i < obstacleList.size(); i++)
	{
		DrawRectangleRounded(obstacleList[i].rect, 0.0f, 1, DARKGRAY);
		DrawRectangleRoundedLines(obstacleList[i].rect, 0.15f, 1, 2.0f, BLACK);
	}
}

void Obstacles::Add(Obstacle obstacle)
{
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
	}
}

bool Obstacles::BallTouchesXofObstacle(Ball& ball, Obstacle& obs)
{
	if (ball.posX + ball.radius + (ball.velocity.x * ball.velocityMultiplier * GetFrameTime()) > obs.x && ball.posX - ball.radius + (ball.velocity.x * ball.velocityMultiplier * GetFrameTime()) < obs.x + obs.width)
	{
		return true;
	}
	return false;
}

bool Obstacles::BallTouchesYofObstacle(Ball& ball, Obstacle& obs)
{
	if (ball.posY + ball.radius + (ball.velocity.y * ball.velocityMultiplier * GetFrameTime()) > obs.y && ball.posY - ball.radius + (ball.velocity.y * ball.velocityMultiplier * GetFrameTime()) < obs.y + obs.height)
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

void Obstacles::Clear()
{
	obstacleList.clear();
}