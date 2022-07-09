#include "Hole.h"
#include "Ball.h"
#include "raylib.h"

Hole::Hole(int Radius)
{
	radius = Radius;
	holePosition = { (float) GetScreenWidth() / 2, 100};
	holePosition = { (float)GetScreenWidth() / 2, 100 };
	collided = false;
}

void Hole::Draw()
{
	DrawCircle(holePosition.x, holePosition.y, radius, BLACK);

	return;
}

void Hole::CheckCollision(Ball& ball)
{
	if (CheckCollisionCircles(holePosition, radius, { (float)ball.GetX(), (float)ball.GetY() }, ball.GetRadius())) collided = true;
}