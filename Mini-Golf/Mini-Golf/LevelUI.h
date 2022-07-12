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

	std::vector<int> LoadScores();
private:
	int blockSize;

	Color blockColor;

	int page;
};