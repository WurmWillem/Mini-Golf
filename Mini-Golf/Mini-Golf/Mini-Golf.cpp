#include "raylib.h"
#include "Game.h"

int main()
{
    InitWindow(650, 800, "Mini-Golf");
    SetTargetFPS(60);

    Game game;
    bool closeGame = false;

    // Main game loop
    while (!WindowShouldClose() && !closeGame)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Startscreen!", 100, 100, 30, BLACK);

        EndDrawing();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) closeGame = game.Run();

    }
    CloseWindow();        

    return 0;
}