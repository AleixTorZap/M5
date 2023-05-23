#pragma once
#include "Personaje.h"
#include  <iostream>
	//constructor
Personaje::Personaje(int pHp, std::string pName, int pAttack, int pPosicionX, int pPosicionY) {
	hp = pHp;
	name = pName;
	attack = pAttack;
	PosicionX = pPosicionX;
	PosicionY = pPosicionY;
	}

	//getters
	int Personaje::getHp() {
		return hp;
	}

	std::string Personaje::getName() {
		return name;
	}

	int Personaje::getAttack() {
		return attack;
	}

	int Personaje::getPosicionX() {
		return PosicionX;
	}
	int Personaje::getPosicionY() {
		return PosicionY;
	}


	//setters

	void Personaje::setHp(int php) {
		hp = php;
	}

	void Personaje::setName(std::string pname) {
		name = pname;
	}

	void Personaje::setAttack(int pattack) {
		attack = pattack;
	}

	void Personaje::setPosicionX( int pPosicionX) {
		PosicionX = pPosicionX;
	}
	void Personaje::setPosicionY(int pPosicionY) {
		PosicionY = pPosicionY;
	}


	//Metodos propios

	void Personaje::posicionEnemigos() {
		std::cout << "El enemigo " << getName() << " esta en la posicion X = " << getPosicionX() << " Y = " << getPosicionY() << std::endl;
	}