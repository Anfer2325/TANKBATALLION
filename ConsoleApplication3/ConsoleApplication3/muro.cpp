#include "pch.h"
#include "muro.h"
#include <windows.h>
#include <iostream>


muro::muro(int x, int y)
{
	this->x = x;
	this->y = y;
	this->vida = 3;
	this->destruido = false;
}

void muro::gotoxy(int X, int Y)
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

void muro::dibujarmuro()
{
	gotoxy(x, y);
	puts("#");
}

void muro::recibirdano()
{
	vida--;
	gotoxy(23, 5);
	std::cout << vida;

}

void muro::destruirMuro()
{
	
	if (vida <= 0)
	{
		gotoxy(x, y);
		puts(" ");
		this->destruido = true;
	}
}



