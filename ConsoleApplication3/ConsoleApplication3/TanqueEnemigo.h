#pragma once
class TanqueEnemigo
{
public:
	TanqueEnemigo(int,int);
	void Disparar();
	int getX();
	int getY();
	void eliminartanque();
	void dibujartanque();
	void gotoxy2(int,int);
	void IniciarDisparo(int X,int Y);
	bool getShooting();
	int x, y;
	// variables para la detecion del tanque a
	int X, Y;

	//Variables para el movimiento de las balas
	int bx, by;
	bool shooting;
};

