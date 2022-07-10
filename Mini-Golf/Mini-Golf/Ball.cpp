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
	DrawCircle(posX, posY, radius, color);
}

void Ball::UpdatePosition()
{
	GetVelocity();

	CheckWallCollision();

	posX += round(velocity.x * velocityMultiplier * GetFrameTime());
	posY += round(velocity.y * velocityMultiplier * GetFrameTime());

	DecreaseVelocity();
}

void Ball::GetVelocity()
{
	if (BallIsPressed()) selected = true;

	if (selected && velocity.x == 0 && velocity.y == 0)
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

	return Vector2{ disX, disY };
}

void Ball::CheckWallCollision()
{

	if (posX >= GetScreenWidth() || posX <= 0) 
	{
		velocity.x *= -1;
	}
	if (posY >= GetScreenHeight() || posY <= 0)
	{
		velocity.y *= -1;
	}
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
	
	//std::cout << "X = " << velocity.x / velocity.y << "\n";
	//std::cout << "Y = " << velocity.y << "\n";
}

int Ball::GetX()
{
	return posX;
}

int Ball::GetY()
{
	return posY;
}

int Ball::GetRadius()
{
	return radius;
}

void Ball::Shrink()
{
	radius -= 2;
}

void Ball::SetX(int pos)
{
	posX = pos;
}

void Ball::SetY(int pos)
{
	posY = pos;
}