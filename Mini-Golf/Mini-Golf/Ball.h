#pragma once
#include "raylib.h"

class Ball 
{
public:
	Ball(int X, int Y);
	void Update();
	void Draw();

private:
	int posX; 
	int posY; 

	Vector2 velocity;

	void GetVelocity();
};
