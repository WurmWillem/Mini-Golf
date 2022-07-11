#pragma once
#include "Ball.h"

class Hole
{
public:
	Hole(float x_, float y_, float radius_);

	void Draw();

	void CheckCollision(Ball& ball);

private:
	Vector2 holePosition;

	float radius;
};