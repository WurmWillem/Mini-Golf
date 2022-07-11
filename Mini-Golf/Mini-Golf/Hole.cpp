#include "Hole.h"
#include "Ball.h"
#include "raylib.h"

Hole::Hole(int Radius)
{
	radius = Radius;
	holePosition = { (float) GetScreenWidth() / 2, 100};
}

void Hole::Draw()
{
	DrawCircle(holePosition.x, holePosition.y, radius, BLACK);

	return;
}

void Hole::CheckCollision(Ball& ball)
{
	if (CheckCollisionCircles(holePosition, radius, { (float)ball.posX, (float)ball.posY }, ball.GetRadius()))
	{
		ball.Shrink();
		ball.posX = GetScreenWidth() / 2;
		ball.posY = 100;;
	}
}
//dwd