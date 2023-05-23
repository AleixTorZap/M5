#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje
{
private:
	//atributos
	int critico;
	int superAttack;

public:

	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	EnemigoFinal(int pHp,
				 std::string pName,
				 int pAttack,
				 int pPosicionX,
				 int pPosicionY,
				 int pCritico,
				 int pSuperAttack);

	//GETTERS AND SETTERS
	int getCritico();
	int getSuperAttack();

	void setCritico(int pCritico);
	void setSuperAttack(int pSuperAttack);

	//METODOS PROPIOS
	void printAllStats();


};

