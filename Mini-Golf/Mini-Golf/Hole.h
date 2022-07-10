#pragma once
#include "Ball.h"

class Hole
{
public:
	Hole(int Radius);

	void Draw();

	void CheckCollision(Ball& ball);

private:
	Vector2 holePosition;

	int radius;
};
