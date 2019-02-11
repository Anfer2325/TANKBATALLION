// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <atomic>
#include "TanqueEnemigo.h"
#include <future>
#include "TanqueJugador.h"
#include "muro.h"
#include <vector>
#include <Windows.h>
#include <list>
#include "Bomba.h"
#include <stdio.h>
#define VK_W 0x57 
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_F 0x46
#define VK_P 0x50
bool disparando = false;
bool disparandojugador1 = false;
bool disparandojugador2 = false;
bool pausar = false;
bool *dispara = &disparando;
int PuntuacionTanqueNiv1 = 30;
int PuntuacionTanqueNiv2 = 60;
int PuntuacionTanqueNiv3 = 120;
int PuntuacionTanqueNiv4 = 180;
int PuntuacionTanqueNiv5 = 360;

int PuntuacionMasterNiv12 = 100;
int PuntuacionMasterNiv34 = 250;
int PuntuacionMaasterNiv5 = 500;
int puntuacion = 0;
using namespace std;
void gotoxy(int x, int y)
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}
int main()
{


	int seleccion = 0;
	int flecha = 0;

	gotoxy(40, 3);
	cout << " ________   ______   __    __  __    __   ______  ";
	gotoxy(40, 4);
	cout << "|        \ /      \ |  \  |  \|  \  /  \ /      \ ";
	gotoxy(40, 5);
	cout<< " \\$$$$$$$$|  $$$$$$\| $$\ | $$| $$ /  $$|  $$$$$$\\";
	gotoxy(40, 6);
	cout << "   | $$   | $$__| $$| $$$\| $$| $$/  $$ | $$___\$$";
	gotoxy(40, 7);
	cout << "   | $$   | $$    $$| $$$$\ $$| $$  $$   \$$    \ ";
	gotoxy(40, 8);
	cout << "   | $$   | $$$$$$$$| $$\$$ $$| $$$$$\   _\$$$$$$\\";
	gotoxy(40,9);
	cout << "   | $$   | $$  | $$| $$ \$$$$| $$ \$$\ |  \__| $$";
	gotoxy(40, 10);
	cout << "   | $$   | $$  | $$| $$  \$$$| $$  \$$\ \$$    $$";
	gotoxy(40, 11);
	cout << "    \$$    \$$   \$$ \$$   \$$ \$$   \$$  \$$$$$$ ";
	gotoxy(53, 13);
	puts("1 PLAYER");
	gotoxy(53, 14);
	puts("2 PLAYER");

	while ( true) {

		


		if (GetAsyncKeyState(VK_DOWN))
		{
			gotoxy(50, 13);
			puts(" ");
			gotoxy(50, 14);
			puts(">");
			flecha = 1;
		}



		if (GetAsyncKeyState(VK_UP))
		{
			gotoxy(50, 14);
			puts(" ");
			gotoxy(50, 13);
			puts(">");
			flecha = 2;

		}




		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (flecha)
			{
			case 1:
				seleccion = 1;
				break;
			case 2:
				seleccion = 2;
				break;
			}
		}


		if (seleccion == 2)
		{
			bool iniciado = false;
			int restantes = 5;
			gotoxy(45, 0);
			cout << "NIVEL 1";

			while (restantes>0) {
				
				
					iniciado = true;
					// obstaculos de mapa
					muro muro1(23, 8);
					muro muro2(23, 9);
					muro muro3(23, 10);
					muro muro4(23, 11);
					muro muro5(23, 12);
					muro muro6(23, 13);
					muro muro7(23, 14);
					muro muro8(23, 15);
					muro muro9(23, 16);
					muro muro10(23, 17);
					muro muro11(23, 18);
					muro muro12(23, 19);
					muro muro13(23, 20);
					muro muro14(23, 21);
					muro muro15(23, 22);
					muro muro16(23, 23);


					//porteria jugador 1

					muro muro17(60, 28);
					muro muro18(60, 27);
					muro muro19(59, 27);
					muro muro20(58, 27);
					muro muro21(57, 27);
					muro muro22(57, 28);


					//porteria jugador 2
					muro muro23(60, 1);
					muro muro24(60, 2);
					muro muro25(59, 2);
					muro muro26(58, 2);
					muro muro27(57, 2);
					muro muro28(57, 1);


					//vector<muro> muros;
					list<Bomba*> bombas;
					Bomba bomba1(70,22);
					bombas.push_back(&bomba1);
					

					list<muro*> muros;

					muros.push_back(&muro1);
					muros.push_back(&muro2);
					muros.push_back(&muro3);
					muros.push_back(&muro4);
					muros.push_back(&muro5);
					muros.push_back(&muro6);
					muros.push_back(&muro7);
					muros.push_back(&muro8);
					muros.push_back(&muro9);
					muros.push_back(&muro10);
					muros.push_back(&muro11);
					muros.push_back(&muro12);
					muros.push_back(&muro12);
					muros.push_back(&muro13);
					muros.push_back(&muro14);
					muros.push_back(&muro15);
					muros.push_back(&muro16);
					muros.push_back(&muro17);
					muros.push_back(&muro18);
					muros.push_back(&muro19);
					muros.push_back(&muro20);
					muros.push_back(&muro21);
					muros.push_back(&muro22);
					muros.push_back(&muro23);
					muros.push_back(&muro24);
					muros.push_back(&muro25);
					muros.push_back(&muro26);
					muros.push_back(&muro27);
					muros.push_back(&muro28);



					for (int y = 1; y < 30; y++)
					{
						for (int x = 0; x < 120; x++)
						{
							if (y == 1 || y == 29)
							{

								muro mur(x, y);
								mur.dibujarmuro();
								//muros.push_back(&mur);
							}
							else if (x == 0 || x == 119)
							{
								muro mur(x, y);
								mur.dibujarmuro();
								//muros.push_back(mur);
							}
							else { gotoxy(x, y); puts(" "); }

						}

					}

					muro1.dibujarmuro();
					muro2.dibujarmuro();
					muro3.dibujarmuro();
					muro4.dibujarmuro();
					muro5.dibujarmuro();
					muro6.dibujarmuro();
					muro7.dibujarmuro();
					muro8.dibujarmuro();
					muro9.dibujarmuro();
					muro10.dibujarmuro();
					muro11.dibujarmuro();
					muro12.dibujarmuro();
					muro13.dibujarmuro();
					muro14.dibujarmuro();
					muro15.dibujarmuro();
					muro16.dibujarmuro();
					muro17.dibujarmuro();
					muro18.dibujarmuro();
					muro19.dibujarmuro();
					muro20.dibujarmuro();
					muro21.dibujarmuro();
					muro22.dibujarmuro();
					muro23.dibujarmuro();
					muro24.dibujarmuro();
					muro25.dibujarmuro();
					muro26.dibujarmuro();
					muro27.dibujarmuro();
					muro28.dibujarmuro();

					muro prueba(50, 5);
					prueba.dibujarmuro();

					muros.push_back(&prueba);

					TanqueJugador jugador11(40, 26, 1, 3, 3, 0, 59, 28);
					TanqueJugador jugador22(40, 4, 2);
					TanqueJugador jugador33(20, 4, 2);
					TanqueJugador jugador44(60, 4, 2);
					
					

					std::list <TanqueJugador*> a;
					a.push_back(&jugador11);
					a.push_back(&jugador22);
					a.push_back(&jugador33);
					a.push_back(&jugador44);
				
				

					TanqueJugador *juga11 = &jugador11;
					TanqueJugador *juga22 = &jugador22;
					TanqueJugador *juga33 = &jugador33;
					TanqueJugador *juga44 = &jugador44;
				

					jugador11.dibujarTanqueAI(a);
					jugador22.dibujarTanqueAI(a);
					jugador33.dibujarTanqueAI(a);
					jugador44.dibujarTanqueAI(a);

					bomba1.Dibujar();
			

					int niv1Speed = 1500;
					int *sleepniv1 = &niv1Speed;

					int v = 1;
					int vv = 0;
					thread t3(&TanqueJugador::iniciarIA, juga22, ref(a), ref(muros),ref(restantes),ref(niv1Speed),ref(v),ref(bombas),ref(pausar));
					t3.detach();
					Sleep(250);

					thread t4(&TanqueJugador::iniciarIA, juga33, ref(a), ref(muros),ref(restantes),ref(niv1Speed),ref(v), ref(bombas),ref(pausar));
					t4.detach();

					Sleep(250);

					thread t5(&TanqueJugador::iniciarIA, juga44, ref(a), ref(muros), ref(restantes),ref(niv1Speed),ref(v), ref(bombas),ref(pausar));
					t5.detach();
					Sleep(250);
					bool BF7 = false;

					bool iniciomaster1 = false;
					while (true)
					{
						

							if (GetAsyncKeyState(VK_UP))
							{


								if (jugador11.MoverArribaAI(a, muros, bombas))
								{
									jugador11.displayvida();
								}

								Sleep(25);
							}
							if (GetAsyncKeyState(VK_DOWN))
							{

								if (jugador11.MoverAbajoAI(a, muros, bombas))
								{
									jugador11.displayvida();
								}
								Sleep(25);
							}

							if (GetAsyncKeyState(VK_LEFT))
							{

								if (jugador11.MoverIzquierdaAI(a, muros, bombas))
								{
									jugador11.displayvida();
								}
								Sleep(25);
							}

							if (GetAsyncKeyState(VK_RIGHT))
							{

								if (jugador11.MoverDerechaAI(a, muros, bombas))
								{
									jugador11.displayvida();
								}
								Sleep(25);
							}

							if (GetAsyncKeyState(VK_SPACE))
							{

								thread t1(&TanqueJugador::DispararAI2, jugador11, ref(a), ref(muros),ref(restantes),ref(disparando),ref(PuntuacionTanqueNiv1),ref(puntuacion));
								t1.detach();
								
								
								Sleep(150);
							}
							if (GetAsyncKeyState(VK_P))
							{
								pausar = true;
								Sleep(10150);
								pausar = false;
							}

							Sleep(150);
							bool iniciado2 = false;
						
							while (restantes <= 0)
							{

								system("cls");


								cout << "BOSS FIGHT";
								Sleep(1500);
								system("cls");
								gotoxy(45, 0);
								cout << "BOSS FIGHT";
								int restantes2 = 3;
								if (iniciado2 == false)
								{
									//NIVEL 11111 master
								


									for (int y = 1; y < 30; y++)
									{
										for (int x = 0; x < 120; x++)
										{
											if (y == 1 || y == 29)
											{

												muro mur(x, y);
												mur.dibujarmuro();
												//muros.push_back(&mur);
											}
											else if (x == 0 || x == 119)
											{
												muro mur(x, y);
												mur.dibujarmuro();
												//muros.push_back(mur);
											}
											else { gotoxy(x, y); puts(" "); }

										}

									}


									muro1.dibujarmuro();
									muro2.dibujarmuro();
									muro3.dibujarmuro();
									muro4.dibujarmuro();
									muro5.dibujarmuro();
									muro6.dibujarmuro();
									muro7.dibujarmuro();
									muro8.dibujarmuro();
									muro9.dibujarmuro();
									muro10.dibujarmuro();
									muro11.dibujarmuro();
									muro12.dibujarmuro();
									muro13.dibujarmuro();
									muro14.dibujarmuro();
									muro15.dibujarmuro();
									muro16.dibujarmuro();
									muro17.dibujarmuro();
									muro18.dibujarmuro();
									muro19.dibujarmuro();
									muro20.dibujarmuro();
									muro21.dibujarmuro();
									muro22.dibujarmuro();
									muro23.dibujarmuro();
									muro24.dibujarmuro();
									muro25.dibujarmuro();
									muro26.dibujarmuro();
									muro27.dibujarmuro();
									muro28.dibujarmuro();

									iniciado2 = true;
								
									TanqueJugador jugador1(65, 26, 1, 3, 3, 0, 59, 28);
									TanqueJugador jugador2(205, 4, 2);
									TanqueJugador jugador3(205, 4, 2);
									TanqueJugador jugador4(60, 4, 2,3,60,0);

									std::list <TanqueJugador*> a2;
									a2.push_back(&jugador1);
									a2.push_back(&jugador2);
									a2.push_back(&jugador3);
									a2.push_back(&jugador4);

									TanqueJugador *juga1 = &jugador1;
									TanqueJugador *juga2 = &jugador2;
									TanqueJugador *juga3 = &jugador3;
									TanqueJugador *juga4 = &jugador4;
									list<Bomba*> bombas;
									Bomba bomba1(70, 25);
									bombas.push_back(&bomba1);
									bomba1.Dibujar();

									jugador1.dibujarTanqueAI(a);
									
									jugador4.dibujarTanqueAI(a);

									int niv2Speed = 100;
									int *sleepniv2 = &niv2Speed;
									int v = 0;
				

									thread t5(&TanqueJugador::iniciarIA, juga4, ref(a2), ref(muros), ref(restantes2),ref(niv2Speed),ref(v), ref(bombas),ref(pausar));
									t5.detach();
									Sleep(250);
									bool BF8 = false;
									while (true)
									{
										if (GetAsyncKeyState(VK_UP))
										{


											jugador1.MoverArribaAI(a2, muros,bombas);

											Sleep(25);
										}
										if (GetAsyncKeyState(VK_DOWN))
										{

											if (jugador1.MoverAbajoAI(a2, muros, bombas))
											{
												jugador1.displayvida();
											}
											Sleep(25);
										}

										if (GetAsyncKeyState(VK_LEFT))
										{

											if (jugador1.MoverIzquierdaAI(a2, muros, bombas))
											{
												jugador1.displayvida();
											}
											Sleep(25);
										}

										if (GetAsyncKeyState(VK_RIGHT))
										{

											if (jugador1.MoverDerechaAI(a2, muros, bombas))
											{
												jugador1.displayvida();
											}
											Sleep(25);
										}
										if (GetAsyncKeyState(VK_P))
										{
											pausar = true;
											Sleep(10150);
											pausar = false;
										}

										if (GetAsyncKeyState(VK_SPACE))
										{

											thread t1(&TanqueJugador::DispararAI2, jugador1, ref(a2), ref(muros), ref(restantes2),ref(disparando), ref(PuntuacionMasterNiv12), ref(puntuacion));
											t1.detach();


											Sleep(150);
										}

										Sleep(250);

										while (restantes2 <= 0)
										{
											system("cls");
											Sleep(500);

											system("cls");


											cout << "SIGUIENTE NIVEL";
											Sleep(1500);
											system("cls");
											gotoxy(45, 0);
											cout << "NIVEL 2";
											int restantes2 = 8;
											
												//NIVEL 2222222222222222222222222222222222222222222222222222222222222
												//porteria jugador 1

												muro muro17(60, 28);
												muro muro18(60, 27);
												muro muro19(59, 27);
												muro muro20(58, 27);
												muro muro21(57, 27);
												muro muro22(57, 28);


												//porteria jugador 2
												muro muro23(60, 1);
												muro muro24(60, 2);
												muro muro25(59, 2);
												muro muro26(58, 2);
												muro muro27(57, 2);
												muro muro28(57, 1);

												//MUROS NIVEL 2

												muro muro2_1(15, 15);
												muro muro2_2(16, 15);
												muro muro2_3(17, 15);
												muro muro2_4(18, 15);
												muro muro2_5(19, 15);
												muro muro2_6(20, 15);
												muro muro2_7(21, 15);
												muro muro2_8(22, 15);
												muro muro2_9(23, 15);
												muro muro2_10(24, 15);
												muro muro2_11(25, 15);
												muro muro2_12(26, 15);
												muro muro2_13(27, 15);
												muro muro2_14(28, 15);
												muro muro2_15(29, 15);
												muro muro2_16(30, 15);
												muro muro2_17(31, 15);

												muro muro2_18(32, 15);
												muro muro2_19(33, 15);
												muro muro2_20(34, 15);
												muro muro2_21(35, 15);
												muro muro2_22(36, 15);
												muro muro2_23(37, 15);
												muro muro2_24(38, 15);
												muro muro2_25(39, 15);
												muro muro2_26(40, 15);
												muro muro2_27(41, 15);
												muro muro2_28(42, 15);
												muro muro2_29(43, 15);
												muro muro2_30(44, 15);
												muro muro2_31(45, 15);
												muro muro2_32(46, 15);
												muro muro2_33(47, 15);
												muro muro2_34(48, 15);




												//vector<muro> muros;

												list<muro*> muros2;
												// nuevos muros pushback
												muros2.push_back(&muro2_1);
												muros2.push_back(&muro2_2);
												muros2.push_back(&muro2_3);
												muros2.push_back(&muro2_4);
												muros2.push_back(&muro2_5);
												muros2.push_back(&muro2_6);
												muros2.push_back(&muro2_7);
												muros2.push_back(&muro2_8);
												muros2.push_back(&muro2_9);
												muros2.push_back(&muro2_10);
												muros2.push_back(&muro2_11);
												muros2.push_back(&muro2_12);
												muros2.push_back(&muro2_13);
												muros2.push_back(&muro2_14);
												muros2.push_back(&muro2_15);
												muros2.push_back(&muro2_16);
												muros2.push_back(&muro2_17);
												muros2.push_back(&muro2_18);
												muros2.push_back(&muro2_19);
												muros2.push_back(&muro2_20);
												muros2.push_back(&muro2_21);
												muros2.push_back(&muro2_22);
												muros2.push_back(&muro2_23);
												muros2.push_back(&muro2_24);
												muros2.push_back(&muro2_25);
												muros2.push_back(&muro2_26);
												muros2.push_back(&muro2_27);
												muros2.push_back(&muro2_28);
												muros2.push_back(&muro2_29);
												muros2.push_back(&muro2_30);
												muros2.push_back(&muro2_31);
												muros2.push_back(&muro2_32);
												muros2.push_back(&muro2_33);
												muros2.push_back(&muro2_34);

												muros2.push_back(&muro17);
												muros2.push_back(&muro18);
												muros2.push_back(&muro19);
												muros2.push_back(&muro20);
												muros2.push_back(&muro21);
												muros2.push_back(&muro22);
												muros2.push_back(&muro23);
												muros2.push_back(&muro24);
												muros2.push_back(&muro25);
												muros2.push_back(&muro26);
												muros2.push_back(&muro27);
												muros2.push_back(&muro28);



												for (int y = 1; y < 30; y++)
												{
													for (int x = 0; x < 120; x++)
													{
														if (y == 1 || y == 29)
														{

															muro mur(x, y);
															mur.dibujarmuro();
															//muros.push_back(&mur);
														}
														else if (x == 0 || x == 119)
														{
															muro mur(x, y);
															mur.dibujarmuro();
															//muros.push_back(mur);
														}
														else { gotoxy(x, y); puts(" "); }

													}

												}


												muro2_1.dibujarmuro();
												muro2_2.dibujarmuro();
												muro2_3.dibujarmuro();
												muro2_4.dibujarmuro();
												muro2_5.dibujarmuro();
												muro2_6.dibujarmuro();
												muro2_7.dibujarmuro();
												muro2_8.dibujarmuro();
												muro2_9.dibujarmuro();
												muro2_10.dibujarmuro();
												muro2_11.dibujarmuro();
												muro2_12.dibujarmuro();
												muro2_13.dibujarmuro();
												muro2_14.dibujarmuro();
												muro2_15.dibujarmuro();
												muro2_16.dibujarmuro();
												muro2_17.dibujarmuro();
												muro2_18.dibujarmuro();
												muro2_19.dibujarmuro();
												muro2_20.dibujarmuro();
												muro2_21.dibujarmuro();
												muro2_22.dibujarmuro();
												muro2_23.dibujarmuro();
												muro2_24.dibujarmuro();
												muro2_25.dibujarmuro();
												muro2_26.dibujarmuro();
												muro2_27.dibujarmuro();
												muro2_28.dibujarmuro();
												muro2_29.dibujarmuro();
												muro2_30.dibujarmuro();
												muro2_31.dibujarmuro();
												muro2_32.dibujarmuro();
												muro2_33.dibujarmuro();
												muro2_34.dibujarmuro();

												muro17.dibujarmuro();
												muro18.dibujarmuro();
												muro19.dibujarmuro();
												muro20.dibujarmuro();
												muro21.dibujarmuro();
												muro22.dibujarmuro();
												muro23.dibujarmuro();
												muro24.dibujarmuro();
												muro25.dibujarmuro();
												muro26.dibujarmuro();
												muro27.dibujarmuro();
												muro28.dibujarmuro();

												iniciado2 = true;

												TanqueJugador jugador1(65, 26, 1, 3, 3, 0, 59, 28);
												TanqueJugador jugador2(40, 4, 2);
												TanqueJugador jugador3(20, 4, 2);
												TanqueJugador jugador4(60, 4, 2);

												std::list <TanqueJugador*> a2;
												a2.push_back(&jugador1);
												a2.push_back(&jugador2);
												a2.push_back(&jugador3);
												a2.push_back(&jugador4);

												TanqueJugador *juga1 = &jugador1;
												TanqueJugador *juga2 = &jugador2;
												TanqueJugador *juga3 = &jugador3;
												TanqueJugador *juga4 = &jugador4;


												jugador1.dibujarTanqueAI(a);
												jugador2.dibujarTanqueAI(a);
												jugador3.dibujarTanqueAI(a);
												jugador4.dibujarTanqueAI(a);

												list<Bomba*> bombas;
												Bomba bomba1(70, 25);
												bombas.push_back(&bomba1);
												bomba1.Dibujar();
												int niv2Speed = 1000;
												int *sleepniv2 = &niv2Speed;
												int v = 1;
												thread t3(&TanqueJugador::iniciarIA, juga2, ref(a2), ref(muros2), ref(restantes2), ref(niv2Speed), ref(v), ref(bombas),ref(pausar));
												t3.detach();
												Sleep(250);

												thread t4(&TanqueJugador::iniciarIA, juga3, ref(a2), ref(muros2), ref(restantes2), ref(niv2Speed), ref(v), ref(bombas),ref(pausar));
												t4.detach();

												Sleep(250);

												thread t5(&TanqueJugador::iniciarIA, juga4, ref(a2), ref(muros2), ref(restantes2), ref(niv2Speed), ref(v), ref(bombas),ref(pausar));
												t5.detach();
												Sleep(250);
												bool BF9 = false;
												while (true)
												{
													if (GetAsyncKeyState(VK_UP))
													{


														if (jugador1.MoverArribaAI(a2, muros2, bombas))
														{
															jugador1.displayvida();
														}

														Sleep(25);
													}
													if (GetAsyncKeyState(VK_DOWN))
													{

														if (jugador1.MoverAbajoAI(a2, muros2, bombas))
														{
															jugador1.displayvida();
														}
														Sleep(25);
													}

													if (GetAsyncKeyState(VK_LEFT))
													{

														if (jugador1.MoverIzquierdaAI(a2, muros2, bombas))
														{
															jugador1.displayvida();
														}
														Sleep(25);
													}

													if (GetAsyncKeyState(VK_RIGHT))
													{

														if (jugador1.MoverDerechaAI(a2, muros2, bombas))
														{
															jugador1.displayvida();
														}
														Sleep(25);
													}
													if (GetAsyncKeyState(VK_P))
													{
														pausar = true;
														Sleep(10150);
														pausar = false;
													}

													if (GetAsyncKeyState(VK_SPACE))
													{

														thread t1(&TanqueJugador::DispararAI2, jugador1, ref(a2), ref(muros2), ref(restantes2), ref(disparando), ref(PuntuacionTanqueNiv2), ref(puntuacion));
														t1.detach();


														Sleep(150);
													}

													Sleep(250);

													while (restantes2 <= 0)
													{
														system("cls");


														cout << "BOSS FIGHT 2";
														Sleep(1500);
														system("cls");
														gotoxy(45, 0);
														cout << "BOSS FIGHT 2";
														int restantes2 = 3;
														if (true)
														{
															//NIVEL 2222 master



															for (int y = 1; y < 30; y++)
															{
																for (int x = 0; x < 120; x++)
																{
																	if (y == 1 || y == 29)
																	{

																		muro mur(x, y);
																		mur.dibujarmuro();
																		//muros.push_back(&mur);
																	}
																	else if (x == 0 || x == 119)
																	{
																		muro mur(x, y);
																		mur.dibujarmuro();
																		//muros.push_back(mur);
																	}
																	else { gotoxy(x, y); puts(" "); }

																}

															}
															muro2_1.dibujarmuro();
															muro2_2.dibujarmuro();
															muro2_3.dibujarmuro();
															muro2_4.dibujarmuro();
															muro2_5.dibujarmuro();
															muro2_6.dibujarmuro();
															muro2_7.dibujarmuro();
															muro2_8.dibujarmuro();
															muro2_9.dibujarmuro();
															muro2_10.dibujarmuro();
															muro2_11.dibujarmuro();
															muro2_12.dibujarmuro();
															muro2_13.dibujarmuro();
															muro2_14.dibujarmuro();
															muro2_15.dibujarmuro();
															muro2_16.dibujarmuro();
															muro2_17.dibujarmuro();
															muro2_18.dibujarmuro();
															muro2_19.dibujarmuro();
															muro2_20.dibujarmuro();
															muro2_21.dibujarmuro();
															muro2_22.dibujarmuro();
															muro2_23.dibujarmuro();
															muro2_24.dibujarmuro();
															muro2_25.dibujarmuro();
															muro2_26.dibujarmuro();
															muro2_27.dibujarmuro();
															muro2_28.dibujarmuro();
															muro2_29.dibujarmuro();
															muro2_30.dibujarmuro();
															muro2_31.dibujarmuro();
															muro2_32.dibujarmuro();
															muro2_33.dibujarmuro();
															muro2_34.dibujarmuro();

															muro17.dibujarmuro();
															muro18.dibujarmuro();
															muro19.dibujarmuro();
															muro20.dibujarmuro();
															muro21.dibujarmuro();
															muro22.dibujarmuro();
															muro23.dibujarmuro();
															muro24.dibujarmuro();
															muro25.dibujarmuro();
															muro26.dibujarmuro();
															muro27.dibujarmuro();
															muro28.dibujarmuro();


															iniciado2 = true;

															TanqueJugador jugador1(65, 26, 1, 3, 3, 0, 59, 28);
															TanqueJugador jugador2(205, 4, 2);
															TanqueJugador jugador3(205, 4, 2);
															TanqueJugador jugador4(60, 4, 2, 3, 60, 0);

															std::list <TanqueJugador*> a2;
															a2.push_back(&jugador1);
															a2.push_back(&jugador2);
															a2.push_back(&jugador3);
															a2.push_back(&jugador4);

															TanqueJugador *juga1 = &jugador1;
															TanqueJugador *juga2 = &jugador2;
															TanqueJugador *juga3 = &jugador3;
															TanqueJugador *juga4 = &jugador4;


															jugador1.dibujarTanqueAI(a);

															jugador4.dibujarTanqueAI(a);

															list<Bomba*> bombas;
															Bomba bomba1(70, 25);
															bombas.push_back(&bomba1);
															bomba1.Dibujar();

															int niv2Speed = 100;
															int *sleepniv2 = &niv2Speed;
															int v = 0;


															thread t5(&TanqueJugador::iniciarIA, juga4, ref(a2), ref(muros2), ref(restantes2), ref(niv2Speed), ref(v), ref(bombas),ref(pausar));
															t5.detach();
															Sleep(250);
															bool BF0 = false;

															while (true)
															{
																if (GetAsyncKeyState(VK_UP))
																{


																	if (jugador1.MoverArribaAI(a2, muros2,bombas))
																	{
																		jugador1.displayvida();
																	}

																	Sleep(25);
																}
																if (GetAsyncKeyState(VK_DOWN))
																{

																	if (jugador1.MoverAbajoAI(a2, muros2, bombas))
																	{
																		jugador1.displayvida();
																	}
																	
																	Sleep(25);
																}

																if (GetAsyncKeyState(VK_LEFT))
																{

																	if (jugador1.MoverIzquierdaAI(a2, muros2, bombas))
																	{
																		jugador1.displayvida();
																	}
																	Sleep(25);
																}

																if (GetAsyncKeyState(VK_RIGHT))
																{

																	if (jugador1.MoverDerechaAI(a2, muros2, bombas))
																	{
																		jugador1.displayvida();
																	}
																	Sleep(25);
																}
																if (GetAsyncKeyState(VK_P))
																{
																	pausar = true;
																	Sleep(10150);
																	pausar = false;
																}

																if (GetAsyncKeyState(VK_SPACE))
																{

																	thread t1(&TanqueJugador::DispararAI2, jugador1, ref(a2), ref(muros2), ref(restantes2), ref(disparando), ref(PuntuacionMasterNiv12), ref(puntuacion));
																	t1.detach();


																	Sleep(150);
																}

																Sleep(250);

																while (restantes2 <= 0)
																{
																	// NIVEL 33333333
																	Sleep(500);
																	system("cls");

																	gotoxy(45, 0);
																	cout << "NIVEL 3";
																	int restantes2 = 10;

																	for (int y = 1; y < 30; y++)
																	{
																		for (int x = 0; x < 120; x++)
																		{
																			if (y == 1 || y == 29)
																			{

																				muro mur(x, y);
																				mur.dibujarmuro();
																				//muros.push_back(&mur);
																			}
																			else if (x == 0 || x == 119)
																			{
																				muro mur(x, y);
																				mur.dibujarmuro();
																				//muros.push_back(mur);
																			}
																			else { gotoxy(x, y); puts(" "); }

																		}

																	}

																	
																	//porteria jugador 1

																	muro muro17(60, 28);
																	muro muro18(60, 27);
																	muro muro19(59, 27);
																	muro muro20(58, 27);
																	muro muro21(57, 27);
																	muro muro22(57, 28);


																	//porteria jugador 2
																	muro muro23(60, 1);
																	muro muro24(60, 2);
																	muro muro25(59, 2);
																	muro muro26(58, 2);
																	muro muro27(57, 2);
																	muro muro28(57, 1);

																	//MUROS NIVEL 2

																	muro muro3_1(15, 15);
																	muro muro3_2(16, 15);
																	muro muro3_3(17, 16);
																	muro muro3_4(18, 16);
																	muro muro3_5(19, 17);
																	muro muro3_6(20, 17);
																	muro muro3_7(21, 18);
																	muro muro3_8(22, 18);
																	muro muro3_9(23, 19);
																	muro muro3_10(24, 19);
																	muro muro3_11(25, 20);
																	muro muro3_12(26, 20);
																	muro muro3_13(27, 21);
																	muro muro3_14(28, 21);
																	muro muro3_15(29, 14);
																	muro muro3_16(30, 14);
																	muro muro3_17(31, 13);

																	muro muro3_18(32, 15);
																	muro muro3_19(33, 15);
																	muro muro3_20(34, 15);
																	muro muro3_21(35, 15);
																	muro muro3_22(36, 15);
																	muro muro3_23(37, 15);
																	muro muro3_24(38, 15);
																	muro muro3_25(39, 15);
																	muro muro3_26(40, 15);
																	muro muro3_27(41, 15);
																	muro muro3_28(42, 15);
																	muro muro3_29(43, 15);
																	muro muro3_30(44, 15);
																	muro muro3_31(45, 15);
																	muro muro3_32(46, 15);
																	muro muro3_33(47, 15);
																	muro muro3_34(48, 15);

																	//vector<muro> muros;

																	list<muro*> muros3;
																	//// nuevos muros pushback
																	muros3.push_back(&muro3_1);
																	muros3.push_back(&muro3_2);
																	muros3.push_back(&muro3_3);
																	muros3.push_back(&muro3_4);
																	muros3.push_back(&muro3_5);
																	muros3.push_back(&muro3_6);
																	muros3.push_back(&muro3_7);
																	muros3.push_back(&muro3_8);
																	muros3.push_back(&muro3_9);
																	muros3.push_back(&muro3_10);
																	muros3.push_back(&muro3_11);
																	muros3.push_back(&muro3_12);
																	muros3.push_back(&muro3_13);
																	muros3.push_back(&muro3_14);
																	muros3.push_back(&muro3_15);
																	muros3.push_back(&muro3_16);
																	muros3.push_back(&muro3_17);
																	muros3.push_back(&muro3_18);
																	muros3.push_back(&muro3_19);
																	muros3.push_back(&muro3_20);
																	muros3.push_back(&muro3_21);
																	muros3.push_back(&muro3_22);
																	muros3.push_back(&muro3_23);
																	muros3.push_back(&muro3_24);
																	muros3.push_back(&muro3_25);
																	muros3.push_back(&muro3_26);
																	muros3.push_back(&muro3_27);
																	muros3.push_back(&muro3_28);
																	muros3.push_back(&muro3_29);
																	muros3.push_back(&muro3_30);
																	muros3.push_back(&muro3_31);
																	muros3.push_back(&muro3_32);
																	muros3.push_back(&muro3_33);
																	muros3.push_back(&muro3_34);

																	muros3.push_back(&muro17);
																	muros3.push_back(&muro18);
																	muros3.push_back(&muro19);
																	muros3.push_back(&muro20);
																	muros3.push_back(&muro21);
																	muros3.push_back(&muro22);
																	muros3.push_back(&muro23);
																	muros3.push_back(&muro24);
																	muros3.push_back(&muro25);
																	muros3.push_back(&muro26);
																	muros3.push_back(&muro27);
																	muros3.push_back(&muro28);
																
																	muro3_1.dibujarmuro();
																	muro3_2.dibujarmuro();
																	muro3_3.dibujarmuro();
																	muro3_4.dibujarmuro();
																	muro3_5.dibujarmuro();
																	muro3_6.dibujarmuro();
																	muro3_7.dibujarmuro();
																	muro3_8.dibujarmuro();
																	muro3_9.dibujarmuro();
																	muro3_10.dibujarmuro();
																	muro3_11.dibujarmuro();
																	muro3_12.dibujarmuro();
																	muro3_13.dibujarmuro();
																	muro3_14.dibujarmuro();
																	muro3_15.dibujarmuro();
																	muro3_16.dibujarmuro();
																	muro3_17.dibujarmuro();
																	muro3_18.dibujarmuro();
																	muro3_19.dibujarmuro();
																	muro3_20.dibujarmuro();
																	muro3_21.dibujarmuro();
																	muro3_22.dibujarmuro();
																	muro3_23.dibujarmuro();
																	muro3_24.dibujarmuro();
																	muro3_25.dibujarmuro();
																	muro3_26.dibujarmuro();
																	muro3_27.dibujarmuro();
																	muro3_28.dibujarmuro();
																	muro3_29.dibujarmuro();
																	muro3_30.dibujarmuro();
																	muro3_31.dibujarmuro();
																	muro3_32.dibujarmuro();
																	muro3_33.dibujarmuro();
																	muro3_34.dibujarmuro();

																	muro17.dibujarmuro();
																	muro18.dibujarmuro();
																	muro19.dibujarmuro();
																	muro20.dibujarmuro();
																	muro21.dibujarmuro();
																	muro22.dibujarmuro();
																	muro23.dibujarmuro();
																	muro24.dibujarmuro();
																	muro25.dibujarmuro();
																	muro26.dibujarmuro();
																	muro27.dibujarmuro();
																	muro28.dibujarmuro();

																	TanqueJugador jugador31(65, 26, 1, 3, 3, 0, 59, 28);
																	TanqueJugador jugador32(40, 4, 2);
																	TanqueJugador jugador33(20, 4, 2);
																	TanqueJugador jugador34(60, 4, 2);

																	std::list <TanqueJugador*> a3;
																	a3.push_back(&jugador31);
																	a3.push_back(&jugador32);
																	a3.push_back(&jugador33);
																	a3.push_back(&jugador34);

																	TanqueJugador *juga31 = &jugador31;
																	TanqueJugador *juga32 = &jugador32;
																	TanqueJugador *juga33 = &jugador33;
																	TanqueJugador *juga34 = &jugador34;


																	jugador31.dibujarTanqueAI(a);
																	jugador32.dibujarTanqueAI(a);
																	jugador33.dibujarTanqueAI(a);
																	jugador34.dibujarTanqueAI(a);

																	list<Bomba*> bombas;
																	Bomba bomba1(70, 25);
																	bombas.push_back(&bomba1);
																	bomba1.Dibujar();

																	int niv3Speed = 800;
																	int *sleepniv3 = &niv3Speed;
																	int v = 1;

																	thread t33(&TanqueJugador::iniciarIA, juga32, ref(a3), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																	t33.detach();
																	Sleep(250);

																	thread t34(&TanqueJugador::iniciarIA, juga33, ref(a3), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																	t34.detach();

																	Sleep(250);

																	thread t35(&TanqueJugador::iniciarIA, juga34, ref(a3), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																	t35.detach();
																	Sleep(250);
																	bool BF1 = false;
																	while (true)
																	{
																		if (GetAsyncKeyState(VK_UP))
																		{


																			if (jugador1.MoverArribaAI(a3, muros3, bombas))
																			{
																				jugador1.displayvida();
																			}

																			Sleep(25);
																		}
																		if (GetAsyncKeyState(VK_DOWN))
																		{

																			if (jugador1.MoverAbajoAI(a3, muros3, bombas))
																			{
																				jugador1.displayvida();
																			}
																			Sleep(25);
																		}

																		if (GetAsyncKeyState(VK_LEFT))
																		{

																			if (jugador1.MoverIzquierdaAI(a3, muros3, bombas))
																			{
																				jugador1.displayvida();
																			}
																			Sleep(25);
																		}

																		if (GetAsyncKeyState(VK_RIGHT))
																		{

																			if (jugador1.MoverDerechaAI(a3, muros3, bombas))
																			{
																				jugador1.displayvida();
																			}
																			Sleep(25);
																		}
																		if (GetAsyncKeyState(VK_P))
																		{
																			pausar = true;
																			Sleep(10150);
																			pausar = false;
																		}
																		if (GetAsyncKeyState(VK_SPACE))
																		{

																			thread t1(&TanqueJugador::DispararAI2, jugador1, ref(a3), ref(muros3), ref(restantes2), ref(disparando), ref(PuntuacionTanqueNiv3), ref(puntuacion));
																			t1.detach();


																			Sleep(150);
																		}

																		Sleep(250);
																		while (restantes2 <=0 )
																		{
																			system("cls");
																			cout << "BOSS FIGHT 3";
																			Sleep(1500);
																			system("cls");
																			gotoxy(45, 0);
																			cout << "BOSS FIGHT 3";
																			int restantes2 = 3;
																			if (true)
																			{
																				//NIVEL 33333 master



																				for (int y = 1; y < 30; y++)
																				{
																					for (int x = 0; x < 120; x++)
																					{
																						if (y == 1 || y == 29)
																						{

																							muro mur(x, y);
																							mur.dibujarmuro();
																							//muros.push_back(&mur);
																						}
																						else if (x == 0 || x == 119)
																						{
																							muro mur(x, y);
																							mur.dibujarmuro();
																							//muros.push_back(mur);
																						}
																						else { gotoxy(x, y); puts(" "); }

																					}

																				}
																				muro3_1.dibujarmuro();
																				muro3_2.dibujarmuro();
																				muro3_3.dibujarmuro();
																				muro3_4.dibujarmuro();
																				muro3_5.dibujarmuro();
																				muro3_6.dibujarmuro();
																				muro3_7.dibujarmuro();
																				muro3_8.dibujarmuro();
																				muro3_9.dibujarmuro();
																				muro3_10.dibujarmuro();
																				muro3_11.dibujarmuro();
																				muro3_12.dibujarmuro();
																				muro3_13.dibujarmuro();
																				muro3_14.dibujarmuro();
																				muro3_15.dibujarmuro();
																				muro3_16.dibujarmuro();
																				muro3_17.dibujarmuro();
																				muro3_18.dibujarmuro();
																				muro3_19.dibujarmuro();
																				muro3_20.dibujarmuro();
																				muro3_21.dibujarmuro();
																				muro3_22.dibujarmuro();
																				muro3_23.dibujarmuro();
																				muro3_24.dibujarmuro();
																				muro3_25.dibujarmuro();
																				muro3_26.dibujarmuro();
																				muro3_27.dibujarmuro();
																				muro3_28.dibujarmuro();
																				muro3_29.dibujarmuro();
																				muro3_30.dibujarmuro();
																				muro3_31.dibujarmuro();
																				muro3_32.dibujarmuro();
																				muro3_33.dibujarmuro();
																				muro3_34.dibujarmuro();

																				muro17.dibujarmuro();
																				muro18.dibujarmuro();
																				muro19.dibujarmuro();
																				muro20.dibujarmuro();
																				muro21.dibujarmuro();
																				muro22.dibujarmuro();
																				muro23.dibujarmuro();
																				muro24.dibujarmuro();
																				muro25.dibujarmuro();
																				muro26.dibujarmuro();
																				muro27.dibujarmuro();
																				muro28.dibujarmuro();


																				iniciado2 = true;

																				TanqueJugador jugador1(65, 26, 1, 3, 3, 0, 59, 28);
																				TanqueJugador jugador2(205, 4, 2);
																				TanqueJugador jugador3(205, 4, 2);
																				TanqueJugador jugador4(60, 4, 2, 3, 60, 0);

																				std::list <TanqueJugador*> a2;
																				a2.push_back(&jugador1);
																				a2.push_back(&jugador2);
																				a2.push_back(&jugador3);
																				a2.push_back(&jugador4);

																				TanqueJugador *juga1 = &jugador1;
																				TanqueJugador *juga2 = &jugador2;
																				TanqueJugador *juga3 = &jugador3;
																				TanqueJugador *juga4 = &jugador4;

																				list<Bomba*> bombas;
																				Bomba bomba1(70, 25);
																				bombas.push_back(&bomba1);
																				bomba1.Dibujar();
																				jugador1.dibujarTanqueAI(a2);

																				jugador4.dibujarTanqueAI(a2);

																				int niv2Speed = 100;
																				int *sleepniv2 = &niv2Speed;
																				int v = 0;


																				thread t5(&TanqueJugador::iniciarIA, juga4, ref(a2), ref(muros3), ref(restantes2), ref(niv2Speed), ref(v), ref(bombas),ref(pausar));
																				t5.detach();
																				Sleep(250);
																				bool BF2 = false;
																				while (true)
																				{
																					if (GetAsyncKeyState(VK_UP))
																					{


																						if (jugador1.MoverArribaAI(a2, muros3,bombas))
																						{
																							jugador1.displayvida();
																						}

																						Sleep(25);
																					}
																					if (GetAsyncKeyState(VK_DOWN))
																					{

																						if (jugador1.MoverAbajoAI(a2, muros3, bombas))
																						{
																							jugador1.displayvida();
																						}
																						Sleep(25);
																					}

																					if (GetAsyncKeyState(VK_LEFT))
																					{

																						if (jugador1.MoverIzquierdaAI(a2, muros3, bombas))
																						{
																							jugador1.displayvida();
																						}
																						Sleep(25);
																					}

																					if (GetAsyncKeyState(VK_RIGHT))
																					{

																						if (jugador1.MoverDerechaAI(a2, muros3, bombas))
																						{
																							jugador1.displayvida();
																						}
																						Sleep(25);
																					}

																					if (GetAsyncKeyState(VK_SPACE))
																					{

																						thread t1(&TanqueJugador::DispararAI2, jugador1, ref(a2), ref(muros3), ref(restantes2), ref(disparando), ref(PuntuacionMasterNiv34), ref(puntuacion));
																						t1.detach();


																						Sleep(150);
																					}
																					Sleep(250);
																					while (restantes2 <= 0)
																					{
																						//NIVEL 444444
																						Sleep(500);
																						system("cls");

																						gotoxy(45, 0);
																						cout << "NIVEL 4";
																						int restantes2 = 12;

																						for (int y = 1; y < 30; y++)
																						{
																							for (int x = 0; x < 120; x++)
																							{
																								if (y == 1 || y == 29)
																								{

																									muro mur(x, y);
																									mur.dibujarmuro();
																									//muros.push_back(&mur);
																								}
																								else if (x == 0 || x == 119)
																								{
																									muro mur(x, y);
																									mur.dibujarmuro();
																									//muros.push_back(mur);
																								}
																								else { gotoxy(x, y); puts(" "); }

																							}

																						}


																						//porteria jugador 1

																						muro muro17(60, 28);
																						muro muro18(60, 27);
																						muro muro19(59, 27);
																						muro muro20(58, 27);
																						muro muro21(57, 27);
																						muro muro22(57, 28);


																						//porteria jugador 2
																						muro muro23(60, 1);
																						muro muro24(60, 2);
																						muro muro25(59, 2);
																						muro muro26(58, 2);
																						muro muro27(57, 2);
																						muro muro28(57, 1);

																						//MUROS NIVEL 2

																						muro muro3_1(15, 15);
																						muro muro3_2(16, 15);
																						muro muro3_3(17, 16);
																						muro muro3_4(18, 16);
																						muro muro3_5(19, 17);
																						muro muro3_6(20, 17);
																						muro muro3_7(21, 18);
																						muro muro3_8(22, 18);
																						muro muro3_9(23, 19);
																						muro muro3_10(24, 19);
																						muro muro3_11(25, 20);
																						muro muro3_12(26, 20);
																						muro muro3_13(27, 21);
																						muro muro3_14(28, 21);
																						muro muro3_15(29, 14);
																						muro muro3_16(30, 14);
																						muro muro3_17(31, 13);

																						muro muro3_18(32, 15);
																						muro muro3_19(33, 15);
																						muro muro3_20(34, 15);
																						muro muro3_21(35, 15);
																						muro muro3_22(36, 15);
																						muro muro3_23(37, 15);
																						muro muro3_24(38, 15);
																						muro muro3_25(39, 15);
																						muro muro3_26(40, 15);
																						muro muro3_27(41, 15);
																						muro muro3_28(42, 15);
																						muro muro3_29(43, 15);
																						muro muro3_30(44, 15);
																						muro muro3_31(45, 15);
																						muro muro3_32(46, 15);
																						muro muro3_33(47, 15);
																						muro muro3_34(48, 15);

																						//vector<muro> muros;

																						list<muro*> muros3;
																						//// nuevos muros pushback
																						muros3.push_back(&muro3_1);
																						muros3.push_back(&muro3_2);
																						muros3.push_back(&muro3_3);
																						muros3.push_back(&muro3_4);
																						muros3.push_back(&muro3_5);
																						muros3.push_back(&muro3_6);
																						muros3.push_back(&muro3_7);
																						muros3.push_back(&muro3_8);
																						muros3.push_back(&muro3_9);
																						muros3.push_back(&muro3_10);
																						muros3.push_back(&muro3_11);
																						muros3.push_back(&muro3_12);
																						muros3.push_back(&muro3_13);
																						muros3.push_back(&muro3_14);
																						muros3.push_back(&muro3_15);
																						muros3.push_back(&muro3_16);
																						muros3.push_back(&muro3_17);
																						muros3.push_back(&muro3_18);
																						muros3.push_back(&muro3_19);
																						muros3.push_back(&muro3_20);
																						muros3.push_back(&muro3_21);
																						muros3.push_back(&muro3_22);
																						muros3.push_back(&muro3_23);
																						muros3.push_back(&muro3_24);
																						muros3.push_back(&muro3_25);
																						muros3.push_back(&muro3_26);
																						muros3.push_back(&muro3_27);
																						muros3.push_back(&muro3_28);
																						muros3.push_back(&muro3_29);
																						muros3.push_back(&muro3_30);
																						muros3.push_back(&muro3_31);
																						muros3.push_back(&muro3_32);
																						muros3.push_back(&muro3_33);
																						muros3.push_back(&muro3_34);

																						muros3.push_back(&muro17);
																						muros3.push_back(&muro18);
																						muros3.push_back(&muro19);
																						muros3.push_back(&muro20);
																						muros3.push_back(&muro21);
																						muros3.push_back(&muro22);
																						muros3.push_back(&muro23);
																						muros3.push_back(&muro24);
																						muros3.push_back(&muro25);
																						muros3.push_back(&muro26);
																						muros3.push_back(&muro27);
																						muros3.push_back(&muro28);

																						muro3_1.dibujarmuro();
																						muro3_2.dibujarmuro();
																						muro3_3.dibujarmuro();
																						muro3_4.dibujarmuro();
																						muro3_5.dibujarmuro();
																						muro3_6.dibujarmuro();
																						muro3_7.dibujarmuro();
																						muro3_8.dibujarmuro();
																						muro3_9.dibujarmuro();
																						muro3_10.dibujarmuro();
																						muro3_11.dibujarmuro();
																						muro3_12.dibujarmuro();
																						muro3_13.dibujarmuro();
																						muro3_14.dibujarmuro();
																						muro3_15.dibujarmuro();
																						muro3_16.dibujarmuro();
																						muro3_17.dibujarmuro();
																						muro3_18.dibujarmuro();
																						muro3_19.dibujarmuro();
																						muro3_20.dibujarmuro();
																						muro3_21.dibujarmuro();
																						muro3_22.dibujarmuro();
																						muro3_23.dibujarmuro();
																						muro3_24.dibujarmuro();
																						muro3_25.dibujarmuro();
																						muro3_26.dibujarmuro();
																						muro3_27.dibujarmuro();
																						muro3_28.dibujarmuro();
																						muro3_29.dibujarmuro();
																						muro3_30.dibujarmuro();
																						muro3_31.dibujarmuro();
																						muro3_32.dibujarmuro();
																						muro3_33.dibujarmuro();
																						muro3_34.dibujarmuro();

																						muro17.dibujarmuro();
																						muro18.dibujarmuro();
																						muro19.dibujarmuro();
																						muro20.dibujarmuro();
																						muro21.dibujarmuro();
																						muro22.dibujarmuro();
																						muro23.dibujarmuro();
																						muro24.dibujarmuro();
																						muro25.dibujarmuro();
																						muro26.dibujarmuro();
																						muro27.dibujarmuro();
																						muro28.dibujarmuro();

																						TanqueJugador jugador41(65, 26, 1, 3, 3, 0, 59, 28);
																						TanqueJugador jugador42(40, 4, 2);
																						TanqueJugador jugador43(20, 4, 2);
																						TanqueJugador jugador44(60, 4, 2);

																						std::list <TanqueJugador*> a4;
																						a4.push_back(&jugador41);
																						a4.push_back(&jugador42);
																						a4.push_back(&jugador43);
																						a4.push_back(&jugador44);

																						TanqueJugador *juga41 = &jugador41;
																						TanqueJugador *juga42 = &jugador42;
																						TanqueJugador *juga43 = &jugador43;
																						TanqueJugador *juga44 = &jugador44;


																						jugador41.dibujarTanqueAI(a);
																						jugador42.dibujarTanqueAI(a);
																						jugador43.dibujarTanqueAI(a);
																						jugador44.dibujarTanqueAI(a);

																						int niv3Speed = 650;
																						int *sleepniv3 = &niv3Speed;
																						int v = 1;

																						thread t43(&TanqueJugador::iniciarIA, juga42, ref(a4), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																						t43.detach();
																						Sleep(250);

																						thread t44(&TanqueJugador::iniciarIA, juga43, ref(a4), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																						t44.detach();

																						Sleep(250);

																						thread t45(&TanqueJugador::iniciarIA, juga44, ref(a4), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																						t45.detach();
																						Sleep(250);
																						bool BF3 = false;
																						while (true)
																						{
																							if (GetAsyncKeyState(VK_UP))
																							{


																								if (jugador41.MoverArribaAI(a4, muros3, bombas))
																								{
																									jugador41.displayvida();
																								}

																								Sleep(25);
																							}
																							if (GetAsyncKeyState(VK_DOWN))
																							{

																								if (jugador41.MoverAbajoAI(a4, muros3, bombas))
																								{
																									jugador41.displayvida();
																								}
																								Sleep(25);
																							}

																							if (GetAsyncKeyState(VK_LEFT))
																							{

																								if (jugador41.MoverIzquierdaAI(a4, muros3, bombas))
																								{
																									jugador41.displayvida();
																								}
																								Sleep(25);
																							}

																							if (GetAsyncKeyState(VK_RIGHT))
																							{

																								if (jugador41.MoverDerechaAI(a4, muros3, bombas))
																								{
																									jugador41.displayvida();
																								}
																								Sleep(25);
																							}
																							if (GetAsyncKeyState(VK_P))
																							{
																								pausar = true;
																								Sleep(10150);
																								pausar = false;
																							}
																							if (GetAsyncKeyState(VK_SPACE))
																							{

																								thread t1(&TanqueJugador::DispararAI2, jugador41, ref(a4), ref(muros3), ref(restantes2), ref(disparando), ref(PuntuacionTanqueNiv4), ref(puntuacion));
																								t1.detach();


																								Sleep(150);
																							}

																							Sleep(250);

																							while (restantes2 <= 0)
																							{
																									system("cls");
																									cout << "BOSS FIGHT 4";
																									Sleep(1500);
																									system("cls");
																									gotoxy(45, 0);
																									cout << "BOSS FIGHT 4";
																									int restantes2 = 3;
																									bool BF4 = false;
																								if (true)
																								{
																									//NIVEL 44444 master



																									for (int y = 1; y < 30; y++)
																									{
																										for (int x = 0; x < 120; x++)
																										{
																											if (y == 1 || y == 29)
																											{

																												muro mur(x, y);
																												mur.dibujarmuro();
																												//muros.push_back(&mur);
																											}
																											else if (x == 0 || x == 119)
																											{
																												muro mur(x, y);
																												mur.dibujarmuro();
																												//muros.push_back(mur);
																											}
																											else { gotoxy(x, y); puts(" "); }

																										}

																									}
																									muro3_1.dibujarmuro();
																									muro3_2.dibujarmuro();
																									muro3_3.dibujarmuro();
																									muro3_4.dibujarmuro();
																									muro3_5.dibujarmuro();
																									muro3_6.dibujarmuro();
																									muro3_7.dibujarmuro();
																									muro3_8.dibujarmuro();
																									muro3_9.dibujarmuro();
																									muro3_10.dibujarmuro();
																									muro3_11.dibujarmuro();
																									muro3_12.dibujarmuro();
																									muro3_13.dibujarmuro();
																									muro3_14.dibujarmuro();
																									muro3_15.dibujarmuro();
																									muro3_16.dibujarmuro();
																									muro3_17.dibujarmuro();
																									muro3_18.dibujarmuro();
																									muro3_19.dibujarmuro();
																									muro3_20.dibujarmuro();
																									muro3_21.dibujarmuro();
																									muro3_22.dibujarmuro();
																									muro3_23.dibujarmuro();
																									muro3_24.dibujarmuro();
																									muro3_25.dibujarmuro();
																									muro3_26.dibujarmuro();
																									muro3_27.dibujarmuro();
																									muro3_28.dibujarmuro();
																									muro3_29.dibujarmuro();
																									muro3_30.dibujarmuro();
																									muro3_31.dibujarmuro();
																									muro3_32.dibujarmuro();
																									muro3_33.dibujarmuro();
																									muro3_34.dibujarmuro();

																									muro17.dibujarmuro();
																									muro18.dibujarmuro();
																									muro19.dibujarmuro();
																									muro20.dibujarmuro();
																									muro21.dibujarmuro();
																									muro22.dibujarmuro();
																									muro23.dibujarmuro();
																									muro24.dibujarmuro();
																									muro25.dibujarmuro();
																									muro26.dibujarmuro();
																									muro27.dibujarmuro();
																									muro28.dibujarmuro();


																									iniciado2 = true;

																									TanqueJugador jugador1(65, 26, 1, 3, 3, 0, 59, 28);
																									TanqueJugador jugador2(205, 4, 2);
																									TanqueJugador jugador3(205, 4, 2);
																									TanqueJugador jugador4(60, 4, 2, 3, 60, 0);

																									std::list <TanqueJugador*> a2;
																									a2.push_back(&jugador1);
																									a2.push_back(&jugador2);
																									a2.push_back(&jugador3);
																									a2.push_back(&jugador4);

																									TanqueJugador *juga1 = &jugador1;
																									TanqueJugador *juga2 = &jugador2;
																									TanqueJugador *juga3 = &jugador3;
																									TanqueJugador *juga4 = &jugador4;


																									jugador1.dibujarTanqueAI(a2);

																									jugador4.dibujarTanqueAI(a2);
																									list<Bomba*> bombas;
																									Bomba bomba1(70, 25);
																									bombas.push_back(&bomba1);
																									bomba1.Dibujar();

																									int niv2Speed = 100;
																									int *sleepniv2 = &niv2Speed;
																									int v = 0;


																									thread t5(&TanqueJugador::iniciarIA, juga4, ref(a2), ref(muros3), ref(restantes2), ref(niv2Speed), ref(v), ref(bombas),ref(pausar));
																									t5.detach();
																									Sleep(250);
																									bool prueba = false;
																									while (true)
																									{
																										if (GetAsyncKeyState(VK_UP))
																										{

																											
																											if (jugador1.MoverArribaAI(a2, muros3, bombas))
																											{
																												jugador1.displayvida();
																											}

																											Sleep(25);
																										}
																										if (GetAsyncKeyState(VK_DOWN))
																										{

																											if (jugador1.MoverAbajoAI(a2, muros3, bombas))
																											{
																												jugador1.displayvida();
																											}
																											Sleep(25);
																										}

																										if (GetAsyncKeyState(VK_LEFT))
																										{

																											if (jugador1.MoverIzquierdaAI(a2, muros3, bombas))
																											{
																												jugador1.displayvida();
																											}
																											Sleep(25);
																										}

																										if (GetAsyncKeyState(VK_RIGHT))
																										{

																											if (jugador1.MoverDerechaAI(a2, muros3, bombas))
																											{
																												jugador1.displayvida();
																											}
																											Sleep(25);
																										}
																										if (GetAsyncKeyState(VK_P))
																										{
																											pausar = true;
																											Sleep(10150);
																											pausar = false;
																										}
																										if (GetAsyncKeyState(VK_SPACE))
																										{

																											thread t1(&TanqueJugador::DispararAI2, jugador1, ref(a2), ref(muros3), ref(restantes2), ref(disparando), ref(PuntuacionMasterNiv34), ref(puntuacion));
																											t1.detach();


																											Sleep(150);
																										}
																										Sleep(250);

																										if (restantes2 <= 0)
																										{
																											prueba = true;
																										}

																										while (prueba==true)
																										{
																											// NIVEL 55555555555555555555555555555555555
																											Sleep(500);
																											system("cls");

																											gotoxy(45, 0);
																											cout << "NIVEL 5";
																											int restantes2 = 15;

																											for (int y = 1; y < 30; y++)
																											{
																												for (int x = 0; x < 120; x++)
																												{
																													if (y == 1 || y == 29)
																													{

																														muro mur(x, y);
																														mur.dibujarmuro();
																														//muros.push_back(&mur);
																													}
																													else if (x == 0 || x == 119)
																													{
																														muro mur(x, y);
																														mur.dibujarmuro();
																														//muros.push_back(mur);
																													}
																													else { gotoxy(x, y); puts(" "); }

																												}

																											}


																											//porteria jugador 1

																											muro muro17(60, 28);
																											muro muro18(60, 27);
																											muro muro19(59, 27);
																											muro muro20(58, 27);
																											muro muro21(57, 27);
																											muro muro22(57, 28);


																											//porteria jugador 2
																											muro muro23(60, 1);
																											muro muro24(60, 2);
																											muro muro25(59, 2);
																											muro muro26(58, 2);
																											muro muro27(57, 2);
																											muro muro28(57, 1);

																											//MUROS NIVEL 2

																											muro muro3_1(35, 15);
																											muro muro3_2(36, 15);
																											muro muro3_3(37, 16);
																											muro muro3_4(38, 16);
																											muro muro3_5(39, 17);
																											muro muro3_6(30, 17);
																											muro muro3_7(41, 18);
																											muro muro3_8(42, 18);
																											muro muro3_9(43, 19);
																											muro muro3_10(44, 19);
																											muro muro3_11(45, 20);
																											muro muro3_12(46, 20);
																											muro muro3_13(47, 21);
																											muro muro3_14(48, 21);
																											muro muro3_15(49, 14);
																											muro muro3_16(50, 14);
																											muro muro3_17(51, 13);

																											muro muro3_18(52, 15);
																											muro muro3_19(53, 15);
																											muro muro3_20(54, 15);
																											muro muro3_21(55, 15);
																											muro muro3_22(56, 15);
																											muro muro3_23(57, 15);
																											muro muro3_24(58, 15);
																											muro muro3_25(59, 15);
																											muro muro3_26(60, 15);
																											muro muro3_27(61, 15);
																											muro muro3_28(62, 15);
																											muro muro3_29(63, 15);
																											muro muro3_30(64, 15);
																											muro muro3_31(65, 15);
																											muro muro3_32(66, 15);
																											muro muro3_33(67, 15);
																											muro muro3_34(68, 15);

																											//vector<muro> muros;

																											list<muro*> muros3;
																											//// nuevos muros pushback
																											muros3.push_back(&muro3_1);
																											muros3.push_back(&muro3_2);
																											muros3.push_back(&muro3_3);
																											muros3.push_back(&muro3_4);
																											muros3.push_back(&muro3_5);
																											muros3.push_back(&muro3_6);
																											muros3.push_back(&muro3_7);
																											muros3.push_back(&muro3_8);
																											muros3.push_back(&muro3_9);
																											muros3.push_back(&muro3_10);
																											muros3.push_back(&muro3_11);
																											muros3.push_back(&muro3_12);
																											muros3.push_back(&muro3_13);
																											muros3.push_back(&muro3_14);
																											muros3.push_back(&muro3_15);
																											muros3.push_back(&muro3_16);
																											muros3.push_back(&muro3_17);
																											muros3.push_back(&muro3_18);
																											muros3.push_back(&muro3_19);
																											muros3.push_back(&muro3_20);
																											muros3.push_back(&muro3_21);
																											muros3.push_back(&muro3_22);
																											muros3.push_back(&muro3_23);
																											muros3.push_back(&muro3_24);
																											muros3.push_back(&muro3_25);
																											muros3.push_back(&muro3_26);
																											muros3.push_back(&muro3_27);
																											muros3.push_back(&muro3_28);
																											muros3.push_back(&muro3_29);
																											muros3.push_back(&muro3_30);
																											muros3.push_back(&muro3_31);
																											muros3.push_back(&muro3_32);
																											muros3.push_back(&muro3_33);
																											muros3.push_back(&muro3_34);

																											muros3.push_back(&muro17);
																											muros3.push_back(&muro18);
																											muros3.push_back(&muro19);
																											muros3.push_back(&muro20);
																											muros3.push_back(&muro21);
																											muros3.push_back(&muro22);
																											muros3.push_back(&muro23);
																											muros3.push_back(&muro24);
																											muros3.push_back(&muro25);
																											muros3.push_back(&muro26);
																											muros3.push_back(&muro27);
																											muros3.push_back(&muro28);

																											muro3_1.dibujarmuro();
																											muro3_2.dibujarmuro();
																											muro3_3.dibujarmuro();
																											muro3_4.dibujarmuro();
																											muro3_5.dibujarmuro();
																											muro3_6.dibujarmuro();
																											muro3_7.dibujarmuro();
																											muro3_8.dibujarmuro();
																											muro3_9.dibujarmuro();
																											muro3_10.dibujarmuro();
																											muro3_11.dibujarmuro();
																											muro3_12.dibujarmuro();
																											muro3_13.dibujarmuro();
																											muro3_14.dibujarmuro();
																											muro3_15.dibujarmuro();
																											muro3_16.dibujarmuro();
																											muro3_17.dibujarmuro();
																											muro3_18.dibujarmuro();
																											muro3_19.dibujarmuro();
																											muro3_20.dibujarmuro();
																											muro3_21.dibujarmuro();
																											muro3_22.dibujarmuro();
																											muro3_23.dibujarmuro();
																											muro3_24.dibujarmuro();
																											muro3_25.dibujarmuro();
																											muro3_26.dibujarmuro();
																											muro3_27.dibujarmuro();
																											muro3_28.dibujarmuro();
																											muro3_29.dibujarmuro();
																											muro3_30.dibujarmuro();
																											muro3_31.dibujarmuro();
																											muro3_32.dibujarmuro();
																											muro3_33.dibujarmuro();
																											muro3_34.dibujarmuro();

																											muro17.dibujarmuro();
																											muro18.dibujarmuro();
																											muro19.dibujarmuro();
																											muro20.dibujarmuro();
																											muro21.dibujarmuro();
																											muro22.dibujarmuro();
																											muro23.dibujarmuro();
																											muro24.dibujarmuro();
																											muro25.dibujarmuro();
																											muro26.dibujarmuro();
																											muro27.dibujarmuro();
																											muro28.dibujarmuro();

																											TanqueJugador jugador41(65, 26, 1, 3, 3, 0, 59, 28);
																											TanqueJugador jugador42(40, 4, 2);
																											TanqueJugador jugador43(20, 4, 2);
																											TanqueJugador jugador44(60, 4, 2);

																											std::list <TanqueJugador*> a4;
																											a4.push_back(&jugador41);
																											a4.push_back(&jugador42);
																											a4.push_back(&jugador43);
																											a4.push_back(&jugador44);

																											TanqueJugador *juga41 = &jugador41;
																											TanqueJugador *juga42 = &jugador42;
																											TanqueJugador *juga43 = &jugador43;
																											TanqueJugador *juga44 = &jugador44;


																											jugador41.dibujarTanqueAI(a);
																											jugador42.dibujarTanqueAI(a);
																											jugador43.dibujarTanqueAI(a);
																											jugador44.dibujarTanqueAI(a);

																											list<Bomba*> bombas;
																											Bomba bomba1(70, 25);
																											bombas.push_back(&bomba1);
																											bomba1.Dibujar();

																											int niv3Speed = 450;
																											int *sleepniv3 = &niv3Speed;
																											int v = 1;

																											thread t43(&TanqueJugador::iniciarIA, juga42, ref(a4), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																											t43.detach();
																											Sleep(250);

																											thread t44(&TanqueJugador::iniciarIA, juga43, ref(a4), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																											t44.detach();

																											Sleep(250);

																											thread t45(&TanqueJugador::iniciarIA, juga44, ref(a4), ref(muros3), ref(restantes2), ref(niv3Speed), ref(v), ref(bombas),ref(pausar));
																											t45.detach();
																											Sleep(250);
																											bool N5 = false;
																											while (true)
																											{
																												if (GetAsyncKeyState(VK_UP))
																												{


																													if (jugador41.MoverArribaAI(a4, muros3, bombas))
																													{
																														jugador41.displayvida();
																													}

																													Sleep(25);
																												}
																												if (GetAsyncKeyState(VK_DOWN))
																												{

																													if (jugador41.MoverAbajoAI(a4, muros3, bombas))
																													{
																														jugador41.displayvida();
																													}
																													Sleep(25);
																												}

																												if (GetAsyncKeyState(VK_LEFT))
																												{

																													if (jugador41.MoverIzquierdaAI(a4, muros3, bombas))
																													{
																														jugador41.displayvida();
																												    }
																													Sleep(25);
																												}

																												if (GetAsyncKeyState(VK_RIGHT))
																												{

																													if (jugador41.MoverDerechaAI(a4, muros3, bombas))
																													{
																														jugador41.displayvida();
																													}
																													Sleep(25);
																												}
																												if (GetAsyncKeyState(VK_P))
																												{
																													pausar = true;
																													Sleep(10150);
																													pausar = false;
																												}

																												if (GetAsyncKeyState(VK_SPACE))
																												{

																													thread t1(&TanqueJugador::DispararAI2, jugador41, ref(a4), ref(muros3), ref(restantes2), ref(disparando), ref(PuntuacionTanqueNiv5), ref(puntuacion));
																													t1.detach();


																													Sleep(150);
																												}

																												Sleep(250);

																												while (restantes2 <= 0)
																												{
																													bool BF5 = false;
																													system("cls");
																													cout << "BOSS FIGHT 5";
																													Sleep(1500);
																													system("cls");
																													gotoxy(45, 0);
																													cout << "BOSS FIGHT 5";
																													int restantes2 = 3;

																													for (int y = 1; y < 30; y++)
																													{
																														for (int x = 0; x < 120; x++)
																														{
																															if (y == 1 || y == 29)
																															{

																																muro mur(x, y);
																																mur.dibujarmuro();
																																//muros.push_back(&mur);
																															}
																															else if (x == 0 || x == 119)
																															{
																																muro mur(x, y);
																																mur.dibujarmuro();
																																//muros.push_back(mur);
																															}
																															else { gotoxy(x, y); puts(" "); }

																														}

																													}
																													muro3_1.dibujarmuro();
																													muro3_2.dibujarmuro();
																													muro3_3.dibujarmuro();
																													muro3_4.dibujarmuro();
																													muro3_5.dibujarmuro();
																													muro3_6.dibujarmuro();
																													muro3_7.dibujarmuro();
																													muro3_8.dibujarmuro();
																													muro3_9.dibujarmuro();
																													muro3_10.dibujarmuro();
																													muro3_11.dibujarmuro();
																													muro3_12.dibujarmuro();
																													muro3_13.dibujarmuro();
																													muro3_14.dibujarmuro();
																													muro3_15.dibujarmuro();
																													muro3_16.dibujarmuro();
																													muro3_17.dibujarmuro();
																													muro3_18.dibujarmuro();
																													muro3_19.dibujarmuro();
																													muro3_20.dibujarmuro();
																													muro3_21.dibujarmuro();
																													muro3_22.dibujarmuro();
																													muro3_23.dibujarmuro();
																													muro3_24.dibujarmuro();
																													muro3_25.dibujarmuro();
																													muro3_26.dibujarmuro();
																													muro3_27.dibujarmuro();
																													muro3_28.dibujarmuro();
																													muro3_29.dibujarmuro();
																													muro3_30.dibujarmuro();
																													muro3_31.dibujarmuro();
																													muro3_32.dibujarmuro();
																													muro3_33.dibujarmuro();
																													muro3_34.dibujarmuro();

																													muro17.dibujarmuro();
																													muro18.dibujarmuro();
																													muro19.dibujarmuro();
																													muro20.dibujarmuro();
																													muro21.dibujarmuro();
																													muro22.dibujarmuro();
																													muro23.dibujarmuro();
																													muro24.dibujarmuro();
																													muro25.dibujarmuro();
																													muro26.dibujarmuro();
																													muro27.dibujarmuro();
																													muro28.dibujarmuro();


																													iniciado2 = true;

																													TanqueJugador jugador1(65, 26, 1, 3, 3, 0, 59, 28);
																													TanqueJugador jugador2(205, 4, 2);
																													TanqueJugador jugador3(205, 4, 2);
																													TanqueJugador jugador4(60, 4, 2, 3, 60, 0);

																													std::list <TanqueJugador*> a2;
																													a2.push_back(&jugador1);
																													a2.push_back(&jugador2);
																													a2.push_back(&jugador3);
																													a2.push_back(&jugador4);

																													TanqueJugador *juga1 = &jugador1;
																													TanqueJugador *juga2 = &jugador2;
																													TanqueJugador *juga3 = &jugador3;
																													TanqueJugador *juga4 = &jugador4;


																													jugador1.dibujarTanqueAI(a2);

																													jugador4.dibujarTanqueAI(a2);
																													list<Bomba*> bombas;
																													Bomba bomba1(70, 25);
																													bombas.push_back(&bomba1);
																													bomba1.Dibujar();

																													int niv2Speed = 10;
																													int *sleepniv2 = &niv2Speed;
																													int v = 0;


																													thread t5(&TanqueJugador::iniciarIA, juga4, ref(a2), ref(muros3), ref(restantes2), ref(niv2Speed), ref(v), ref(bombas),ref(pausar));
																													t5.detach();
																													Sleep(250);

																													while (true)
																													{
																														if (GetAsyncKeyState(VK_UP))
																														{


																															if (jugador1.MoverArribaAI(a2, muros3,bombas))
																															{
																																jugador1.displayvida();
																															}

																															Sleep(25);
																														}
																														if (GetAsyncKeyState(VK_DOWN))
																														{

																															if (jugador1.MoverAbajoAI(a2, muros3, bombas))
																															{
																																jugador1.displayvida();
																															}
																															Sleep(25);
																														}

																														if (GetAsyncKeyState(VK_LEFT))
																														{

																															if (jugador1.MoverIzquierdaAI(a2, muros3, bombas))
																															{
																																jugador1.displayvida();
																															}
																															Sleep(25);
																														}

																														if (GetAsyncKeyState(VK_RIGHT))
																														{

																															if (jugador1.MoverDerechaAI(a2, muros3, bombas))
																															{
																																jugador1.displayvida();
																															}
																															Sleep(25);
																														}
																														if (GetAsyncKeyState(VK_P))
																														{
																															pausar = true;
																															Sleep(10150);
																															pausar = false;
																														}
																														if (GetAsyncKeyState(VK_SPACE))
																														{

																															thread t1(&TanqueJugador::DispararAI2, jugador1, ref(a2), ref(muros3), ref(restantes2),ref(disparando), ref(PuntuacionMaasterNiv5), ref(puntuacion));
																															t1.detach();


																															Sleep(150);
																														}

																														if (restantes2 <= 0)
																														{
																															system("cls");
																															seleccion = 0;
																															BF5 = true;
																															N5 = true;
																															break;
																														}
																														Sleep(250);
																														
																													}
																													
																													Sleep(1500);
																													if (BF5)
																													{
																														
																														N5 = true;
																														break;
																														
																													}
																												
																													
																												}
																												
																												
																												if (N5)
																												{
																													prueba = false;
																													
																													break;
																												}
																											}

																											if (N5)
																											{

																												
																												break;
																											}
																										}

																										if (BF4)
																										{
																											
																											break;
																										}
																										
																									}
																								}

																								if (BF4)
																								{
																									BF3 = true;
																									break;
																								}
																							}
																							if (BF3)
																							{
																								break;
break;
																							}
																						}
																						if (BF3)
																						{	
																							BF2 = true;
																							break;
																						}
																					} 
																					if (BF2)
																					{
																						break;
																					}
																				
	
																				}

																				if (BF2)
																				{
																					BF1 = true;
																					break;
																				}
																			}		
																		}
																		if (BF1)
																		{
																			break;
																		}
																	}

																	if (BF1)
																	{
																		BF0 = true;
																		break;
																	}


																}
																if (BF0)
																{
																	break;
																}
																
															}
															if (BF0)
															{
																BF9 = true;
																break;
															}
														}
													}
													if (BF9)
													{
														break;
													}
													
												} 
												if (BF9)
												{
													BF8 = true;
													break;
												}
											

										} 
										if (BF8)
										{
											break;
										}
									
									}
									if (BF8)
									{
										BF7 = true;
										break;
									}
								}

							}
							if (BF7)
							{
								break;
							}
							
					}
					if(BF7)
					{
						Sleep(2000);
						cout << "PERRRRAARARARARARARRARARARARARARARARARARARARARARARA";
						seleccion = 0;
						break;
					}
					
				
				
				}
				seleccion = 0;
	}
		

		if (seleccion == 1) {

			seleccion = 0;

			// obstaculos de mapa
			muro muro1(23, 8);
			muro muro2(23, 9);
			muro muro3(23, 10);
			muro muro4(23, 11);
			muro muro5(23, 12);
			muro muro6(23, 13);
			muro muro7(23, 14);
			muro muro8(23, 15);
			muro muro9(23, 16);
			muro muro10(23, 17);
			muro muro11(23, 18);
			muro muro12(23, 19);
			muro muro13(23, 20);
			muro muro14(23, 21);
			muro muro15(23, 22);
			muro muro16(23, 23);


			//porteria jugador 1

			muro muro17(60, 28);
			muro muro18(60, 27);
			muro muro19(59, 27);
			muro muro20(58, 27);
			muro muro21(57, 27);
			muro muro22(57, 28);


			//porteria jugador 2
			muro muro23(60, 2);
			muro muro24(60, 3);
			muro muro25(59, 3);
			muro muro26(58, 3);
			muro muro27(57, 3);
			muro muro28(57, 2);


			//vector<muro> muros;

			list<muro*> muros;

			muros.push_back(&muro1);
			muros.push_back(&muro2);
			muros.push_back(&muro3);
			muros.push_back(&muro4);
			muros.push_back(&muro5);
			muros.push_back(&muro6);
			muros.push_back(&muro7);
			muros.push_back(&muro8);
			muros.push_back(&muro9);
			muros.push_back(&muro10);
			muros.push_back(&muro11);
			muros.push_back(&muro12);
			muros.push_back(&muro12);
			muros.push_back(&muro13);
			muros.push_back(&muro14);
			muros.push_back(&muro15);
			muros.push_back(&muro16);
			muros.push_back(&muro17);
			muros.push_back(&muro18);
			muros.push_back(&muro19);
			muros.push_back(&muro20);
			muros.push_back(&muro21);
			muros.push_back(&muro22);
			muros.push_back(&muro23);
			muros.push_back(&muro24);
			muros.push_back(&muro25);
			muros.push_back(&muro26);
			muros.push_back(&muro27);
			muros.push_back(&muro28);



			for (int y = 0+1; y < 30; y++)
			{
				for (int x = 0; x < 120; x++)
				{
					if (y == 1 || y == 29)
					{

						muro mur(x, y);
						mur.dibujarmuro();
						muros.push_back(&mur);
					}
					else if (x == 0 || x == 119)
					{
						muro mur(x, y);
						mur.dibujarmuro();
						muros.push_back(&mur);
					}
					else { gotoxy(x, y); puts(" "); }

				}

			}

			muro1.dibujarmuro();
			muro2.dibujarmuro();
			muro3.dibujarmuro();
			muro4.dibujarmuro();
			muro5.dibujarmuro();
			muro6.dibujarmuro();
			muro7.dibujarmuro();
			muro8.dibujarmuro();
			muro9.dibujarmuro();
			muro10.dibujarmuro();
			muro11.dibujarmuro();
			muro12.dibujarmuro();
			muro13.dibujarmuro();
			muro14.dibujarmuro();
			muro15.dibujarmuro();
			muro16.dibujarmuro();
			muro17.dibujarmuro();
			muro18.dibujarmuro();
			muro19.dibujarmuro();
			muro20.dibujarmuro();
			muro21.dibujarmuro();
			muro22.dibujarmuro();
			muro23.dibujarmuro();
			muro24.dibujarmuro();
			muro25.dibujarmuro();
			muro26.dibujarmuro();
			muro27.dibujarmuro();
			muro28.dibujarmuro();
			list<Bomba*> bombas;
			Bomba bomba1(70, 22);
			bombas.push_back(&bomba1);
			bomba1.Dibujar();
			muro prueba(50, 5);
			prueba.dibujarmuro();

			muros.push_back(&prueba);

			TanqueJugador jugador1(40, 26, 1,3,3,0,59,28);
			TanqueJugador jugador2(40, 4, 2,3,50,0,59,2);
			TanqueJugador *juga1 = &jugador1;
			TanqueJugador *juga2 = &jugador2;
			jugador1.dibujarTanque(juga2);
			jugador2.dibujarTanque(juga1);

			bool terminar = false;
			bool *ter = &terminar;

			while (!terminar)
			{


				if (GetAsyncKeyState(VK_UP))
				{


					if (jugador1.MoverArriba(juga2, muros, bombas))
					{
						jugador1.displayvida();


					}

					Sleep(25);
				}
				if (GetAsyncKeyState(VK_DOWN))
				{

					if (jugador1.MoverAbajo(juga2, muros, bombas))
					{
						jugador1.displayvida();
					}
					Sleep(25);
				}

				if (GetAsyncKeyState(VK_LEFT))
				{

					if (jugador1.MoverIzquierda(juga2, muros, bombas))
					{
						jugador1.displayvida();
					}
					Sleep(25);
				}
				if (GetAsyncKeyState(VK_P))
				{
					pausar = true;
					Sleep(10150);
					pausar = false;
				}

				if (GetAsyncKeyState(VK_RIGHT))
				{

					if (jugador1.MoverDerecha(juga2, muros, bombas))
					{
						jugador1.displayvida();
					}
					Sleep(25);
				}

				if (GetAsyncKeyState(VK_SPACE))
				{

					thread t1(&TanqueJugador::Disparar, jugador1, ref(juga2), ref(muros),ref(ter),ref(disparandojugador1));
					t1.detach();
					Sleep(150);
				}

				Sleep(150);


				if (GetAsyncKeyState(VK_W))
				{
					if (jugador2.MoverArriba(juga1, muros, bombas))
					{
						jugador2.displayvida();
					}
					Sleep(25);
				}

				if (GetAsyncKeyState(VK_S))
				{

					if (jugador2.MoverAbajo(juga1, muros, bombas))
					{
						jugador2.displayvida();
					}
					Sleep(25);
				}

				if (GetAsyncKeyState(VK_A))
				{
					
					if (jugador2.MoverIzquierda(juga1, muros, bombas))
					{
						jugador2.displayvida();
					}
					Sleep(25);
				}

				if (GetAsyncKeyState(VK_D))
				{
					
					if (jugador2.MoverDerecha(juga1, muros, bombas))
					{
						jugador2.displayvida();
					}
					Sleep(25);
				}

				if (GetAsyncKeyState(VK_F))
				{
					thread t2(&TanqueJugador::Disparar, jugador2, ref(juga1), ref(muros),ref(ter),ref(disparandojugador2));

					t2.detach();
					Sleep(150);
				}
				
	
			}
		
			cout << "gane prros";

			Sleep(150);
			 
			system("cls");	




		}
		
	}

}

