#include "LevelUI.h"

LevelUI::LevelUI()
{
	blockSize = 150;
	blockColor = GRAY;
    page = 0;

    for (float row = 0; row < 4; row++) // Rows
    {
        for (float column = 0; column < 3; column++) // Columns
        {
            levels.push_back({ 70 + column * 180, 30 + row * 180, (float) blockSize, (float) blockSize });
        }
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

    for (float row = 0; row < 4; row++) // Rows
    {
        for (float column = 0; column < 3; column++) // Columns
        {
            level++;
            DrawText(TextFormat("Level %i", level), 85 + column * 180, 60 + row * 180, 30, WHITE);
        }
    }
}

void LevelUI::DrawScores()
{
    std::vector<int> scores = LoadScores();

    int i = 0;

    for (float row = 0; row < 4; row++) // Rows
    {
        for (float column = 0; column < 3; column++) // Columns
        {
            DrawText(TextFormat("Score:  %i", scores[i]), 85 + column * 180, 100 + row * 180, 22, WHITE);
            i++;
        }
    }
}