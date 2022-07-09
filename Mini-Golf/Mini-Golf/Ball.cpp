#include "Ball.h"
#include <iostream>

Ball::Ball(int X, int Y, int Radius, Color Color)
{
	posX = X;
	posY = Y;
	radius = Radius;

	color = Color;

	velocity.x = 0;
	velocity.y = 0;
}

void Ball::Draw()
{
	DrawCircle(posX, posY, 10, color);
}

void Ball::Update()
{
	GetVelocity();

	posX += velocity.x;
	posY += velocity.y;
}

void Ball::GetVelocity()
{
	if (BallIsPressed()) selected = true; // Ball is selected
	if (selected)
	{
		color = ORANGE;
		distance = CalculateDistance(); //Get the distance between the ball and mouse
		DrawText("Distance: ", 20, 780, 16, WHITE);
		DrawText(TextFormat("%.2f", distance), 20 + MeasureText("Distance: ", 16), 780, 16, WHITE);
	}
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) selected = false;
}

bool Ball::BallIsPressed() // Checks if ball is pressed.
{
	if (CheckCollisionPointCircle(Vector2{ (float)GetMousePosition().x, (float)GetMousePosition().y }, Vector2{ (float)posX, (float)posY }, radius) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		return true;
	}
	return false;
}

float Ball::CalculateDistance()
{
	float disX = posX - GetMousePosition().x; //Get horizontal distance between mouse and ball
	float disY = posY - GetMousePosition().y; //Get vertical distance between mouse and ball

	float dis = sqrt(pow(disX, 2) + pow(disY, 2)); // calculate distance using Pythagoreas theorem
	
	return dis;
}



