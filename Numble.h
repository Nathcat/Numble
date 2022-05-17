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

HWND** boxes = new HWND * [] {
	new HWND[]{ NULL, NULL, NULL, NULL },
	new HWND[]{ NULL, NULL, NULL, NULL },
	new HWND[]{ NULL, NULL, NULL, NULL },
	new HWND[]{ NULL, NULL, NULL, NULL },
	new HWND[]{ NULL, NULL, NULL, NULL },
	new HWND[]{ NULL, NULL, NULL, NULL },
};

int currentRow = 0;
RECT windowRect;
TCHAR correctNumbers[5] = _T("1234");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void PaintBoxStates(HWND hWnd, PAINTSTRUCT* ps);
TCHAR* GetRowValues(HWND hWnd, int row);
COLORREF DetermineColour(TCHAR number, int index);
void DebugLog(std::string message);
std::string ttos(TCHAR* message, int numberOfChars);
