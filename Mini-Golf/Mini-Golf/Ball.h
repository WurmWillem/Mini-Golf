#pragma once
#include "raylib.h"
#include <iostream>
#include <cmath>

class Ball
{
public:
	Ball(int X, int Y, int Radius, Color Color);

	void UpdatePosition();

	void Draw();

	int GetX();

	int GetY();

	int GetRadius();

	void Shrink();

	void SetX(int pos);

	void SetY(int pos);

private:

	int posX;
	int posY;

	int radius;

	Color color;

	Vector2 velocity;
	Vector2 velocityOnceReleased;

	const float velocityMultiplier = 1.8f;

	bool selected = false;

	void GetVelocity();

	bool BallIsPressed();

	Vector2 CalculateVelocity();

	void CheckWallCollision();

	void DecreaseVelocity();
};