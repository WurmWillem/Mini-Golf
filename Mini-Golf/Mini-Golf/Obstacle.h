#pragma once
#include "raylib.h"

class Obstacle
{
public:
	Obstacle(float X, float Y, float Width, float Height);

	float x, y, width, height;
	Rectangle rect;
	
private:

};