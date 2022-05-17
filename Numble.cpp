#include "Numble.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WinProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = WINDOW_CLASS_NAME;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	RegisterClassEx(&wcex);

	HWND hWnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		WINDOW_CLASS_NAME,
		L"Numble",
		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),
		0, 0,
		170, 270,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	windowRect = { 0, 0, 170, 270 };

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	HGDIOBJ original;

	switch (msg) {
	case WM_CREATE:
		// Create the text boxes here
		hdc = BeginPaint(hWnd, &ps);

		for (int row = 0; row < 6; row++) {
			for (int col = 0; col < 4; col++) {
				*((* (boxes + row)) + col) = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 20 + (30 * col), 20 + (30 * row), 20, 20, hWnd, NULL, NULL, NULL);
			}
		}

		CreateWindow(TEXT("button"), TEXT("Submit"), WS_VISIBLE | WS_CHILD, 25, 200, 100, 20, hWnd, (HMENU) 1, NULL, NULL);

		//SelectObject(hdc, original);
		EndPaint(hWnd, &ps);
		break;

	case WM_PAINT:
		PaintBoxStates(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_COMMAND:
		if (LOWORD(wParam) == 1) {
			if (currentRow == 6) {
				PostQuitMessage(0);
				break;
			}

			TCHAR* rowValues = GetRowValues(hWnd, currentRow);
			/*
			*(boxStates + currentRow) = new COLORREF[] {
				DetermineColour(*rowValues, 0),
				DetermineColour(*(rowValues + 1), 1),
				DetermineColour(*(rowValues + 2), 2),
				DetermineColour(*(rowValues + 3), 3),
			};*/
			

			PaintBoxStates(hWnd, &ps);
			InvalidateRect(hWnd, &windowRect, TRUE);
			UpdateWindow(hWnd);
			currentRow++;
		}

		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
		break;
	}
}

void PaintBoxStates(HWND hWnd, PAINTSTRUCT* pPs) {
	HDC hdc = BeginPaint(hWnd, pPs);

	HGDIOBJ original = SelectObject(hdc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(hdc, NORMAL_COLOUR);

	for (int row = 0; row < 6; row++) {
		for (int col = 0; col < 4; col++) {
			COLORREF colour = *((*(boxStates + row)) + col);
			SetDCBrushColor(hdc, colour);

			Rectangle(hdc, 15 + (30 * col), 15 + (30 * row), 45 + (30 * col), 45 + (30 * row));
		}
	}

	SelectObject(hdc, original);
	EndPaint(hWnd, pPs);
}

TCHAR* GetRowValues(HWND hWnd, int row) {
	HWND* rowBoxes = *(boxes + row);

	TCHAR buffer[4];

	for (int i = 0; i < 4; i++) {
		GetWindowText(*(rowBoxes + i), &buffer[i], 1);
	}

	DebugLog(ttos(buffer, 4) + "\n");

	return buffer;
}

bool ListContains(TCHAR number, TCHAR* list, int numberOfElements) {
	for (int i = 0; i < numberOfElements; i++) {
		if (number == *(list + i)) {
			return true;
		}
	}

	return false;
}

COLORREF DetermineColour(TCHAR number, int index) {
	COLORREF result = NULL;

	if (number == correctNumbers[index]) {
		result = CORRECT_COLOUR;  // Green
		return result;
	}
	else if (ListContains(number, correctNumbers, 4)) {
		result = INCORRECT_COLOUR;  // Yellow
		return result;
	}
	else {
		result = NOTINWORD_COLOUR;  // Black
		return result;
	}
}

void DebugLog(std::string message) {
	std::ofstream file("DebugLog.txt");

	file << message;

	file.flush();
	file.close();
}

std::string ttos(TCHAR* message, int numberOfChars) {
	std::string str = "";

	for (int i = 0; i < numberOfChars; i++) {
		str += *(message + i);
	}

	return str;
}