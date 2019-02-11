#pragma once
class muro
{
public:
	muro(int,int);
	void gotoxy(int, int);
	void dibujarmuro();
	void recibirdano();
	void destruirMuro();

	int x, y;
	int vida;
	bool destruido;
};

