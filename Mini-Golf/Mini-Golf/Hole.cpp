#include "Hole.h"
#include "Ball.h"
#include "raylib.h"

Hole::Hole(float Radius)
{
	radius = Radius;
	holePosition = { (float) GetScreenWidth() / 2, 100};
}

void Hole::Draw()
{
	DrawCircle((int) holePosition.x, (int) holePosition.y, radius, BLACK);

	return;
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