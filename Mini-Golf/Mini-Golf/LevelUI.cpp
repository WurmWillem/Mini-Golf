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

int LevelUI::checkClick()
{
    // If clicked
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        // If column 1
        if (GetMouseX() > 70 && GetMouseX() < 220)
        {
            // If row 1
            if (GetMouseY() > 30 && GetMouseY() < 180) return 1 + page * 12;
            // If row 2
            else if (GetMouseY() > 210 && GetMouseY() < 360) return 2 + page * 12;
            // If row 3
            else if (GetMouseY() > 390 && GetMouseY() < 540) return 3 + page * 12;
            // If row 4
            else if (GetMouseY() > 570 && GetMouseY() < 750) return 4 + page * 12;
        }
        // If column 2
        if (GetMouseX() > 250 && GetMouseX() < 400)
        {
            // If row 1
            if (GetMouseY() > 30 && GetMouseY() < 180) return 5 + page * 12;
            // If row 2
            else if (GetMouseY() > 210 && GetMouseY() < 360) return 6 + page * 12;
            // If row 3
            else if (GetMouseY() > 390 && GetMouseY() < 540) return 7 + page * 12;
            // If row 4
            else if (GetMouseY() > 570 && GetMouseY() < 750) return 8 + page * 12;
        }
        // If column 3
        if (GetMouseX() > 430 && GetMouseX() < 580)
        {
            // If row 1
            if (GetMouseY() > 30 && GetMouseY() < 180) return 9 + page * 12;
            // If row 2
            else if (GetMouseY() > 210 && GetMouseY() < 360) return 10 + page * 12;
            // If row 3
            else if (GetMouseY() > 390 && GetMouseY() < 540) return 11 + page * 12;
            // If row 4
            else if (GetMouseY() > 570 && GetMouseY() < 750) return 12 + page * 12;
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