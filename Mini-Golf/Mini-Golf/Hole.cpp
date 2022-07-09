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

bool Hole::CheckCollision(Ball &ball)
{
	return false;
}