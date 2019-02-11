#pragma once
#include <vector>
#include <array>

#include "muro.h"
#include <list>
#include "Bomba.h"
class TanqueJugador


{
public:

	void displayvida();
	TanqueJugador(int,int,int,int,int,int,int,int);
	TanqueJugador(int, int,int);
	TanqueJugador(int, int, int, int,int,int);


	void dibujarTanque(TanqueJugador *);
	void dibujarTanqueAI(std::list<TanqueJugador*>);

	void IniciarDisparo();
	void gotoxy(int,int);
	void EliminarTanque();
	void Disparar(TanqueJugador *,std::list<muro*>,bool *,bool&);

	void DispararAI(std::list<TanqueJugador*>, std::list<muro*>,int &);
	void DispararAI2(std::list<TanqueJugador*>, std::list<muro*>, int &,bool &,int &,int &);

	// Movimiento de tanque
	bool MoverArriba(TanqueJugador *, std::list<muro*>,std::list<Bomba*>);
	bool MoverArribaAI(std::list<TanqueJugador*> , std::list<muro*>,std::list<Bomba*>);

	bool MoverAbajo(TanqueJugador*, std::list<muro*>, std::list<Bomba*>);
	bool MoverAbajoAI(std::list<TanqueJugador*>, std::list<muro*>,std::list<Bomba*>);

	bool MoverIzquierda(TanqueJugador*, std::list<muro*>, std::list<Bomba*>);
	bool MoverIzquierdaAI(std::list<TanqueJugador*>, std::list<muro*>, std::list<Bomba*>);

	bool MoverDerecha(TanqueJugador*,std::list<muro*>, std::list<Bomba*>);
	bool MoverDerechaAI(std::list<TanqueJugador*>, std::list<muro*>,std::list<Bomba*>);


	bool verificarmovimientoFrente(TanqueJugador*);
	bool verificarmovimientoFrenteAI(std::list<TanqueJugador*>);

	bool verificarmovimientoAbajo(TanqueJugador*);
	bool verificarmovimientoAbajoAI(std::list<TanqueJugador*>);

	bool verificarmovimientoIzquierda(TanqueJugador*);
	bool verificarmovientoIzquierdaAI(std::list<TanqueJugador*>);

	bool verificarmovimientoDerecha(TanqueJugador*);
	bool verificarmovimientoDerechaAI(std::list<TanqueJugador*>);

	void iniciarIA(std::list<TanqueJugador*>,std::list<muro*>,int &,int  &,int &, std::list<Bomba*>,bool &);

	int getX();
	int getY();

	void setvida(int);
	void setxvy(int,int);
	
	
	//posicion tanque
	int x, y,vida,xv,yv;

	int ix, iy;

	//victoria
	int vx, vy;
	int direccion;
	int direccionAnte;
	//posicion bala de tanque
	int bx, by;
	bool shooting,ganador;
	//posicion de los enemigos
	int ex, ey;
};

