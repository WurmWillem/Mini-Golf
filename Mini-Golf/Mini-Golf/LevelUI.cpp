#include "LevelUI.h"

LevelUI::LevelUI()
{
	blockSize = 150;
	blockColor = GRAY;
    page = 0;
}

void LevelUI::AddLevels()
{
    float y = 30;

    for (float rank = 0; rank < 4; rank++) //Vertical row levels
    {
        float x = 70;

        for (float column = 0; column < 3; column++) //Horizontal row levels
        {
            levels.push_back({ x, y, (float) blockSize, (float) blockSize });
            x += 180;
        }
        y += 180;
    }
}

void LevelUI::DrawUI()
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

void LevelUI::DrawScores()
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
}