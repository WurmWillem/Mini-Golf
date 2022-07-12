#pragma once
#include "raylib.h"
#include <string>

class LevelUI
{
public:
	LevelUI();

	void DrawUI();

private:
	int blockSize;

	Color blockColor;

	int page;
};