#include "LevelUI.h"

LevelUI::LevelUI()
{
	blockSize = 150;
	blockColor = GRAY;
    page = 0;
}

void LevelUI::DrawUI()
{
    // Levels 1-3
    Rectangle level1 = { 70, 30, blockSize, blockSize };
    DrawRectangleRounded(level1, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level1, 0.15f, 0, 2, BLACK);

    Rectangle level2 = { 250, 30, blockSize, blockSize };
    DrawRectangleRounded(level2, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level2, 0.15f, 0, 2, BLACK);

    Rectangle level3 = { 430, 30, blockSize, blockSize };
    DrawRectangleRounded(level3, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level3, 0.15f, 0, 2, BLACK);

    // Levels 4-6
    Rectangle level4 = { 70, 210, blockSize, blockSize };
    DrawRectangleRounded(level4, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level4, 0.15f, 0, 2, BLACK);

    Rectangle level5 = { 250, 210, blockSize, blockSize };
    DrawRectangleRounded(level5, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level5, 0.15f, 0, 2, BLACK);

    Rectangle level6 = { 430, 210, blockSize, blockSize };
    DrawRectangleRounded(level6, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level6, 0.15f, 0, 2, BLACK);

    // Levels 7-9
    Rectangle level7 = { 70, 390, blockSize, blockSize };
    DrawRectangleRounded(level7, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level7, 0.15f, 0, 2, BLACK);

    Rectangle level8 = { 250, 390, blockSize, blockSize };
    DrawRectangleRounded(level8, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level8, 0.15f, 0, 2, BLACK);

    Rectangle level9 = { 430, 390, blockSize, blockSize };
    DrawRectangleRounded(level9, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level9, 0.15f, 0, 2, BLACK);

    // Levels 10-12
    Rectangle level10 = { 70, 570, blockSize, blockSize };
    DrawRectangleRounded(level10, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level10, 0.15f, 0, 2, BLACK);

    Rectangle level11 = { 250, 570, blockSize, blockSize };
    DrawRectangleRounded(level11, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level11, 0.15f, 0, 2, BLACK);

    Rectangle level12 = { 430, 570, blockSize, blockSize };
    DrawRectangleRounded(level12, 0.1f, 0, blockColor);
    DrawRectangleRoundedLines(level12, 0.15f, 0, 2, BLACK);

    DrawText("JUST PRESS ESC", 50, 100, 30, RED);
    DrawText("THIS WILL BE IMPLEMENTED LATER", 50, 140, 30, RED);
    
}