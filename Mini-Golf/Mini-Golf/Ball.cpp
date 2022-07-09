#include "Ball.h"

Ball::Ball(int X, int Y)
{
	posX = X;
	posY = Y;

	velocity.x = 1;
	velocity.y = 1;
}

void Ball::Draw()
{
	DrawCircle(posX, posY, 10, WHITE);
}

void Ball::Update()
{
	GetVelocity();

	posX += velocity.x;
	posY += velocity.y;
}

void Ball::GetVelocity()
{

}


