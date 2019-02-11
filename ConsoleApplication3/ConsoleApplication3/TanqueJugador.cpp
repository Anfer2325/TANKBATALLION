#include "pch.h"
#include "TanqueJugador.h"
#include <iostream>
#include <vector>
#include "muro.h"
#include <Windows.h>
#include <thread>

using namespace std;

//direccion
// 1 = Arriba
// 2 = Abajo
// 3 = Izquierda
// 4 = Derecha
char a = (char) 987;
//char TanqueJugador_l1[] = { ' ',' ',' ', I,' ',' ',' ',0 };
//char TanqueJugador_l2[] = { ' ','o','|', '-','|','o',' ',0 };
//char TanqueJugador_l3[] = { ' ','o','|', '-','|','o',' ',0 };

char TanqueJugador_l1[] = {' ',' ','^','^',0 };
char TanqueJugador_l2[] = {' ',a,a,a,a,0 };
char TanqueJugador_l3[] = {' ',a,a,a,a,0 };

char TanqueJugador_Izquieda1[] = { ' ',' ',' ',' ',0 };
char TanqueJugador_Izquieda2[] = { '<',a,a,a,a,0 };
char TanqueJugador_Izquieda3[] = { '<',a,a,a,a,0 };

char TanqueJugador_Derecha1[] = { ' ',' ',' ',' ',0 };
char TanqueJugador_Derecha2[] = { a,a,a,a,'>',0 };
char TanqueJugador_Derecha3[] = { a,a,a,a,'>',0 };




//char TanqueJugador_Izquieda1[] = { ' ',' ',' ' ,0};
//char TanqueJugador_Izquieda2[] = { ' ','o','o' ,0 };
//char TanqueJugador_Izquieda3[] = { ' ','-','-' ,0 };
//char TanqueJugador_Izquieda4[] = { '-','I','I' ,0 };
//char TanqueJugador_Izquieda5[] = { ' ','-','-' ,0 };
//char TanqueJugador_Izquieda6[] = { ' ','o','o' ,0 };
//char TanqueJugador_Izquieda7[] = { ' ',' ',' ' ,0 };
//char TanqueJugador_Derecha4[] =  { ' ','I','-' ,0 };

char borrar_avion[] = { ' ',' ',' ',' ',' ',0 };

void TanqueJugador::dibujarTanqueAI(std::list<TanqueJugador*> jugadores)
{

	if (direccion == 1) {
		switch (direccionAnte)
		{
		case 1:
			//termiando

			if (verificarmovimientoFrenteAI(jugadores))
			{
				y--;
				gotoxy(x, y + 1); puts(borrar_avion);

				gotoxy(x, y); puts(TanqueJugador_l3);
				gotoxy(x, y - 1); puts(TanqueJugador_l2);
				gotoxy(x, y - 2); puts(TanqueJugador_l1);
			}


			break;

		case 2:
			//terminado
			gotoxy(x, y + 1); puts(borrar_avion);

			gotoxy(x, y); puts(TanqueJugador_l3);
			gotoxy(x, y - 1); puts(TanqueJugador_l2);
			gotoxy(x, y - 2); puts(TanqueJugador_l1);
			break;

		case 3:
			//gotoxy(x, y + 3); puts(borrar_avion);
			gotoxy(x, y + 1); puts(borrar_avion);


			gotoxy(x, y); puts(TanqueJugador_l3);
			gotoxy(x, y - 1); puts(TanqueJugador_l2);
			gotoxy(x, y - 2); puts(TanqueJugador_l1);
			break;

		case 4:
			//ERROR DE DERECHA A ARRIBA
			gotoxy(x + 1, y - 1); puts(borrar_avion);
			gotoxy(x + 1, y); puts(borrar_avion);


			gotoxy(x, y); puts(TanqueJugador_l3);
			gotoxy(x, y - 1); puts(TanqueJugador_l2);
			gotoxy(x, y - 2); puts(TanqueJugador_l1);

			break;
		}
	}

	if (direccion == 2)
	{
		switch (direccionAnte)
		{

		case 1:
			//terminado
			gotoxy(x, y - 1); puts(borrar_avion);
			gotoxy(x, y - 2); puts(borrar_avion);


			gotoxy(x, y - 1); puts(TanqueJugador_l3);
			gotoxy(x, y); puts(TanqueJugador_l2);
			gotoxy(x, y + 1); puts(TanqueJugador_l1);
			break;

		case 2:

			if (verificarmovimientoAbajoAI(jugadores))
			{
				//termiando
				y++;
				gotoxy(x, y - 2); puts(borrar_avion);

				gotoxy(x, y - 1); puts(TanqueJugador_l3);
				gotoxy(x, y); puts(TanqueJugador_l2);
				gotoxy(x, y + 1); puts(TanqueJugador_l1);
			}
			break;

		case 3:
			//gotoxy(x, y + 3); puts(borrar_avion);
			//gotoxy(x, y + 2); puts(borrar_avion);

			gotoxy(x, y - 1); puts(TanqueJugador_l3);
			gotoxy(x, y); puts(TanqueJugador_l2);
			gotoxy(x, y + 1); puts(TanqueJugador_l1);

			break;

		case 4:
			gotoxy(x + 1, y); puts(borrar_avion);
			gotoxy(x + 1, y - 1); puts(borrar_avion);

			gotoxy(x, y - 1); puts(TanqueJugador_l3);
			gotoxy(x, y); puts(TanqueJugador_l2);
			gotoxy(x, y + 1); puts(TanqueJugador_l1);

			break;
		}
	}

	if (direccion == 3)
	{
		switch (direccionAnte)
		{
		case 1:
			//terminado
			gotoxy(x, y - 2); puts(borrar_avion);

			gotoxy(x, y); puts(TanqueJugador_Izquieda2);
			gotoxy(x, y - 1); puts(TanqueJugador_Izquieda3);
			break;

		case 2:
			//termiando
			gotoxy(x, y + 1); puts(borrar_avion);

			gotoxy(x, y); puts(TanqueJugador_Izquieda2);
			gotoxy(x, y - 1); puts(TanqueJugador_Izquieda3);
			break;

		case 3:
			//terminado

			if (verificarmovientoIzquierdaAI(jugadores))
			{
				gotoxy(x, y); puts(borrar_avion);
				gotoxy(x, y - 1); puts(borrar_avion);
				x--;
				gotoxy(x, y); puts(TanqueJugador_Izquieda2);
				gotoxy(x, y - 1); puts(TanqueJugador_Izquieda3);
			}
			break;
		case 4:
			//terminado
			gotoxy(x + 1, y); puts(borrar_avion);
			gotoxy(x + 1, y - 1); puts(borrar_avion);


			gotoxy(x, y); puts(TanqueJugador_Izquieda2);
			gotoxy(x, y - 1); puts(TanqueJugador_Izquieda3);

			break;
		}
	}

	if (direccion == 4)
	{
		switch (direccionAnte)
		{
		case 1:

			//terminado
			gotoxy(x, y - 2); puts(borrar_avion);

			gotoxy(x + 1, y); puts(TanqueJugador_Derecha2);
			gotoxy(x + 1, y - 1); puts(TanqueJugador_Derecha3);
			break;

		case 2:
			//termiando
			gotoxy(x, y + 1); puts(borrar_avion);

			gotoxy(x + 1, y); puts(TanqueJugador_Derecha2);
			gotoxy(x + 1, y - 1); puts(TanqueJugador_Derecha3);
			break;

		case 3:
			gotoxy(x, y); puts(borrar_avion);
			gotoxy(x, y - 1); puts(borrar_avion);

			gotoxy(x + 1, y); puts(TanqueJugador_Derecha2);
			gotoxy(x + 1, y - 1); puts(TanqueJugador_Derecha3);
			break;

		case 4:

			if (verificarmovimientoDerechaAI(jugadores))
			{
				gotoxy(x, y); puts(borrar_avion);
				gotoxy(x, y - 1); puts(borrar_avion);
				x++;

				gotoxy(x + 1, y); puts(TanqueJugador_Derecha2);
				gotoxy(x + 1, y - 1); puts(TanqueJugador_Derecha3);
				break;
			}
		}
	}
	/*gotoxy(x, y); cout << y;
	gotoxy(x, y - 1); cout << x;*/



}
bool TanqueJugador::MoverAbajoAI(std::list<TanqueJugador*>jugadores, list<muro*>muros, std::list<Bomba*>bombas)
{
	direccionAnte = direccion;
	direccion = 2;
	bool obstaculo = false;
	

	for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

		if (((*it)->x >= x && (*it)->x <= x + 5 && y + 2 == (*it)->y) && (*it)->destruido == false)
		{
			obstaculo = true;
			break;
		}

	}

	for (std::list<Bomba*>::iterator it = bombas.begin(); it != bombas.end(); ++it) {

		if (((*it)->x >= x && (*it)->x <= x + 5 && y + 2 == (*it)->y))
		{
			obstaculo = true;
			EliminarTanque();
			vida--;
			(*it)->ElimarBomba();
			return true;
			break;
		}

	}

	if (!obstaculo)
	{
		dibujarTanqueAI(jugadores);
	}
	return false;
}

bool TanqueJugador::MoverIzquierdaAI(std::list<TanqueJugador*>jugadores, list<muro*>muros, std::list<Bomba*>bombas)
{

	direccionAnte = direccion;
	direccion = 3;
	bool obstaculo = false;


	for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

		if (((*it)->y >= y - 2 && (*it)->y <= y + 1 && x - 1 == (*it)->x) && (*it)->destruido == false)
		{
			obstaculo = true;
			break;
		}

	}

	for (std::list<Bomba*>::iterator it = bombas.begin(); it != bombas.end(); ++it) {

		if (((*it)->y >= y - 2 && (*it)->y <= y + 1 && x - 1 == (*it)->x))
		{
			obstaculo = true;
			EliminarTanque();
			vida--;
			(*it)->ElimarBomba();
			return true;
			break;
		}

	}

	if (!obstaculo) {
		dibujarTanqueAI(jugadores);
	}
	return false;
}

bool TanqueJugador::MoverDerechaAI(std::list<TanqueJugador*>jugadores, list<muro*>muros,std::list<Bomba*>bombas)
{
	direccionAnte = direccion;
	direccion = 4;
	bool obstaculo = false;


	for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

		if (((*it)->y >= y - 2 && (*it)->y <= y + 1 && x + 6 == (*it)->x) && (*it)->destruido == false)
		{
			obstaculo = true;
			break;
		}

	}

	for (std::list<Bomba*>::iterator it = bombas.begin(); it != bombas.end(); ++it) {


		if (((*it)->y >= y - 2 && (*it)->y <= y + 1 && x + 6 == (*it)->x))
		{
			obstaculo = true;
			EliminarTanque();
			vida--;
			(*it)->ElimarBomba();
			return true;
			break;
		}

	}

	if (!obstaculo) {
		dibujarTanqueAI(jugadores);
	}
	return false;
}
void TanqueJugador::DispararAI(std::list<TanqueJugador*>jugadores, list<muro*>muros,int &restantes)
{
	std::list<TanqueJugador*>::iterator it = jugadores.begin();

	int *restante = &restantes;
	

	TanqueJugador *jugador1 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador2 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador3 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador4 = &**it;

	if (!shooting) {


		shooting = true;
		if (direccion == 1) {
			bx = x + 3;
			by = y - 3;
			bool toquearriba = false;

			do {
		
				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx && (*it)->y == by - 1) && (*it)->destruido == false)
					{
						toquearriba = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
					}

				}
				if (!toquearriba) {
					gotoxy(bx, by);
					printf("\b 0");
					Sleep(150);
					gotoxy(bx, by);
					printf(" ");
					by--;


					if ((bx > (*jugador1).x && bx < (*jugador1).x + 6 && by == (*jugador1).y + 1))
					{
						(*jugador1).EliminarTanque();
						(*jugador1).vida--;

						

						
						
						if ((*jugador1).vida > 0) {

							(*jugador1).displayvida();

						}
						else {
							gotoxy(((*jugador1).xv), (*jugador1).yv);
							cout << "PERDISTE     ";
							this->ganador = true;
							Sleep(500);
							gotoxy(50, 13);
							cout << "FIN DEL JUEGO";

						}

						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (bx == (*jugador1).vx && by - 1 == (*jugador1).vy)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						this->ganador = true;
						(*jugador1).vida = 0;

						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}


					if ((bx > (*jugador2).x && bx < (*jugador2).x + 6 && by == (*jugador2).y + 1))
					{
						(*jugador2).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta<<"   ";
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;



					}


					if ((bx > (*jugador3).x && bx < (*jugador3).x + 6 && by == (*jugador3).y + 1))
					{
						(*jugador3).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}


					if ((bx > (*jugador4).x && bx < (*jugador4).x + 6 && by == (*jugador4).y + 1))
					{
						(*jugador4).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by == 0)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						break;
					}
				}
				if (restante <= 0)
				{
				
				}
			} while (shooting == true);
		}

		if (direccion == 2)
		{
			bx = x + 3;
			by = y + 3;
			bool toqueabajo = false;
			do {

				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx && (*it)->y == by + 1) && (*it)->destruido == false)
					{
						toqueabajo = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
					}

				}

				if (!toqueabajo)
				{
					gotoxy(bx, by);
					printf("\b 0");
					Sleep(150);
					gotoxy(bx, by);
					printf(" ");
					by++;

					if ((bx > (*jugador1).x && bx < (*jugador1).x + 6 && by == (*jugador1).y + 1))
					{
						(*jugador1).EliminarTanque();
						(*jugador1).vida--;
						
						if ((*jugador1).vida > 0) {

							(*jugador1).displayvida();

						}
						else {
							gotoxy(((*jugador1).xv), (*jugador1).yv);
							cout << "PERDISTE     ";
							this->ganador = true;
							Sleep(500);
							gotoxy(50, 13);
							cout << "FIN DEL JUEGO";

						}

						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (bx == (*jugador1).vx && by + 1 == (*jugador1).vy)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						(*jugador1).vida = 0;

						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}

					if ((bx > (*jugador2).x && bx < (*jugador2).x + 6 && by == (*jugador2).y + 1))
					{
						(*jugador2).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if ((bx > (*jugador3).x && bx < (*jugador3).x + 6 && by == (*jugador3).y + 1))
					{
						(*jugador3).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if ((bx > (*jugador4).x && bx < (*jugador4).x + 6 && by == (*jugador4).y + 1))
					{
						(*jugador4).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by == 0 || by == 29)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						break;
					}
				}
				if (restante <= 0)
				{
					
				}
			} while (shooting == true);


		}
		if (direccion == 3)
		{
			bx = x - 3;
			by = y;
			bool toqueizquierda = false;
			do {
				

				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx - 1 && (*it)->y == by) && (*it)->destruido == false)
					{
						toqueizquierda = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
					}

				}

				if (!toqueizquierda) {
					gotoxy(bx, by);
					printf("\b 0");
					Sleep(150);
					gotoxy(bx, by);
					printf(" ");
					bx--;

					if (by <= (*jugador1).y&&by >= (*jugador1).y - 1 && bx - 4 == (*jugador1).x)
					{
						(*jugador1).EliminarTanque();
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (bx - 1 == (*jugador1).vx && by == (*jugador1).vy)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						(*jugador1).vida = 0;

						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}

					if (by <= (*jugador2).y&&by >= (*jugador2).y - 1 && bx - 4 == (*jugador2).x)
					{
						(*jugador2).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by <= (*jugador3).y&&by >= (*jugador3).y - 1 && bx - 4 == (*jugador3).x)
					{
						(*jugador3).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by <= (*jugador4).y&&by >= (*jugador4).y - 1 && bx - 4 == (*jugador4).x)
					{
						(*jugador4).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}


					if (bx == 0 || bx == 119)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						break;
					}
				}
				if (restante <= 0)
				{
					
				}
			} while (shooting == true);


		}

		if (direccion == 4)
		{
			bx = x + 6;
			by = y;

			bool toquederecha = false;

			do {
			
				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx + 1 && (*it)->y == by) && (*it)->destruido == false)
					{
						toquederecha = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
					}

				}

				if (!toquederecha)
				{
					gotoxy(bx, by);
					printf("\b 0");
					Sleep(150);
					gotoxy(bx, by);
					printf(" ");
					bx++;

					if (by <= (*jugador1).y&&by >= (*jugador1).y - 1 && bx + 1 == (*jugador1).x)
					{
						(*jugador1).EliminarTanque();
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}
					if (bx + 1 == (*jugador1).vx && by == (*jugador1).vy)
					{
						by = NULL;
						bx = NULL;
						(*jugador1).vida = 0;
						shooting = false;
						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}

					if (by <= (*jugador2).y&&by >= (*jugador2).y - 1 && bx + 1 == (*jugador2).x)
					{
						(*jugador2).EliminarTanque();
						(*restante)--;
					
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by <= (*jugador3).y&&by >= (*jugador3).y - 1 && bx + 1 == (*jugador3).x)
					{
						(*jugador3).EliminarTanque();
						
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						(*restante)--;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by <= (*jugador4).y&&by >= (*jugador4).y - 1 && bx + 1 == (*jugador4).x)
					{
						(*jugador4).EliminarTanque();
						(*restante)--;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}


					if (bx == 0 || bx == 119)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						break;
					}
				}
				if (restante <= 0)
				{
					
				}
			} while (shooting == true);

		}
	}

}
void TanqueJugador::DispararAI2(std::list<TanqueJugador*>jugadores, list<muro*>muros, int &restantes,bool &disparo,int &puntuacionxtank,int &puntuacion)
{
	bool *disparar = &disparo;
	int *puntua = &puntuacion;
	int *puntos = &puntuacionxtank;
	if (*disparar==false)
	{
		(*disparar) = true;
	
	std::list<TanqueJugador*>::iterator it = jugadores.begin();

	int *restante = &restantes;

	TanqueJugador *jugador1 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador2 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador3 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador4 = &**it;

	if (!shooting) {


		shooting = true;
		if (direccion == 1) {
			bx = x + 3;
			by = y - 3;
			bool toquearriba = false;

			do {

				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx && (*it)->y == by - 1) && (*it)->destruido == false)
					{
						toquearriba = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
						(*disparar) = false;
					}

				}
				if (!toquearriba) {
					gotoxy(bx, by);
					printf("\b 0");
					Sleep(150);
					gotoxy(bx, by);
					printf(" ");
					by--;


					if ((bx > (*jugador1).x && bx < (*jugador1).x + 6 && by == (*jugador1).y + 1))
					{
						(*jugador1).EliminarTanque();
						(*jugador1).vida--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;



						if ((*jugador1).vida > 0) {

							(*jugador1).displayvida();

						}
						else {
							gotoxy(((*jugador1).xv), (*jugador1).yv);
							cout << "PERDISTE     ";
							this->ganador = true;
							Sleep(500);
							gotoxy(50, 13);
							cout << "FIN DEL JUEGO";

						}

						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (bx == (*jugador1).vx && by - 1 == (*jugador1).vy)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						this->ganador = true;
						(*jugador1).vida = 0;

						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}


					if ((bx > (*jugador2).x && bx < (*jugador2).x + 6 && by == (*jugador2).y + 1))
					{
						(*jugador2).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta << "   ";
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;



					}


					if ((bx > (*jugador3).x && bx < (*jugador3).x + 6 && by == (*jugador3).y + 1))
					{
						(*jugador3).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}


					if ((bx > (*jugador4).x && bx < (*jugador4).x + 6 && by == (*jugador4).y + 1))
					{
						(*jugador4).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by == 0)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						(*disparar) = false;
						break;
					}
				}
				if (restante <= 0)
				{

				}
			} while (shooting == true);
		}
		}

		if (direccion == 2)
		{
			bx = x + 3;
			by = y + 3;
			bool toqueabajo = false;
			do {

				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx && (*it)->y == by + 1) && (*it)->destruido == false)
					{
						toqueabajo = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
						(*disparar) = false;
					}

				}

				if (!toqueabajo)
				{
					gotoxy(bx, by);
					printf("\b 0");
					Sleep(150);
					gotoxy(bx, by);
					printf(" ");
					by++;

					if ((bx > (*jugador1).x && bx < (*jugador1).x + 6 && by == (*jugador1).y + 1))
					{
						(*jugador1).EliminarTanque();
						(*jugador1).vida--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;

						if ((*jugador1).vida > 0) {

							(*jugador1).displayvida();

						}
						else {
							gotoxy(((*jugador1).xv), (*jugador1).yv);
							cout << "PERDISTE     ";
							this->ganador = true;
							Sleep(500);
							gotoxy(50, 13);
							cout << "FIN DEL JUEGO";

						}

						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (bx == (*jugador1).vx && by + 1 == (*jugador1).vy)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						(*jugador1).vida = 0;

						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}

					if ((bx > (*jugador2).x && bx < (*jugador2).x + 6 && by == (*jugador2).y + 1))
					{
						(*jugador2).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if ((bx > (*jugador3).x && bx < (*jugador3).x + 6 && by == (*jugador3).y + 1))
					{
						(*jugador3).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if ((bx > (*jugador4).x && bx < (*jugador4).x + 6 && by == (*jugador4).y + 1))
					{
						(*jugador4).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by == 0 || by == 29)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						shooting = false;
						break;
					}
				}
				if (restante <= 0)
				{

				}
			} while (shooting == true);


		}
		if (direccion == 3)
		{
			bx = x - 3;
			by = y;
			bool toqueizquierda = false;
			do {


				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx - 1 && (*it)->y == by) && (*it)->destruido == false)
					{
						toqueizquierda = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
						(*disparar) = false;
					}

				}

				if (!toqueizquierda) {
					gotoxy(bx, by);
					printf("\b 0");
					Sleep(150);
					gotoxy(bx, by);
					printf(" ");
					bx--;

					if (by <= (*jugador1).y&&by >= (*jugador1).y - 1 && bx - 4 == (*jugador1).x)
					{
						(*jugador1).EliminarTanque();
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (bx - 1 == (*jugador1).vx && by == (*jugador1).vy)
					{
						by = NULL;
						bx = NULL;
						shooting = false;
						(*jugador1).vida = 0;

						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}

					if (by <= (*jugador2).y&&by >= (*jugador2).y - 1 && bx - 4 == (*jugador2).x)
					{
						(*jugador2).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by <= (*jugador3).y&&by >= (*jugador3).y - 1 && bx - 4 == (*jugador3).x)
					{
						(*jugador3).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by <= (*jugador4).y&&by >= (*jugador4).y - 1 && bx - 4 == (*jugador4).x)
					{
						(*jugador4).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}


					if (bx == 0 || bx == 119)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						shooting = false;
						break;
					}
				}
				if (restante <= 0)
				{

				}
			} while (shooting == true);


		}

		if (direccion == 4)
		{
			bx = x + 6;
			by = y;

			bool toquederecha = false;

			do {

				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx + 1 && (*it)->y == by) && (*it)->destruido == false)
					{
						toquederecha = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
						(*disparar) = false;
					}

				}

				if (!toquederecha)
				{
					gotoxy(bx, by);
					printf("\b 0");
					Sleep(150);
					gotoxy(bx, by);
					printf(" ");
					bx++;

					if (by <= (*jugador1).y&&by >= (*jugador1).y - 1 && bx + 1 == (*jugador1).x)
					{
						(*jugador1).EliminarTanque();
						(*disparar) = false;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}
					if (bx + 1 == (*jugador1).vx && by == (*jugador1).vy)
					{
						by = NULL;
						bx = NULL;
						(*jugador1).vida = 0;
						shooting = false;
						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}

					if (by <= (*jugador2).y&&by >= (*jugador2).y - 1 && bx + 1 == (*jugador2).x)
					{
						(*jugador2).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;

						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by <= (*jugador3).y&&by >= (*jugador3).y - 1 && bx + 1 == (*jugador3).x)
					{
						(*jugador3).EliminarTanque();
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;

						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						(*restante)--;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by <= (*jugador4).y&&by >= (*jugador4).y - 1 && bx + 1 == (*jugador4).x)
					{
						(*jugador4).EliminarTanque();
						(*restante)--;
						(*puntua) += (*puntos);
						gotoxy(80, 0);
						cout << "PUNTUACION : " << (*puntua);
						(*disparar) = false;
						int resta = *restante;
						gotoxy(17, 0);
						cout << "Enemigos restantes: " << resta;
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}


					if (bx == 0 || bx == 119)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						shooting = false;
						break;
					}
				}
				if (restante <= 0)
				{

				}
			} while (shooting == true);

		}
	}

}
bool TanqueJugador::MoverArribaAI(std::list<TanqueJugador*>jugadores, list<muro*>muros, list<Bomba*> bombas)
{


	direccionAnte = direccion;
	direccion = 1;
	bool obstaculo = false;




	

	for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

		if (((*it)->x >= x && (*it)->x <= x + 5 && y - 3 == (*it)->y) && (*it)->destruido == false)
		{
			obstaculo = true;
			break;
		}

	}

	for (std::list<Bomba*>::iterator it = bombas.begin(); it != bombas.end(); ++it) {

		if (((*it)->x >= x && (*it)->x <= x + 5 && y - 3 == (*it)->y))
		{
			obstaculo = true;
			EliminarTanque();
			vida--;
			(*it)->ElimarBomba();
			return true;
			break;
		}

	}
	if (!obstaculo) {
		dibujarTanqueAI(jugadores);
	}
	return false;
}
void TanqueJugador::iniciarIA(list<TanqueJugador*> tanques, list<muro*> muros,int &restantes,int &sleep,int &v, std::list<Bomba*> bombas,bool & pausar)
{

	int *restante = &restantes;
	int res = *restante;
	bool *pausa = &pausar;
	int *sleepa = &sleep;
	int sleepp = *sleepa;


	MoverAbajoAI(tanques, muros,bombas);

	while (res>v)
	{
		res = *restante;
		//gotoxy(0, 60);
		//cout << "PRUEBA " << res;
		//movimientos de tanque 1
		switch (rand() % 6)
		{
		case 1:
			//MoverArriba(jugador2, muros);
			Sleep(25);
			//MoverArriba(jugador2, muros);
			Sleep(25);
			break;

		case 2:
			MoverAbajoAI(tanques, muros,bombas);
			Sleep(25);
			MoverAbajoAI(tanques, muros,bombas);
			Sleep(25);
			break;

		case 3:
			MoverIzquierdaAI(tanques, muros,bombas);
			Sleep(25);
			MoverIzquierdaAI(tanques, muros,bombas);
			Sleep(25);
			break;

		case 4:
			MoverDerechaAI(tanques, muros,bombas);
			Sleep(25);
			MoverDerechaAI(tanques, muros,bombas);
			Sleep(25);
			break;

		case 5:
		thread t2(&TanqueJugador::DispararAI, this, ref(tanques), ref(muros),ref(restantes));
		t2.join();
		
			break;
		}
		Sleep(sleepp);
		if ((*pausa))
		{
			Sleep(10000);
		}
	}

	EliminarTanque();
	

}

void TanqueJugador::displayvida()
{
	gotoxy(xv, yv);
	cout << "Vidas: " << vida;
}
TanqueJugador::TanqueJugador(int Px, int Py, int dirc, int vida,int xv,int yv,int vx, int vy)
{
	this->x = Px;
	this->y = Py;
	shooting = false;
	direccion = dirc;
	//display de vida
	this->vida = vida;
	this->xv = xv;
	this->yv = yv;
	//vicotira
	this->vx = vx;
	this->vy = vy;
	gotoxy(vx, vy);
	cout << "%";
	displayvida();
	ganador = false;

	this->ix = Px;
	this->iy = Py;
}
TanqueJugador::TanqueJugador(int Px,int Py,int dirc)
{
	this->x = Px;
	this->y = Py;
	shooting = false;
	direccion = dirc;
	this->vida =1;

	this->xv = NULL;
	this->yv = NULL;
	this->vx = NULL;
	this->vy = NULL;

	this->ix = Px;
	this->iy = Py;
	
}
TanqueJugador::TanqueJugador(int Px, int Py, int dirc, int vid, int xv,int yv)
{
	this->x = Px;
	this->y = Py;
	shooting = false;
	direccion = dirc;

	this->vida = vid;
	this->xv = xv;
	this->yv = yv;

	this->ix = Px;
	this->iy = Py;
}
void TanqueJugador::gotoxy(int X, int Y)
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

void TanqueJugador::dibujarTanque(TanqueJugador *jugador)
{ 
	if (vida > 0) {

		if (direccion == 1) {
			switch (direccionAnte)
			{
			case 1:
				//termiando

				if (verificarmovimientoFrente(jugador))
				{
					y--;
					gotoxy(x, y + 1); puts(borrar_avion);

					gotoxy(x, y); puts(TanqueJugador_l3);
					gotoxy(x, y - 1); puts(TanqueJugador_l2);
					gotoxy(x, y - 2); puts(TanqueJugador_l1);
				}


				break;

			case 2:
				//terminado
				gotoxy(x, y + 1); puts(borrar_avion);

				gotoxy(x, y); puts(TanqueJugador_l3);
				gotoxy(x, y - 1); puts(TanqueJugador_l2);
				gotoxy(x, y - 2); puts(TanqueJugador_l1);
				break;

			case 3:
				//gotoxy(x, y + 3); puts(borrar_avion);
				gotoxy(x, y + 1); puts(borrar_avion);


				gotoxy(x, y); puts(TanqueJugador_l3);
				gotoxy(x, y - 1); puts(TanqueJugador_l2);
				gotoxy(x, y - 2); puts(TanqueJugador_l1);
				break;

			case 4:
				//ERROR DE DERECHA A ARRIBA
				gotoxy(x + 1, y - 1); puts(borrar_avion);
				gotoxy(x + 1, y); puts(borrar_avion);


				gotoxy(x, y); puts(TanqueJugador_l3);
				gotoxy(x, y - 1); puts(TanqueJugador_l2);
				gotoxy(x, y - 2); puts(TanqueJugador_l1);

				break;
			}
		}

		if (direccion == 2)
		{
			switch (direccionAnte)
			{

			case 1:
				//terminado
				gotoxy(x, y - 1); puts(borrar_avion);
				gotoxy(x, y - 2); puts(borrar_avion);


				gotoxy(x, y - 1); puts(TanqueJugador_l3);
				gotoxy(x, y); puts(TanqueJugador_l2);
				gotoxy(x, y + 1); puts(TanqueJugador_l1);
				break;

			case 2:

				if (verificarmovimientoAbajo(jugador))
				{
					//termiando
					y++;
					gotoxy(x, y - 2); puts(borrar_avion);

					gotoxy(x, y - 1); puts(TanqueJugador_l3);
					gotoxy(x, y); puts(TanqueJugador_l2);
					gotoxy(x, y + 1); puts(TanqueJugador_l1);
				}
				break;

			case 3:
				//gotoxy(x, y + 3); puts(borrar_avion);
				//gotoxy(x, y + 2); puts(borrar_avion);

				gotoxy(x, y - 1); puts(TanqueJugador_l3);
				gotoxy(x, y); puts(TanqueJugador_l2);
				gotoxy(x, y + 1); puts(TanqueJugador_l1);

				break;

			case 4:
				gotoxy(x + 1, y); puts(borrar_avion);
				gotoxy(x + 1, y - 1); puts(borrar_avion);

				gotoxy(x, y - 1); puts(TanqueJugador_l3);
				gotoxy(x, y); puts(TanqueJugador_l2);
				gotoxy(x, y + 1); puts(TanqueJugador_l1);

				break;
			}
		}

		if (direccion == 3)
		{
			switch (direccionAnte)
			{
			case 1:
				//terminado
				gotoxy(x, y - 2); puts(borrar_avion);

				gotoxy(x, y); puts(TanqueJugador_Izquieda2);
				gotoxy(x, y - 1); puts(TanqueJugador_Izquieda3);
				break;

			case 2:
				//termiando
				gotoxy(x, y + 1); puts(borrar_avion);

				gotoxy(x, y); puts(TanqueJugador_Izquieda2);
				gotoxy(x, y - 1); puts(TanqueJugador_Izquieda3);
				break;

			case 3:
				//terminado

				if (verificarmovimientoIzquierda(jugador))
				{
					gotoxy(x, y); puts(borrar_avion);
					gotoxy(x, y - 1); puts(borrar_avion);
					x--;
					gotoxy(x, y); puts(TanqueJugador_Izquieda2);
					gotoxy(x, y - 1); puts(TanqueJugador_Izquieda3);
				}
				break;
			case 4:
				//terminado
				gotoxy(x + 1, y); puts(borrar_avion);
				gotoxy(x + 1, y - 1); puts(borrar_avion);


				gotoxy(x, y); puts(TanqueJugador_Izquieda2);
				gotoxy(x, y - 1); puts(TanqueJugador_Izquieda3);

				break;
			}
		}

		if (direccion == 4)
		{
			switch (direccionAnte)
			{
			case 1:

				//terminado
				gotoxy(x, y - 2); puts(borrar_avion);

				gotoxy(x + 1, y); puts(TanqueJugador_Derecha2);
				gotoxy(x + 1, y - 1); puts(TanqueJugador_Derecha3);
				break;

			case 2:
				//termiando
				gotoxy(x, y + 1); puts(borrar_avion);

				gotoxy(x + 1, y); puts(TanqueJugador_Derecha2);
				gotoxy(x + 1, y - 1); puts(TanqueJugador_Derecha3);
				break;

			case 3:
				gotoxy(x, y); puts(borrar_avion);
				gotoxy(x, y - 1); puts(borrar_avion);

				gotoxy(x + 1, y); puts(TanqueJugador_Derecha2);
				gotoxy(x + 1, y - 1); puts(TanqueJugador_Derecha3);
				break;

			case 4:

				if (verificarmovimientoDerecha(jugador))
				{
					gotoxy(x, y); puts(borrar_avion);
					gotoxy(x, y - 1); puts(borrar_avion);
					x++;

					gotoxy(x + 1, y); puts(TanqueJugador_Derecha2);
					gotoxy(x + 1, y - 1); puts(TanqueJugador_Derecha3);
					break;
				}
			}
		}
		//gotoxy(x, y); cout << y;
		//gotoxy(x, y - 1); cout << x;
	}
	
}

void TanqueJugador::EliminarTanque()
{
	
	gotoxy(x, y-1); puts(borrar_avion);
	gotoxy(x, y); puts(borrar_avion);
	gotoxy(x, y + 1); puts(borrar_avion);
	gotoxy(x, y + 2); puts(borrar_avion);
	this->x = ix;
	this->y = iy;
}

void TanqueJugador::Disparar(TanqueJugador *enemy, list<muro*> muros,bool *terminar,bool &disparo)
{
	bool *disparar = &disparo;
	if(*disparar ==false)
	{ 
		(*disparar) =true;
	if (!shooting) {
		
	
		shooting = true;
		if (direccion == 1) {
			bx = x + 3;
			by = y - 3;
			bool toquearriba = false;
		
			do {
				/*for (int i = 0; i < muros.size(); i++)
				{
					muro muro1 = muros[i];
					
					

					if ((muro1.x == bx && muro1.y == by - 1)&&muro1.destruido==false)
					{
						toquearriba = true;
						shooting = false;
						muro1.recibirdano();
						muro1.destruirMuro();
					}

				}*/
				
				

				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {
					
					if (((*it)->x == bx && (*it)->y == by - 1) && (*it)->destruido == false)
					{
						toquearriba = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
						(*disparar) = false;
					}

				}
				if (!toquearriba) {
					gotoxy(bx, by);
					printf("0");
					Sleep(50);
					gotoxy(bx, by);
					printf(" ");
					by--;
					

					if ((bx > (*enemy).x && bx < (*enemy).x + 6 && by == (*enemy).y + 1))
					{
						
						(*enemy).EliminarTanque();
						(*enemy).vida--;
						(*disparar) = false;
						if ((*enemy).vida > 0) {
							
							(*enemy).displayvida();

						}
						else {
							gotoxy(((*enemy).xv), (*enemy).yv);
							cout << "PERDISTE     ";
							this->ganador = true;
							Sleep(500);
							gotoxy(50, 13);
							cout << "FIN DEL JUEGO";
							(*terminar) = true;
							

						}

						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}

					if (by == 0)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						shooting = false;
						break;
					}
					if (bx == (*enemy).vx && by - 1 == (*enemy).vy)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						shooting = false;
						this->ganador = true;
						(*enemy).vida = 0;

						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;
						
					}
				}
			} while (shooting == true);
		}

		if (direccion == 2) 
		{
			bx = x + 3;
			by = y + 3;
			bool toqueabajo = false;
				do {

				


					for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

						if (((*it)->x == bx && (*it)->y == by + 1) && (*it)->destruido == false)
						{
							toqueabajo = true;
							shooting = false;
							(*it)->recibirdano();
							(*it)->destruirMuro();
							(*disparar) = false;
						}

					}

					if (!toqueabajo)
					{
						gotoxy(bx, by);
						printf("0");
						Sleep(50);
						gotoxy(bx, by);
						printf(" ");
						by++;

						if ((bx > (*enemy).x && bx < (*enemy).x + 6 && by == (*enemy).y + 1))
						{
							(*enemy).EliminarTanque();
							(*enemy).vida--;
							(*disparar) = false;
							if ((*enemy).vida > 0) {
								
								(*enemy).displayvida();

							}
							else {
								gotoxy(((*enemy).xv), (*enemy).yv);
								cout << "PERDISTE     ";
								this->ganador = true;
								Sleep(500);
								gotoxy(50, 13);
								cout << "FIN DEL JUEGO";
								(*terminar) = true;
								
							}

							Sleep(150);

							shooting = false;
							by = NULL;
							bx = NULL;
							break;

						}


						if (by == 0 || by == 29)
						{
							by = NULL;
							bx = NULL;
							shooting = false;
							(*disparar) = false;
							break;
						}

						if (bx == (*enemy).vx && by + 1 == (*enemy).vy)
						{
							by = NULL;
							(*disparar) = false;
							bx = NULL;
							shooting = false;
							(*enemy).vida = 0;

							Sleep(500);
							gotoxy(50, 13);
							cout << "FIN DEL JUEGO";
							break;
							
						}
					}
			} while (shooting == true);

			
		}
		if (direccion == 3)
		{
			bx = x - 3;
			by = y ;
			bool toqueizquierda = false;
			do {
			/*	for (int i = 0; i < muros.size(); i++)
				{
					muro muro = muros[i];

					if (muro.y==by&&muro.x==bx-1)
					{
						toqueizquierda = true;
						shooting = false;
						muro.recibirdano();
						muro.destruirMuro();
					}

				}
*/

				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx-1 && (*it)->y == by ) && (*it)->destruido == false)
					{
						toqueizquierda = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
						(*disparar) = false;
					}

				}

				if (!toqueizquierda) {
					gotoxy(bx, by);
					printf("0");
					Sleep(50);
					gotoxy(bx, by);
					printf(" ");
					bx--;

					if (by <= (*enemy).y&&by >= (*enemy).y - 1&& bx-4==(*enemy).x)
					{
							(*enemy).vida--;
						(*enemy).EliminarTanque();
						(*disparar) = false;
						if ((*enemy).vida > 0) {
						
							(*enemy).displayvida();

						}
						else {
							gotoxy(((*enemy).xv), (*enemy).yv);
							cout << "PERDISTE     ";
							this->ganador = true;
							gotoxy(50, 13);
							cout << "FIN DEL JUEGO";
							(*terminar) = true;
							

						}
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}


					if (bx == 0 || bx == 119)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						shooting = false;
						break;
					}

					if (bx-1 == (*enemy).vx && by  == (*enemy).vy)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						shooting = false;
						(*enemy).vida = 0;

						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}
				}
			} while (shooting == true);


		}

		if (direccion == 4)
		{
			bx = x + 6;
			by = y;

			bool toquederecha = false;

			do {
				/*for (int i = 0; i < muros.size(); i++)
				{
					muro muro = muros[i];

					if (muro.y == by && muro.x == bx + 1)
					{
						toquederecha = true;
						shooting = false;
						muro.recibirdano();
						muro.destruirMuro();
					}

				}*/


				for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

					if (((*it)->x == bx + 1 && (*it)->y == by) && (*it)->destruido == false)
					{
						toquederecha = true;
						shooting = false;
						(*it)->recibirdano();
						(*it)->destruirMuro();
						(*disparar) = false;
					}

				}

				if (!toquederecha)
				{
					gotoxy(bx, by);
					printf("0");
					Sleep(50);
					gotoxy(bx, by);
					printf(" ");
					bx++;

					if (by <= (*enemy).y&&by >= (*enemy).y - 1 && bx + 1 == (*enemy).x)
					{
						(*enemy).vida--;
						(*enemy).EliminarTanque();
						(*disparar) = false;

						if ((*enemy).vida > 0) {

							(*enemy).displayvida();

						}
						else {
							gotoxy(((*enemy).xv), (*enemy).yv);
							cout << "PERDISTE     ";
							gotoxy(50, 13);
							cout << "FIN DEL JUEGO";
							(*terminar) = true;

						}
						Sleep(150);

						shooting = false;
						by = NULL;
						bx = NULL;
						break;

					}


					if (bx == 0 || bx == 119)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						shooting = false;
						break;
					}

					if (bx + 1 == (*enemy).vx && by == (*enemy).vy)
					{
						by = NULL;
						bx = NULL;
						(*disparar) = false;
						(*enemy).vida = 0;
						shooting = false;
						Sleep(500);
						gotoxy(50, 13);
						cout << "FIN DEL JUEGO";
						break;

					}
				}
			} while (shooting == true);

		}
	}
	}
}

//Movimiento de tanque

bool TanqueJugador::MoverArriba(TanqueJugador *jugador, list<muro*> muros,list<Bomba*> bombas)
{	
	direccionAnte = direccion;
	direccion = 1;
	bool obstaculo = false;

	//for (int i = 0; i < muros.size(); i++)
	//{
	//	muro muro = muros[i];

	//	if ((muro.x>=x&& muro.x<=x+5)&&y - 3 == muro.y)
	//	{
	//		obstaculo = true;
	//		break;
	//	}

	//}

	for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

		if (((*it)->x >= x  && (*it)->x <= x+5 && y-3 == (*it)->y) && (*it)->destruido == false)
		{
			obstaculo = true;
			break;
		}

	}

	for (std::list<Bomba*>::iterator it = bombas.begin(); it != bombas.end(); ++it) {

		if (((*it)->x >= x && (*it)->x <= x + 5 && y - 3 == (*it)->y))
		{
			obstaculo = true;
			EliminarTanque();
			vida--;
			(*it)->ElimarBomba();
			return true;
			break;
		}

	}
	if (!obstaculo) {
		dibujarTanque(jugador);
	}
	return false;
	
}
bool TanqueJugador::MoverAbajo(TanqueJugador *jugador, list<muro*> muros, list<Bomba*> bombas)
{
	direccionAnte = direccion;
	direccion = 2;
	bool obstaculo = false;
	//
	//for (int i = 0; i < muros.size(); i++)
	//{
	//	muro muro = muros[i];

	//	if ((muro.x >= x && muro.x <= x + 5) && y + 2 == muro.y)
	//	{
	//		obstaculo = true;
	//		break;
	//	}

	//}

	for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

		if (((*it)->x >= x && (*it)->x <= x + 5 && y + 2 == (*it)->y) && (*it)->destruido == false)
		{
			obstaculo = true;
			break;
		}

	}

	for (std::list<Bomba*>::iterator it = bombas.begin(); it != bombas.end(); ++it) {

		if (((*it)->x >= x && (*it)->x <= x + 5 && y + 2 == (*it)->y))
		{
			obstaculo = true;
			EliminarTanque();
			vida--;
			(*it)->ElimarBomba();
			return true;
			break;
		}

	}
	

	if (!obstaculo)
	{
		dibujarTanque(jugador);
	}
	return false;
	
}
bool TanqueJugador::MoverIzquierda(TanqueJugador *jugador, list<muro*> muros, list<Bomba*>bombas)
{
	direccionAnte = direccion;
	direccion = 3;
	bool obstaculo = false;
	//for (int i = 0; i < muros.size(); i++)
	//{
	//	muro muro = muros[i];

	//	if ((muro.y>=y-2&&muro.y<=y+1)&&muro.x==x-1)
	//	{
	//		obstaculo = true;
	//		break;
	//	}

	//}

	for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

		if (((*it)->y >= y-2 && (*it)->y <= y + 1 && x - 1 == (*it)->x) && (*it)->destruido == false)
		{
			obstaculo = true;
			break;
		}

	}
	for (std::list<Bomba*>::iterator it = bombas.begin(); it != bombas.end(); ++it) {

		if (((*it)->y >= y - 2 && (*it)->y <= y + 1 && x - 1 == (*it)->x))
		{
			obstaculo = true;
			EliminarTanque();
			vida--;
			(*it)->ElimarBomba();
			return true;
			break;
		}

	}


	if (!obstaculo) {
		dibujarTanque(jugador);
	}
	return false;
}
bool TanqueJugador::MoverDerecha(TanqueJugador *jugador, list<muro*> muros, list<Bomba*>bombas)
{
	direccionAnte = direccion;
	direccion = 4;
	bool obstaculo = false;

	//for (int i = 0; i < muros.size(); i++)
	//{
	//	muro muro = muros[i];

	//	if ((muro.y >= y - 2 && muro.y <= y + 1) && muro.x == x + 6)
	//	{
	//		obstaculo = true;
	//		break;
	//	}

	//}

	for (std::list<muro*>::iterator it = muros.begin(); it != muros.end(); ++it) {

		if (((*it)->y >= y - 2 && (*it)->y <= y + 1 && x + 6 == (*it)->x) && (*it)->destruido == false)
		{
			obstaculo = true;
			break;
		}

	}

	for (std::list<Bomba*>::iterator it = bombas.begin(); it != bombas.end(); ++it) {


		if (((*it)->y >= y - 2 && (*it)->y <= y + 1 && x + 6 == (*it)->x))
		{
			obstaculo = true;
			EliminarTanque();
			vida--;
			(*it)->ElimarBomba();
			return true;
			break;
		}

	}


	if (!obstaculo) {
		dibujarTanque(jugador);
	}
	return false;
}


bool TanqueJugador::verificarmovimientoFrenteAI(std::list<TanqueJugador*> jugadores)
{
	std::list<TanqueJugador*>::iterator it = jugadores.begin();

	TanqueJugador *jugador1 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador2 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador3 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador4 = &**it;

	if (y - 3 == 1) {

		return false;
	}
	
	if (/*(y - 4 <= (*jugador1).y&&y - 4 >= (*jugador1).y - 2) && (x > (*jugador1).x - 5 && x < (*jugador1).x + 5)   ||*/
		(y - 4 <= (*jugador2).y&&y - 4 >= (*jugador2).y - 2) && (x > (*jugador2).x - 5 && x < (*jugador2).x + 5)   ||
		(y - 4 <= (*jugador3).y&&y - 4 >= (*jugador3).y - 2) && (x > (*jugador3).x - 5 && x < (*jugador3).x + 5)   ||
		(y - 4 <= (*jugador4).y&&y - 4 >= (*jugador4).y - 2) && (x > (*jugador4).x - 5 && x < (*jugador4).x + 5))
	{
		return false;
	}
	else {
		//se puede mover

		return true;
	}
}
bool TanqueJugador::verificarmovimientoFrente(TanqueJugador *jugador)
{

	if (y - 3 == 1) {
	
		return false;
	}
	if ((y-4<=(*jugador).y&&y - 4 >= (*jugador).y - 2)&&(x>(*jugador).x-5&&x<(*jugador).x+5))
	{
		return false;
	}
	else{
		//se puede mover

		return true;
	}

}


bool TanqueJugador::verificarmovimientoAbajoAI(std::list<TanqueJugador*> jugadores)
{
	std::list<TanqueJugador*>::iterator it = jugadores.begin();

	TanqueJugador *jugador1 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador2 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador3 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador4 = &**it;

	if (y + 1 == 28) {

		return false;
	}

	if (/*(y + 4 <= (*jugador1).y&&y + 6 >= (*jugador1).y + 2) && (x > (*jugador1).x - 5 && x < (*jugador1).x + 5)  ||*/
		(y + 4 <= (*jugador2).y&&y + 6 >= (*jugador2).y + 2) && (x > (*jugador2).x - 5 && x < (*jugador2).x + 5)  ||
		(y + 4 <= (*jugador3).y&&y + 6 >= (*jugador3).y + 2) && (x > (*jugador3).x - 5 && x < (*jugador3).x + 5)  ||
		(y + 4 <= (*jugador4).y&&y + 6 >= (*jugador4).y + 2) && (x > (*jugador4).x - 5 && x < (*jugador4).x + 5))
	{
		return false;
	}
	else {
		//se puede mover

		return true;
	}

}
bool TanqueJugador::verificarmovimientoAbajo(TanqueJugador *jugador)
{
	if (y + 1 == 28) {

		return false;
	}
	if ((y + 4 <= (*jugador).y&&y + 6 >= (*jugador).y +2) && (x > (*jugador).x - 5 && x < (*jugador).x + 5))
	{
		return false;
	}
	else {
		//se puede mover

		return true;
	}
}


bool TanqueJugador::verificarmovientoIzquierdaAI(std::list<TanqueJugador*>jugadores)
{
	std::list<TanqueJugador*>::iterator it = jugadores.begin();

	TanqueJugador *jugador1 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador2 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador3 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador4 = &**it;

	if (x - 1 == 0) {

		return false;
	}

	if (/*(x - 6 <= (*jugador1).x&&x + 4 >= (*jugador1).x) && (y <= (*jugador1).y + 3 && y >= (*jugador1).y - 3)  */
		(x - 6 <= (*jugador2).x&&x + 4 >= (*jugador2).x) && (y <= (*jugador2).y + 3 && y >= (*jugador2).y - 3)   ||
		(x - 6 <= (*jugador3).x&&x + 4 >= (*jugador3).x) && (y <= (*jugador3).y + 3 && y >= (*jugador3).y - 3)   ||
		(x - 6 <= (*jugador4).x&&x + 4 >= (*jugador4).x) && (y <= (*jugador4).y + 3 && y >= (*jugador4).y - 3))
	{
		return false;
	}
	else {
		//se puede mover

		return true;
	}
}
bool TanqueJugador::verificarmovimientoIzquierda(TanqueJugador *jugador)
{

	if (x - 1 == 0) {

		return false;
	}
	if ((x-6<=(*jugador).x&&x+4>=(*jugador).x)&& (y <= (*jugador).y+3&&y>=(*jugador).y-3))
	{
		return false;
	}
	else {
		//se puede mover

		return true;
	}

}


bool TanqueJugador::verificarmovimientoDerechaAI(std::list<TanqueJugador*>jugadores)
{

	std::list<TanqueJugador*>::iterator it = jugadores.begin();

	TanqueJugador *jugador1 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador2 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador3 = &**it;
	std::advance(it, 1);
	TanqueJugador *jugador4 = &**it;

	if (x + 3 == 116) {

		return false;
	}

	if (/*(x - 5 <= (*jugador1).x&&x + 7 >= (*jugador1).x) && (y <= (*jugador1).y + 3 && y >= (*jugador1).y - 3)  ||*/
		(x - 5 <= (*jugador2).x&&x + 7 >= (*jugador2).x) && (y <= (*jugador2).y + 3 && y >= (*jugador2).y - 3)  ||
		(x - 5 <= (*jugador3).x&&x + 7 >= (*jugador3).x) && (y <= (*jugador3).y + 3 && y >= (*jugador3).y - 3)  ||
		(x - 5 <= (*jugador4).x&&x + 7 >= (*jugador4).x) && (y <= (*jugador4).y + 3 && y >= (*jugador4).y - 3)  )
	{
		return false;
	}
	else {
		//se puede mover

		return true;
	}

}
bool TanqueJugador::verificarmovimientoDerecha(TanqueJugador *jugador)
{
	if (x + 3 == 116) {

		return false;
	}

	if ((x - 5 <= (*jugador).x&&x + 7 >= (*jugador).x) && (y <= (*jugador).y + 3 && y >= (*jugador).y - 3))
	{
		return false;
	}
	else {
		//se puede mover

		return true;
	}

}

void TanqueJugador::setvida(int vid)
{
	this->vida = vid;
}

void TanqueJugador::setxvy(int x, int v)
{
	this->xv = x;
	this->yv = v;

}
