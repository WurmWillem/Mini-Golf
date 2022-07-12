#include "Ball.h"

Ball::Ball(float X, float Y, float Radius, Color Color)
{
	posX = X;
	posY = Y;
	radius = Radius;

	color = Color;

	velocity = { 0, 0 };

	velocityOnceReleased = { 0, 0 };

	inHole = false;
}

void Ball::Draw()
{
	DrawCircle((int) round(posX), (int) round(posY), radius + 2, BLACK);
	DrawCircle((int) round(posX), (int) round(posY), radius, color);
}

void Ball::UpdatePosition()
{
	GetVelocity();

	CheckWallCollision();

	posX += velocity.x * velocityMultiplier * GetFrameTime();
	posY += velocity.y * velocityMultiplier * GetFrameTime();

	DecreaseVelocity();
}

void Ball::GetVelocity()
{
	if (BallIsPressed() && (velocity.x < 13 && velocity.x > -13) && (velocity.y < 13 && velocity.y > -13)) selected = true;

	if (selected && (velocity.x < 13  && velocity.x > -13) && (velocity.y < 13 && velocity.y > -13))
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
	if (CheckCollisionPointCircle(Vector2{ (float)GetMousePosition().x, (float)GetMousePosition().y }, Vector2{ posX, posY }, radius) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
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

	return Vector2{ disX, disY };
}

void Ball::CheckWallCollision()
{
	if (posX + radius >= GetScreenWidth())
	{
		velocity.x *= -1;
		posX = GetScreenWidth() - radius;
	}
	else if (posX - radius <= 0)
	{
		velocity.x *= -1;
		posX = radius;
	}
	if (posY + radius >= GetScreenHeight())
	{
		velocity.y *= -1;
		posY = GetScreenHeight() - radius;
	}
	else if (posY - radius <= 0)
	{
		velocity.y *= -1;
		posY = radius;
	}
}

void Ball::DecreaseVelocity() 
{
	velocity.x *= 0.958f;
	velocity.y *= 0.958f;
}

void Ball::Shrink()
{
	radius -= 2;
}

bool Ball::IsBallInHole()
{
	if (inHole)
	{
		DrawText("Good job", GetScreenWidth() / 2 - MeasureText("Good job", 40) / 2, 150, 40, DARKBLUE);
		DrawText("Click to continue", GetScreenWidth() / 2 - MeasureText("Click to continue", 40) / 2, 220, 40, DARKBLUE);
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) return true;
	}
	return false;
}