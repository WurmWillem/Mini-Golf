#include "Game.h"
#include "raylib.h"

bool Game::Run()
{
    //Initialize components
    Ball ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 10, WHITE); //These arguments are the initial position, radius and color of the ball
    Hole hole(16);

    LoadLevel(1);

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

    hole.CheckCollision(ball);
    hole.Draw();

    ball.Draw();
    ball.UpdatePosition();
}

void Game::LoadLevel(int level)
{
    std::ifstream lvlFile;
    lvlFile.open("level1.txt");

    std::vector<int> values;
    int value;

    while ( lvlFile )
    {
        lvlFile >> value;
        values.push_back(value);
    }
    values.pop_back();

    Ball ball(values.at(0), values.at(1), values.at(2), WHITE);
    balls.push_back(ball);
    Hole hole(values.at(3));
    holes.push_back(hole);

}