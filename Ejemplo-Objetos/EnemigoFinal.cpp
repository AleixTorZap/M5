#include "EnemigoFinal.h"

//CONSTRUCTOR
//TIENE COMO PARÁMETROS DE ENTRADA LOS ATRIBUTOS PROPIOS
//Y LOS ATRIBUTOS DE LA CLASE QUE HEREDA
//LOS PARÁMETROS DE LA CLASE QUE HEREDA SE PASAN COMO PARÁMETROS DE ENTRADA
//AL CONSTRUCTOR HEREDADO
EnemigoFinal::EnemigoFinal(int pHp,
						   std::string pName,
						   int pAttack,
						   int pPosicionX,
						   int pPosicionY,
						   int pCritico,
						   int pSuperAttack) : Personaje(pHp,
														pName,
														pAttack,
														pPosicionX, 
														pPosicionY) {critico = pCritico;
																  superAttack = pSuperAttack;
						}


//GETTERS AND SETTERS
int EnemigoFinal::getCritico() {
	return critico;
}
int EnemigoFinal::getSuperAttack() {
	return superAttack;
}

void EnemigoFinal::setCritico(int pCritico) {
	critico = pCritico;
}
void EnemigoFinal::setSuperAttack(int pSuperAttack) {
	superAttack = pSuperAttack;
}

//METODOS PROPIOS
void EnemigoFinal::printAllStats() {
	cout << "El nombre del enemigo final es " << getName() << endl;
	cout << "La vida del enemigo final es " << getHp() << endl;
	cout << "El ataque normal del enemigo final es " << getAttack() << endl;
	cout << "El ataque critico del enemigo final es " << getCritico() << endl;
	cout << "El super ataque del enemigo final es " << getSuperAttack() << endl;
}
