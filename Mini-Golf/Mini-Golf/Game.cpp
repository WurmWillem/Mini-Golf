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
    if (!levelCompleted) endApplication = true;
	return true;
}

bool Game::Update()
{
    // Hole
    holes[0].CheckCollision(balls[0]);
    holes[0].Draw();
    
    // Obstacles
    obstacles.Draw();
    obstacles.CheckCollisionObstacles(balls[0]);

    // Ball
    balls[0].UpdatePosition();
    balls[0].Draw();
    return balls[0].IsBallInHole();
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
    Ball ball(values[0], values[1], values[2], WHITE);
    balls.push_back(ball);
    Hole hole(values[3], values[4], values[5]);
    holes.push_back(hole);

    strokesForPar = values[6];

    // Load opstacles
    for (int i = 7; i < values.size(); i += 4)
    {
        Obstacle obstacle(values[i], values[i + 1], values[i + 2], values[i + 3]);
        obstacles.Add(obstacle);
    }
}

bool Game::ShowUI()
{
    LevelUI UI;
    int level;
    endApplication = false;

    while (!WindowShouldClose() && !endApplication)
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        UI.DrawBlocks(); 
        UI.DrawLevels();
        UI.DrawScores();
        level = UI.CheckClick();
        
        if (level != 0)
        {
            RunLevel(level);
            ResetGame(level);
        } 
        EndDrawing();
    }
    return true;
}

void Game::ResetGame(int level)
{
    SaveScore(level, balls[0]);

    balls.clear();
    holes.clear();
    scores.clear();
    obstacles.Clear();
}

void Game::SaveScore(int level, Ball& ball)
{
    LevelUI levelScore;
    std::vector<float> scores = levelScore.LoadScores();

    if (scores.at(level - 1) < strokesForPar / ball.strokes * 100) scores.at(level - 1) = strokesForPar / ball.strokes * 100;
    scores.at(level - 1) = std::min(100.0f, scores.at(level - 1));

    std::fstream f;
    f.open("Scores.txt", std::ios::out | std::ios::in);
    for (int i = 0; i < scores.size() - 1; i++)
    {
        f << ("%.0f", scores[i]) << "\n";
    }
    f << scores[scores.size() - 1];
    f.close();
}