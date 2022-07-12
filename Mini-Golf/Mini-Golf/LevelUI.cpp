#include "LevelUI.h"

LevelUI::LevelUI()
{
	blockSize = 150;
	blockColor = GRAY;
    page = 0;

    float y = 30;
    for (float row = 0; row < 4; row++) // Rows
    {
        float x = 70;
        for (float row = 0; row < 3; row++) // Columns
        {
            levels.push_back({ x, y, (float) blockSize, (float) blockSize });
            x += 180;
        }
        y += 180;
    }
}

void LevelUI::DrawBlocks()
{
    for (int i = 0; i < levels.size(); i++)
    {
        DrawRectangleRounded(levels[i], 0.1f, 0, blockColor);
        DrawRectangleRoundedLines(levels[i], 0.15f, 0, 2, BLACK);
    }
}

int LevelUI::CheckClick()
{
    // If clicked
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        for (int i = 0; i < levels.size(); i++)
        {
            if (CheckCollisionPointRec({ (float) GetMouseX(), (float) GetMouseY()}, levels[i]))
            {
                return i + 1 + page * 12;
            }
        }
    }
    return 0;
}

std::vector<int> LevelUI::LoadScores()
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

void LevelUI::DrawLevels()
{
    int level = 0;
    float y = 60;
    for (float row = 0; row < 4; row++) // Rows
    {
        float x = 85;
        for (float row = 0; row < 3; row++) // Columns
        {
            level++;
            DrawText(TextFormat("Level %i", level), x, y, 30, WHITE);
            x += 180;
        }
        y += 180;
    }
}

void LevelUI::DrawScores()
{
    std::vector<int> scores = LoadScores();

    int i = 0;
    float y = 100;
    for (float row = 0; row < 4; row++) // Rows
    {
        float x = 85;
        for (float row = 0; row < 3; row++) // Columns
        {
            DrawText(TextFormat("Score:  %i", scores[i]), x, y, 22, WHITE);
            x += 180;
            i++;
        }
        y += 180;
    }
}