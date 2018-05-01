#include <windows.h>
#include <process.h>
#include <stdio.h>

void gotoxy(int x, int y) {
	COORD CursorPosition;
	CursorPosition.X = x - 1;
	CursorPosition.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}