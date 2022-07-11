#include "Hole.h"

Hole::Hole(float x_, float y_, float radius_)
{
	radius = radius_;
	holePosition = { x_, y_ };
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
		ball.posX = holePosition.x;
		ball.posY = holePosition.y;
	}
}