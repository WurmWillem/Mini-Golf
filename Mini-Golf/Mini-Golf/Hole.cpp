#include "Hole.h"
#include "Ball.h"
#include "raylib.h"

Hole::Hole(float X, float Y, float Radius)
{
	radius = Radius;
	x = X;
	y = Y;
	holePosition = { x, y };
}

void Hole::Draw()
{
	DrawCircle((int) holePosition.x, (int) holePosition.y, radius, BLACK);
}

void Hole::CheckCollision(Ball& ball)
{
	if (CheckCollisionCircles(holePosition, radius, { ball.posX, ball.posY }, ball.radius))
	{
		ball.Shrink();
		ball.posX = (float) GetScreenWidth() / 2.0f;
		ball.posY = 100;;
	}
}