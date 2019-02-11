#include "pch.h"
#include "TanqueEnemigo.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <thread>

char enemigo_l11[] = { ' ',' ',' ', 'I',' ',' ',' ',0 };
char enemigo_l22[] = { ' ','o','|', '-','|','o',' ',0 };
char enemigo_l33[] = { ' ','o','|', '-','|','o',' ',0 };

TanqueEnemigo::TanqueEnemigo(int x, int y)
{
	this->x = x;
	this->y = y;
	this->bx = NULL;
	this->by = NULL;
	this->shooting = false;



}
void TanqueEnemigo::dibujartanque()
{
	gotoxy2(x, y); puts(enemigo_l33);
	gotoxy2(x, y + 1); puts(enemigo_l22);
	gotoxy2(x, y + 2); puts(enemigo_l11);
}

void TanqueEnemigo::gotoxy2(int x, int y)
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

void TanqueEnemigo::Disparar()
{
	if (shooting == false)
	{
		if (true)
		{
			shooting = true;
			this->bx = this->x + 3;
			this->by = this->y + 3;
			
			do {
				gotoxy2(bx, by);
				printf("0");
				Sleep(50);
				gotoxy2(bx, by);
				printf(" ");
				by++;




				if (by > 25)
				{
					by = NULL;
					bx = NULL;
					shooting = false;
					
					break;
				}

				if (by == Y)
				{
					by = NULL;
					bx = NULL;
					shooting = false;
					
					break;
				}


			} while (shooting == true);

		}
		else { }


	}
	else {  }
}
bool TanqueEnemigo::getShooting()
{
	return shooting;
}

void TanqueEnemigo::IniciarDisparo(int X, int Y)
{
	this->X = X;
	this->Y = Y;
	
}
