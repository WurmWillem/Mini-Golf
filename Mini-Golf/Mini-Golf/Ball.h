#pragma once
#include "raylib.h"
#include <iostream>
#include <cmath>

class Ball
{
public:

	Ball(int X, int Y, int Radius, Color Color);

	float posX;
	float posY;

	int radius;

	Vector2 velocity;

	const float velocityMultiplier = 1.8f;

	void UpdatePosition();

	void Draw();

	int GetRadius();

	void Shrink();

private:

	Color color;
	
	Vector2 velocityOnceReleased;

	bool selected = false;

	void GetVelocity();

	bool BallIsPressed();

	Vector2 CalculateVelocity();

	void CheckWallCollision();

	void DecreaseVelocity();
};