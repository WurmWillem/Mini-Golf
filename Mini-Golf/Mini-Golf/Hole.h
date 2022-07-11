#pragma once
#include "Ball.h"

class Hole
{
public:
	Hole(float Radius);

	void Draw();

	void CheckCollision(Ball& ball);

private:
	Vector2 holePosition;

	float radius;
};