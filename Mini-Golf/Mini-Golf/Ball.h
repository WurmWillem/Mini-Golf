#pragma once
#include "raylib.h"
#include <cmath>

class Ball 
{
public:
	Ball(int X, int Y, int Radius, Color Color);

	void Update();
	void Draw();

private:
	int posX; 
	int posY; 

	int radius;

	Color color;

	Vector2 velocity;

	bool selected = false;

	float distance;

	void GetVelocity();

	bool BallIsPressed();

	float CalculateDistance();
};
