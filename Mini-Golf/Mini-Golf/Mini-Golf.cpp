// ------------------------------------------------------
// Startscreen
//-------------------------------------------------------

#include "raylib.h"
#include "Game.h"

int main()
{
    // Init Window
    InitWindow(650, 800, "Mini-Golf");
    SetTargetFPS(60);

    // Some vars
    Game game;
    bool closeGame = false;
    Vector2 MousePos;

    // Main game loop
    while (!WindowShouldClose() && !closeGame)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Check if mouse hovers text
        MousePos = GetMousePosition();
        if (MousePos.x > 100 && MousePos.x < MeasureText("Welcome to our Mini-Golf game", 32) + 100 && MousePos.y > 100 && MousePos.y < 180)
        {
            DrawText("Welcome to our Mini-Golf game", 325 - (MeasureText("Welcome to our Mini-Golf game", 32) / 2), 100, 32, DARKGRAY);
            DrawText("Click to continue", 325 - (MeasureText("Click to continue", 32) / 2), 150, 32, DARKGRAY);
        }
        else
        {
            DrawText("Welcome to our Mini-Golf game", 325 - (MeasureText("Welcome to our Mini-Golf game", 26) / 2), 100, 26, LIGHTGRAY);
            DrawText("Click to continue", 325 - (MeasureText("Click to continue", 26) / 2), 150, 26, LIGHTGRAY);
        }

        EndDrawing();

        // Onclick start game
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) closeGame = game.Run();

    }
    CloseWindow();        

    return 0;
}