#include "raylib.h"
#include "Game.cpp"

int main()
{
    InitWindow(650, 800, "Mini-Golf");
    SetTargetFPS(60);              

    // Main game loop
    while (!WindowShouldClose()) 
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        

        EndDrawing();
        
    }
    CloseWindow();        

    return 0;
}