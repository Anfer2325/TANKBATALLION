#include "pch.h"
#include "Bomba.h"
#include <Windows.h>
#include <iostream>

Bomba::Bomba(int x,int y)
{
	this->x = x;
	this->y = y;
}

void Bomba::gotoxy(int X, int Y)
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

void Bomba::Dibujar()
{
	gotoxy(x, y);
	puts("@");
}

void Bomba::ElimarBomba()
{
	gotoxy(x, y);
	puts(" ");
	x = NULL;
	y = NULL;
}
