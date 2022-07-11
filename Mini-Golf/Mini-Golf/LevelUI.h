#pragma once
#include "raylib.h"

class LevelUI
{
public:
	LevelUI();

	void DrawUI();

private:
	int blockSize;

	Color blockColor;
};