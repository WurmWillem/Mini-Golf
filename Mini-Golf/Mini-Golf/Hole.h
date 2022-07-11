#pragma once
#include "Ball.h"

class Hole
{
public:
	Hole(float X, float Y, float Radius);

	void Draw();

	void CheckCollision(Ball& ball);

private:
	Vector2 holePosition;

	float x;
	float y;
	float radius;
};