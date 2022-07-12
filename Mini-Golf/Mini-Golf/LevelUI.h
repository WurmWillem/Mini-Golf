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

	int checkClick();

	void DrawScores();

	void AddLevels();

	std::vector<int> LoadScores();

	std::vector<Rectangle> levels;
private:
	int blockSize;

	Color blockColor;

	int page;
};