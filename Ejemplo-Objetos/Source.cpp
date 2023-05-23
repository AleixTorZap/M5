#include <iostream>
#include "Personaje.h"
#include "EnemigoFinal.h"
#include <conio.h>


int main() {
	srand(time(nullptr));

	string tabla[5][5];
	int posicionX;
	int posicionY;
	int arrX[5];
	int arrY[5];
	bool HeroeAlive = true;
	
	for (int i = 0; i < 4; i++)
	{
		posicionX = rand() % 5;
		posicionY = rand() % 3 + 1;
		arrX[i] = posicionX;
		arrY[i] = posicionY;
	}

	//Heroe
	Personaje Heroe(50, "Daniel Towers", 50, 0, 0);
	//CREAMOS UN ENEMIGO NORMAL
	Personaje goomba1(50, "Goomba 1", 50, arrX[0], arrY[0]);
	Personaje goomba2(50, "Goomba 2", 50, arrX[1], arrY[1]);
	Personaje goomba3(50, "Goomba 3", 50, arrX[2], arrY[2]);
	


	//CREAMOS UN ENEMIGO FINAL QUE HvEREDA DE ENEMIGO
	EnemigoFinal kingBowser(100, "Bowser", 75, 4, 2, 100, 50);



	goomba1.posicionEnemigos();
	goomba2.posicionEnemigos();
	goomba3.posicionEnemigos();
	for (int i = 0; i < 3; i++)
	{
		int goombaX = arrX[i];
		int goombaY = arrY[i];
		tabla[goombaY][goombaX] = "| E |";
	}
	tabla[kingBowser.getPosicionX()][kingBowser.getPosicionY()] = "| B |";
	
	while (HeroeAlive)
	{
	int key = _getch();
	int posAntX = Heroe.getPosicionX();
	int posAntY = Heroe.getPosicionY();
	string celdaHeroe = "| H |";



		switch (key) {
		key = _getch();
	case 75: // Flecha izquierda 
		Heroe.setPosicionY(Heroe.getPosicionY() - 1);
		break;
	case 77: // Flecha derecha 
		Heroe.setPosicionY(Heroe.getPosicionY() + 1);
		break;
	case 72: // Flecha arriba 
		Heroe.setPosicionX(Heroe.getPosicionX() - 1);
		break;
	case 80: // Flecha abajo 
		Heroe.setPosicionX(Heroe.getPosicionX() + 1);
		break;
	default:
		break;
	}	
		tabla[Heroe.getPosicionX()][Heroe.getPosicionY()] = celdaHeroe;
		tabla[posAntX][posAntY] = "|   |";

		cout << "TABLERO\n";
	for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tabla[i][j].empty()) {
					tabla[i][j] = "|   |";
				}
			cout << tabla[i][j] << " ";
		}	
			cout << endl;
		}




		
		
	
	} ;
}
