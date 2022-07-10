#include "Obstacle.h"

Obstacle::Obstacle(float X, float Y, float Width, float Height)
{
	x = X;
	y = Y;
	width = Width;
	height = Height;
	rect = { (float)x, (float)y, (float)width, (float)height };
}