#pragma once
#include <iostream>
class lancha
{
private:
	std::string name;
	int velocidad;
	int distancia;
	int nitro;

public:
	//constructor
	lancha(std::string pName, int pVelocidad, int pDistancia, int pNitro);



	//getters
	std::string getName();
	int getVelocidad();
	int getDistancia();
	int getNitro();

	//setters
	void setName(std::string pname);
	void setVelocidad(int pVelocidad);
	void setDistancia(int pDistancia);
	void setNitro(int pNitro);

	//METHOOS
	void printStats();

};


