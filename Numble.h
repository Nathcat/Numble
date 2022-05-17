#pragma once

#include "resource.h"

#include "framework.h"

#define WINDOW_CLASS_NAME L"Numble"
#define CORRECT_COLOUR RGB(0, 255, 0)
#define INCORRECT_COLOUR RGB(255, 255, 0)
#define NOTINWORD_COLOUR RGB(0, 0, 0)
#define NORMAL_COLOUR RGB(255, 255, 255)

COLORREF** boxStates = new COLORREF * [] {
	new COLORREF[]{ NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR },
	new COLORREF[]{ NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR },
	new COLORREF[]{ NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR },
	new COLORREF[]{ NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR },
	new COLORREF[]{ NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR },
	new COLORREF[]{ NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR, NORMAL_COLOUR },
};

int** boxes = new int * [] {
	new int[]{ NULL, NULL, NULL, NULL },
	new int[]{ NULL, NULL, NULL, NULL },
	new int[]{ NULL, NULL, NULL, NULL },
	new int[]{ NULL, NULL, NULL, NULL },
	new int[]{ NULL, NULL, NULL, NULL },
	new int[]{ NULL, NULL, NULL, NULL },
};

int currentRow = 0;
RECT windowRect;
int correctNumbers[] = {1, 2, 3, 4};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void PaintBoxStates(HWND hWnd, PAINTSTRUCT* ps);
int* GetRowValues(HWND hWnd, int row);
