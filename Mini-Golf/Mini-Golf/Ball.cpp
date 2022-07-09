#include "Ball.h"

Ball::Ball(int X, int Y, int Radius, Color Color)
{
	posX = X;
	posY = Y;
	radius = Radius;

	color = Color;

	velocity = { 0, 0 };

	velocityOnceReleased = { 0, 0 };
}

void Ball::Draw()
{
	DrawCircle(posX, posY, 10, color);
}

void Ball::Update()
{
	GetVelocity();

	posX += velocity.x * velocityMultiplier * GetFrameTime();
	posY += velocity.y * velocityMultiplier * GetFrameTime();
}

void Ball::GetVelocity()
{
	if (BallIsPressed()) selected = true;

	if (selected)
	{
		color = ORANGE;
		velocityOnceReleased = CalculateVelocity(); //Get the distance between the ball and mouse

		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			velocity = velocityOnceReleased;
			color = WHITE;
			selected = false;
		}
	}
}

bool Ball::BallIsPressed() // Checks if ball is pressed.
{
	if (CheckCollisionPointCircle(Vector2{ (float)GetMousePosition().x, (float)GetMousePosition().y }, Vector2{ (float)posX, (float)posY }, radius) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		return true;
	}
	return false;
}

Vector2 Ball::CalculateVelocity()
{
	float disX = posX - GetMousePosition().x; //Get horizontal distance between mouse and ball
	float disY = posY - GetMousePosition().y; //Get vertical distance between mouse and ball

	//float dis = sqrt(pow(disX, 2) + pow(disY, 2)); // calculate distance using Pythagoreas theorem
	
	return Vector2{disX, disY};
}



