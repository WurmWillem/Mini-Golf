#include "Game.h"
#include "raylib.h"

bool Game::RunLevel(int level)
{
    LoadLevel(level);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        Update();

        EndDrawing();
    }
	return true;
}

void Game::Update()
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
    std::vector<std::string> possibleScores = {
        "no score",
        "hole-in-one",
        "double eagle",
        "eagle",
        "birdie",
        "par",
        "bogey",
        "double bogey",
        "triple bogey"
    };
    std::vector<int> scores = LoadScores();

    for (int i = 0; i < scores.size(); i++)
    {
        std::cout << "Level " << i + 1 << ": " << possibleScores[scores[i]] << "\n";
    }

    RunLevel(1);

    return true;
}

std::vector<int> Game::LoadScores()
{
    

    std::ifstream scoreFile;
    scoreFile.open("Scores.txt");

    std::vector<int> scores;
    int score;

    // Read values from file
    while (scoreFile)
    {
        // Values to Vector
        scoreFile >> score;
        scores.push_back(score);
    }
    scores.pop_back();

    return scores;
}