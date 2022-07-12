#pragma once
#include "raylib.h"
#include <string>
#include <vector>
#include "Game.h"

class LevelUI
{
public:
	LevelUI();

	void DrawUI();

	void DrawLevels();

	void DrawScores();

	int CheckClick();

	std::vector<int> LoadScores();

	std::vector<Rectangle> levels;
private:
	int blockSize;

	Color blockColor;

	int page;
};