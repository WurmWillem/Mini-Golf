#pragma once
#include "Ball.h"

class Hole
{
public:
	Hole(int Radius);

	void Draw();

	void CheckCollision(Ball& ball);

	bool collided;
private:

	Vector2 holePosition;

	int radius;
};
