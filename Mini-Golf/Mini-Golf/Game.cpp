#include "raylib.h"
#include "Game.h"
#include "Ball.h"

bool Game::Run()
{
    //Initialize Ball
    Ball ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 10, WHITE); //These arguments are the initial position, radius and color of the ball 

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Main Game!", GetScreenWidth() / 3, 100, 30, WHITE);

        ball.Update();
        ball.Draw();

        EndDrawing();

    }
	return true;
}

void Game::Update()
{
	return;
}