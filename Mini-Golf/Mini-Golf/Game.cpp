#include "Game.h"

bool Game::RunLevel(int level)
{
    LoadLevel(level);
    bool levelCompleted = false;

    while (!WindowShouldClose() && !levelCompleted)
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        levelCompleted = Update();

        EndDrawing();
    }
	return true;
}

bool Game::Update()
{
    // Hole
    holes.at(0).CheckCollision(balls.at(0));
    holes.at(0).Draw();
    
    // Obstacles
    obstacles.Draw();
    obstacles.CheckCollisionObstacles(balls.at(0));

    // Ball
    balls.at(0).UpdatePosition();
    balls.at(0).Draw();
    return balls.at(0).IsBallInHole();
}

void Game::LoadLevel(int level)
{
    std::ifstream lvlFile;
    lvlFile.open("level" + std::to_string(level) + ".txt");

    std::vector<float> values;
    float value;

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
    Hole hole(values.at(3), values.at(4), values.at(5));
    holes.push_back(hole);

    // Load opstacles
    for (int i = 7; i < values.size(); i += 4)
    {
        Obstacle obstacle(values.at(i), values.at(i + 1), values.at(i + 2), values.at(i + 3));
        obstacles.Add(obstacle);
    }
}

bool Game::ShowUI()
{
    LevelUI UI;
    int level;
    UI.AddLevels();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        UI.DrawUI(); /*
        level = UI.checkClick();

        if (level != 0)
        {
            RunLevel(level);
            ResetGame();
        } */
        EndDrawing();
    }

    return true;
}

void Game::ResetGame()
{
    balls.clear();
    holes.clear();
    scores.clear();
    obstacles.Clear();
}