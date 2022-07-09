#include "raylib.h"
#include "Game.h"
#include "Ball.h"
#include "Hole.h"

bool Game::Run()
{
    //Initialize components
    Ball ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 10, WHITE); //These arguments are the initial position, radius and color of the ball
    Hole hole(16);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        Update(ball, hole);

        EndDrawing();
    }
	return true;
}

void Game::Update(Ball &ball, Hole &hole)
{
    DrawText("Main Game!", GetScreenWidth() / 3, 140, 30, WHITE);

    hole.Draw();
    hole.CheckCollision(ball);

    ball.Update();
    ball.Draw();
}