#include "Obstacle.h"

Obstacle::Obstacle(float X, float Y, float Width, float Height)
{
	x = X;
	y = Y;
	width = Width;
	height = Height;
	rect = { x, y, width, height };
}