#include "Lanchas.h"
#include <iostream>
using namespace std;
void Start() {
	cout << "Bienvenido al juego\n";
	cout << "Empezamos la carrera de lanchas\n";
}
void Dado(lancha& lancha) {
	int dado = rand() % 6 + 1;
	cout << "El corredor " << lancha.getName() << " ha sacado un " << dado << " en el dado.\n";
	//Sumamos el dado a la velocidad del jugador
	lancha.setVelocidad(lancha.getVelocidad() + dado);
}
void sumarVelo(lancha& lancha) {
	//Calculamos la distancia que avanzamos cada ronda
	lancha.setDistancia(lancha.getDistancia() + lancha.getVelocidad() * 100);

}
void nitro(lancha& lancha) {
	//ponemos que si ya ha usado el nitro no se pude volver a usar
	if (lancha.getNitro() == 0) {
		cout << lancha.getName() << " ya ha usado su nitro en esta carrera." << endl;
		return;
	}
	//cambiamos el nitro a 0
	lancha.setNitro(0);
	int random = rand() % 2 ;
	if (random == 0) {
		cout << "Has sacado un 0  tu velocidad se divide :(\n";
		lancha.setVelocidad(lancha.getVelocidad() / 2);
		
	}
	else if (random == 1) {
		cout << "Has sacado un 1  tu velocidad se multiplica :)\n";
		lancha.setVelocidad(lancha.getVelocidad() * 2);
	}
	
}
void ganador(lancha& lancha1, lancha& lancha2) {
	//declaramos al ganador(el que esta a mas distancia)
	if (lancha1.getDistancia() > lancha2.getDistancia())
	{
		cout << "El ganador de la carrera ha sido " << lancha1.getName() << " con una distancia de " << lancha1.getDistancia();
	}
	else if (lancha1.getDistancia() < lancha2.getDistancia())
	{
		cout << "El ganador de la carrera ha sido " << lancha2.getName() << " con una distancia de " << lancha2.getDistancia();
	}

}




void main() {
	srand(time(nullptr));

	lancha lancha1("Alex", 0, 0, 1 );
	lancha lancha2("Gerard", 0, 0, 1 );
	
	Start();
	for (int t = 1; t <= 5; t++	)
	{
		cout << "------TURNO" << t << "------\n";
	Dado(lancha1);
	Dado(lancha2);
	
	if (t != 6) {

		//lancha1
		cout << "" << lancha1.getName() << " quieres usar el nitro? \n";
		cout << "1) SI\n";
		cout << "2) NO\n";
		int respuesta;
		cin >> respuesta;

		if (respuesta == 1)
		{
			nitro(lancha1);
		}

		//lancha2
		cout << "" << lancha2.getName() << " quieres usar el nitro? \n";
		cout << "1) SI\n";
		cout << "2) NO\n";
		int respuesta2;
		cin >> respuesta2;

		if (respuesta2 == 1)
		{
			nitro(lancha2);
		
		}
	}
		sumarVelo(lancha1);
		sumarVelo(lancha2);
		lancha1.printStats();
		lancha2.printStats();
	}


	ganador(lancha1, lancha2);
	
}
