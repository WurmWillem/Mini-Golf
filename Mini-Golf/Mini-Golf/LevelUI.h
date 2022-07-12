#pragma once
#include "raylib.h"
#include <string>
#include <iostream>

class LevelUI
{
public:
	LevelUI();

	void DrawUI();

	int checkClick();

private:
	int blockSize;

	Color blockColor;

	int page;
};