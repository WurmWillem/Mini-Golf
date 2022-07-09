#pragma once
class Hole
{
public:
	Hole(int Radius);

	void Draw();

	bool CheckCollision(Ball &ball);
private:

	Vector2 holePosition;
	int radius;
};