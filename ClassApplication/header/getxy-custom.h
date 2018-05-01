#include <windows.h>
#include <process.h>
#include <stdio.h>

CONSOLE_SCREEN_BUFFER_INFO CSBI;

int getx() {
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI)) return -1;
	return CSBI.dwCursorPosition.X + 1;
}

int gety() {
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI)) return -1;
	return CSBI.dwCursorPosition.Y + 1;
}