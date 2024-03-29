// Blackjack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <MMSystem.h>
using namespace std;



//VARIABLES
string PlayerName;
int palo;
int valor;
string NombrePalo;
int PosicionListaPalo;
int corazones[13];
int diamantes[13];
int treboles[13];
int picas[13];
int puntosJugador = 0;
bool winner;
bool looser;
int valorAS;
int valorASc;
bool seguir;
bool CrupierPlaying = false;
int puntosCrupier = 0;
bool choosed;
string nombreCarta;
int respuestaAS;
string nombreCartaCrupier;
string NombrePaloCrupier;



//FUNCIONES
void StartGame() {
	cout << "Bienvenido al Gran Casino LAUMON \n" << "¿Como te llamas? \n";
	cin >> PlayerName;
	cout << "Bien, " << PlayerName << " juguemnos al BLACKJACK. \n";
}

void inicioArray(int(&lista)[13]) {
	for (int i = 0; i <= 13 ; i++) {
		lista[i] = 1; 
	}
}



void SacarCartasJugador() {
	choosed = false;
	while (!choosed) {
		palo = rand() % 4;
		PosicionListaPalo = rand() % 13;
		if (palo == 0) {
			if (corazones[PosicionListaPalo] == 1) {
				NombrePalo = "Corazones";
				corazones[PosicionListaPalo] = 0;
				choosed = true;
			}
		}
	
		if (palo == 1) {
			if (diamantes[PosicionListaPalo] == 1) {
				NombrePalo = "Diamantes";
				diamantes[PosicionListaPalo] = 0;
				choosed = true;
			}
		}
		if (palo == 2) {
			if (treboles[PosicionListaPalo] == 1) {
				NombrePalo = "Treboles";
				treboles[PosicionListaPalo] = 0;
				choosed = true;
			}
		}
		if (palo == 3) {
			if (picas[PosicionListaPalo] == 1) {
				NombrePalo = "Picas";
				picas[PosicionListaPalo] = 0;
				choosed = true;
			}
	}
	}
	nombreCarta;
	respuestaAS;
	nombreCarta = to_string(PosicionListaPalo + 1);
	if (PosicionListaPalo == 0) //AS
	{
		nombreCarta = "AS";
		cout << "Has sacado un " << nombreCarta << " de " << NombrePalo << "\n";
		cout << "Escoje si el valor del AS: [1] 1 o [2] 11. \n";
		cin >> respuestaAS;
		if (respuestaAS == 1)
		{
			valorAS = 1;
		}
		else if (respuestaAS == 2)
		{
			valorAS = 11;
		}
		
		
	}
	else if (PosicionListaPalo >= 10) { //GRANDES
		if (PosicionListaPalo == 10) //J
		{
			nombreCarta = "J";
		}
		else if (PosicionListaPalo == 11) //Q
		{
			nombreCarta = "Q";
		}
		else if (PosicionListaPalo == 12) //K
		{
			nombreCarta = "K";
		}
		cout << "Has sacado un " << nombreCarta << " de " << NombrePalo << "\n";
	}
	else {
		cout << "Has sacado un " << nombreCarta << " de " << NombrePalo << "\n";
	}
}
void SacarCartasCrupier() {
	choosed = false;
	while (!choosed) {
		palo = rand() % 4;
		PosicionListaPalo = rand() % 13;
		if (palo == 0) {
			if (corazones[PosicionListaPalo] == 1) {
				NombrePaloCrupier = "Corazones";
				corazones[PosicionListaPalo] = 0;
				choosed = true;
				}
			}
		
		if (palo == 1) {
			if (diamantes[PosicionListaPalo] == 1) {
			NombrePaloCrupier = "Diamantes";
			diamantes[PosicionListaPalo] = 0;
			choosed = true;
			}
		}
		if (palo == 2) {
			if (treboles[PosicionListaPalo] == 1) {
			NombrePaloCrupier = "Treboles";
			treboles[PosicionListaPalo] = 0;
			choosed = true;
			}
		}
		if (palo == 3) {
			if (picas[PosicionListaPalo] == 1) {
			NombrePaloCrupier = "Picas";
			picas[PosicionListaPalo] = 0;
			choosed = true;
			}
		}
	}
	nombreCartaCrupier = to_string(PosicionListaPalo + 1);

	if (PosicionListaPalo == 0) //AS
	{
		nombreCartaCrupier = "AS";
		if (puntosCrupier > 10)
		{
			valorASc = 1;
		}
		else
		{
			valorASc = 11;
		}
	}
	else if (PosicionListaPalo >= 10) { //GRANDES
		valor = 10;
		if (PosicionListaPalo == 10) //J
		{
			nombreCartaCrupier = "J";
		}
		if (PosicionListaPalo == 11) //Q
		{
			nombreCartaCrupier = "Q";
		}
		if (PosicionListaPalo == 12) //K
		{
			nombreCartaCrupier = "K";
		}
	}

	else { 
		valor = PosicionListaPalo + 1;
	}
}

void ContarPuntosJugador() {
	if (PosicionListaPalo == 0) //AS
	{
		puntosJugador = puntosJugador + valorAS - 1;
	}
	if (PosicionListaPalo >= 10) //GRANDES
	{
		valor = 10;
		puntosJugador = puntosJugador + valor;
	}
	else {
		valor = PosicionListaPalo + 1;
		puntosJugador = puntosJugador + valor;
	}
	
}
void ContarPuntosCrupier() {
	if (PosicionListaPalo == 0) //AS
	{
		puntosCrupier = puntosCrupier + valorASc;
	}
	else if (PosicionListaPalo >= 10) //GRANDES
	{
		puntosCrupier = puntosCrupier + valor;
	}
	else {
		puntosCrupier = puntosCrupier + valor;
	}
	
	//PARA VER SI EMPATAN: puntosCrupier = puntosJugador;
}
void CrupierPlay() {
	CrupierPlaying = true;
	SacarCartasCrupier();
	ContarPuntosCrupier();
}

void CompararPuntos() {
	if (puntosJugador == puntosCrupier)
	{
		cout << "Habeis empatado";

	}
	else if ((puntosJugador > puntosCrupier && puntosJugador <= 21) || (puntosCrupier > 21))
	{
		cout << "El ganador de la partida es el jugador.";
	}
	else if ((puntosJugador < puntosCrupier && puntosCrupier <= 21) || (puntosJugador > 21))
	{
		cout << "El ganador de la partida es el crupier.";
	}
	
}

void mostrarCartasCrupier() {
	cout << "El crupier ha sacado un " << nombreCartaCrupier << " de " << NombrePaloCrupier << "\n";
}

void keepPlaying() {
	seguir = true;
	int	respuestaSeguir;
	while (puntosJugador < 21 && seguir)
	{
		cout << "Quieres mas cartas? \n";
		cout << "[1] SI \n";
		cout << "[2] NO \n";
		cin >> respuestaSeguir;
		if (respuestaSeguir == 1)
		{
			SacarCartasJugador();
			ContarPuntosJugador();
			cout << "Has hecho " << puntosJugador << " puntos. \n";
			
		}
		if (respuestaSeguir == 2)
		{
			cout << "Te has plantado, ahora es el turno del crupier" << "\n";
			seguir = false;
		}
	}
}
void keepPlayingCrupier() {
	seguir = true;
	cout << "El crupier tiene " << puntosCrupier << " puntos. \n";
	while (puntosCrupier < puntosJugador && seguir)
	{
		if (puntosCrupier < puntosJugador)
		{
			cout << "El crupier quiere mas cartas.\n";
			SacarCartasCrupier();
			mostrarCartasCrupier();
			ContarPuntosCrupier();
			cout << "El crupier tiene " << puntosCrupier << " puntos. \n";
			
			if (puntosCrupier == 21)
			{
				seguir = false;
			}
		}
		if (puntosCrupier > puntosJugador && puntosCrupier <= 21)
		{
			cout << "El crupier se planta.\n";
			seguir = false;
		}
	}
}



//MAIN
int main() {
	srand(time(nullptr));
	inicioArray(corazones);
	inicioArray(diamantes);
	inicioArray(treboles);
	inicioArray(picas);
	puntosCrupier = 0;
	StartGame();
	//Repartir cartas
	cout << "Sacare dos cartas al jugador y una para mi. \n"
		//cartas jugador
		<< "Las cartas del jugadore son: \n";
	SacarCartasJugador();
	ContarPuntosJugador();
	cout << "La segunda carta es... \n";
	SacarCartasJugador();
	ContarPuntosJugador();
	cout << "Has hecho " << puntosJugador << " puntos. \n";
	//carta crupier
	CrupierPlay();
	//seguir jugando jugador
	keepPlaying();
	//jugador planta -> juega crupier
	if (puntosJugador > 21) {
		cout << "Te has pasado." << "\nEl ganador de la partida es el crupier";
	}
	else {
		do
		{
			mostrarCartasCrupier();
			keepPlayingCrupier();
			CompararPuntos();
		} while (puntosCrupier < puntosJugador);
		//CompararPuntos();
	}

		
	




}
