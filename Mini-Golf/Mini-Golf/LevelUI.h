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

	int CheckClick();

	void DrawScores();

	std::vector<int> LoadScores();

	std::vector<Rectangle> levels;
private:
	int blockSize;

	Color blockColor;

	int page;
};