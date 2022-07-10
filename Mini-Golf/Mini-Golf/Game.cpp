#include "Game.h"
#include "raylib.h"

bool Game::Run()
{
    LoadLevel(1);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        Update();

        EndDrawing();
    }
	return true;
}

void Game::Update()
{
    DrawText("Main Game!", GetScreenWidth() / 3, 140, 30, WHITE);

    // Hole
    holes.at(0).CheckCollision(balls.at(0));
    holes.at(0).Draw();
    
    // Obstacles
    obstacles.Draw();
    obstacles.CheckCollisionObstacles(balls.at(0));

    // Ball
    balls.at(0).Draw();
    balls.at(0).UpdatePosition();
}

void Game::LoadLevel(int level)
{
    std::ifstream lvlFile;
    lvlFile.open("level1.txt");

    std::vector<int> values;
    int value;

    // Read values from file
    while ( lvlFile )
    {
        // Values to Vector
        lvlFile >> value;
        values.push_back(value);
    }
    values.pop_back();

    // Load Ball + Hole
    Ball ball(values.at(0), values.at(1), values.at(2), WHITE);
    balls.push_back(ball);
    Hole hole(values.at(3));
    holes.push_back(hole);

    // Load opstacles
    for (int i = 4; i < values.size(); i += 4)
    {
        Obstacle obstacle(values.at(i), values.at(i + 1), values.at(i + 2), values.at(i + 3));
        obstacles.Add(obstacle);
    }
}