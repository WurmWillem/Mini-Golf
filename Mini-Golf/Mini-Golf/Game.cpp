#include "raylib.h"
#include "Game.h"

bool Game::Run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Main Game!", 100, 100, 30, WHITE);

        EndDrawing();

    }
	return true;
}

void Game::Update()
{
	return;
}