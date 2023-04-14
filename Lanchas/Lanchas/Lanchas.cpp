#include "Lanchas.h"

//constructor
lancha::lancha(std::string pName, int pVelocidad, int pDistancia, int pNitro) {
	name = pName;
	velocidad = pVelocidad;
	distancia = pDistancia;
	nitro = pNitro;
}

//getters
std::string lancha::getName() {
	return name;
}

int lancha::getVelocidad() {
	return velocidad;
}

int lancha::getDistancia() {
	return distancia;
}


int lancha::getNitro() {
	return nitro;
}

//settets

void lancha::setName(std::string pName)
{
	name = pName;
}

void lancha::setVelocidad(int pVelocidad) {
	velocidad = pVelocidad;

}
void lancha::setDistancia(int pDistancia) {
	distancia = pDistancia;
}
void lancha::setNitro(int pNitro)
{
	nitro = pNitro;
}



//METHOOS

void lancha::printStats() {
	std::cout << "El jugador " << getName() << " va a una velocidad de " << getVelocidad() 
		<< " km/h i esta a una distancia de " << getDistancia() << ".\n";
}
