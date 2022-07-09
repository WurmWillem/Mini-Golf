#pragma once
<<<<<<< Updated upstream
=======
#include "Ball.h"

>>>>>>> Stashed changes
class Hole
{
public:
	Hole(int Radius);

	void Draw();

<<<<<<< Updated upstream
	bool CheckCollision(Ball &ball);
private:

	Vector2 holePosition;
	int radius;
};
=======
	void CheckCollision(Ball& ball);

	bool collided;
private:

	Vector2 holePosition;

	int radius;
};
>>>>>>> Stashed changes
