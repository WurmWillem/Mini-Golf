// ------------------------------------------------------
// Startscreen
//-------------------------------------------------------

#include "raylib.h"
#include "Game.h"
#include "Startscreen.h"

int main()
{
    // Init Window
    InitWindow(650, 800, "Mini-Golf");
    SetTargetFPS(60);

    // Some vars
    Startscreen startscreen;
    Game game;
    bool closeGame = false;

    // Main game loop
    while (!WindowShouldClose() && !closeGame)
    {
        // Begin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw text
        startscreen.DrawWelcomeText();

        // End
        EndDrawing();

        // Onclick start game
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) closeGame = game.Run();

    }

    // End application
    CloseWindow();        

    return 0;
}