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

HWND boxes[24];

int currentRow = 0;
RECT windowRect;
TCHAR correctNumbers[5] = TEXT("1234");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void PaintBoxStates(HWND hWnd, PAINTSTRUCT* ps);
int GetRowValues(HWND hWnd, int row, TCHAR** pBuffers);
COLORREF DetermineColour(TCHAR number, int index);
void GenerateRandomNumber();
bool ListContains(TCHAR number, TCHAR* list, int numberOfElements);