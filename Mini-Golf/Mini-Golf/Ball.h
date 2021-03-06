#pragma once
#include "raylib.h"
#include <iostream>
#include <cmath>

class Ball
{
public:

	Ball(float X, float Y, float Radius, Color Color);

	float posX;
	float posY;

	float radius;

	Vector2 velocity;

	const float velocityMultiplier = 2.7f;

	void UpdatePosition();

	void Draw();

	void Shrink();

	bool IsBallInHole();

	bool inHole;

	int strokes;

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