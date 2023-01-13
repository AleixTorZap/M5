// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del enemigo
int enemyHP = 100;
string enemyName = "Creeper";
bool enemyIsAlive = true;


//Atributos del enemigo
bool enemy2IsAlive = true;
string enemy2Name = "Zombie";
int enemy2HP = 300;
int enemy;
int enemigo;
int enemyDamage;
int enemy2Damage;

//Atributos de héroe
string heroName;
int heroDamage;
int heroHP = 500;
bool heroIsAlive = true;
int atack;
int atack2;

//Ataques heroe
string Rayo = "Rayo";
int RayoDamage = 25;
int contador = 3;

string Golpe = "Golpe";
int GolpeDamage = 50;

string Espada = "Espada";
int EspadaDamage = 75;

void gameStart() {
    cout << "Un " << enemyName << " i un " << enemy2Name << " acaban de aparecer y tienen " << enemyHP << " i " << enemy2HP << " puntos de vida\n";
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
}
void atack1() {
    cout << "Que ataque quieres utilizar?\n";
    cout << "(1)" << Rayo << "?\n";
    cout << "(2)" << Golpe << "?\n";
    cout << "(3)" << Espada << "?\n";
    cin >> atack;

    if (atack == 1) {
        enemyHP = enemyHP - RayoDamage;

    }
    else if (atack == 2) {
        enemyHP = enemyHP - GolpeDamage;
    }
    else if (atack == 3) {
        enemyHP = enemyHP - EspadaDamage;
    }
}
void atack22() {

    cout << "Que ataque quieres utilizar?\n";
    cout << "(1)" << Rayo << "?\n";
    cout << "(2)" << Golpe << "?\n";
    cout << "(3)" << Espada << "?\n";
    cin >> atack2;

    if (atack2 == 1) {
        enemy2HP = enemy2HP - RayoDamage;
    }
    else if (atack2 == 2) {
        enemy2HP = enemy2HP - GolpeDamage;
    }
    else if (atack2 == 3) {
        enemy2HP = enemy2HP - EspadaDamage;
    }
}

int SeleccionEnemigo() {

    cout << "A quien quieres atacar?\n";
    cout << "(1)" << enemyName << "?\n";
    cout << "(2)" << enemy2Name << "?\n";
    cin >> enemy;

    return enemy;
}
int main()
{
    srand(time(0));
    gameStart();
    while (enemyIsAlive == true && heroIsAlive == true && enemy2IsAlive == true) {
        int enemyDamage = rand() % 100 + 1;
        int enemy2Damage = rand() % 100 + 1;
        //seleciona el enemigo

        SeleccionEnemigo();

        if (enemy == 1) {
            cout << "Vamos a atacar al " << enemyName << "\n";
            string enemigo = enemyName;

        }
        else if (enemy == 2) {
            cout << "Vamos a atacar al " << enemy2Name << "\n";
            string enemigo = enemy2Name;
        }
        else
        {
            cout << "Caracter incorrecto\n";
        }

        //enemy1
        switch (enemy)
        {
        case 1:

            //seleciona el ataque
            atack1();

            if (enemyHP <= 0)
            {
                cout << "Te acabas de cargar al enemigo " << enemyName << "\n";
                enemyIsAlive = false;
                cout << "Solo queda el " << enemy2Name << "\n";
            }
            else if (enemyIsAlive == true) {
                cout << "Al enemigo " << enemyName << " le quedan " << enemyHP << " puntos de vida\n";
                heroHP = heroHP - enemyDamage;
                heroHP = heroHP - enemy2Damage;

            }
            if (heroHP <= 0) {
                heroHP = 0;
                cout << "El enemigo " << enemyName << " te ha  ha matado\n";
                heroIsAlive = false;
            }
            else {
                cout << "El enemigo " << enemyName << " te ha hecho un ataque de " << enemyDamage << " puntos de daño i el enemigo " << enemy2Name << " te ha hecho " << enemy2Damage << " de daño.\n";
                cout << "Tienes " << heroHP << " puntos de vida\n";
            }
            break;



            //enemy2
        case 2:

            //seleciona el ataque
            atack22();

            if (enemy2HP <= 0)
            {
                cout << "Te acabas de cargar al enemigo " << enemy2Name << "\n";
                enemy2IsAlive = false;
                cout << "Solo queda el " << enemyName << "\n";
            }
            else if (enemy2IsAlive == true) {
                cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de vida\n";
                heroHP = heroHP - enemy2Damage;
                heroHP = heroHP - enemyDamage;
            }
            if (heroHP <= 0) {
                heroHP = 0;
                cout << "El enemigo " << enemy2Name << " te ha  ha matado\n";
                heroIsAlive = false;
            }
            else {
                cout << "El enemigo " << enemyName << " te ha hecho un ataque de " << enemyDamage << " puntos de daño i el enemigo " << enemy2Name << " te ha hecho " << enemy2Damage << " de daño.\n";
                cout << "Tienes " << heroHP << " puntos de vida\n";
            }
        }
    }
    while (enemyIsAlive == true && heroIsAlive == true && enemy2IsAlive == false) {
        int enemyDamage = rand() % 100 + 1;
        int enemy2Damage = rand() % 100 + 1;
        atack1();
        if (enemyHP <= 0)
        {
            cout << "Te acabas de cargar al enemigo " << enemyName << "\n";
            enemyIsAlive = false;
            cout << "Solo queda el " << enemy2Name << "\n";
        }
        else if (enemyIsAlive == true) {
            cout << "Al enemigo " << enemyName << " le quedan " << enemyHP << " puntos de vida\n";
            heroHP = heroHP - enemyDamage;


        }
        if (heroHP <= 0) {
            heroHP = 0;
            cout << "El enemigo " << enemyName << " te ha  ha matado\n";
            heroIsAlive = false;
        }
        else {
            cout << "El enemigo " << enemyName << " te ha hecho un ataque de " << enemyDamage << " puntos de daño.\n";
            cout << "Tienes " << heroHP << " puntos de vida\n";
        }

    }
    while (enemyIsAlive == false && heroIsAlive == true && enemy2IsAlive == true) {
        int enemyDamage = rand() % 100 + 1;
        int enemy2Damage = rand() % 100 + 1;
        atack22();

        if (enemy2HP <= 0)
        {
            cout << "Te acabas de cargar al enemigo " << enemy2Name << "\n";
            enemy2IsAlive = false;
            cout << "Solo queda el " << enemyName << "\n";
        }
        else if (enemy2IsAlive == true) {
            cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de vida\n";
            heroHP = heroHP - enemy2Damage;
        }
        if (heroHP <= 0) {
            heroHP = 0;
            cout << "El enemigo " << enemy2Name << " te ha  ha matado\n";
            heroIsAlive = false;
        }
        else {
            cout << "El enemigo " << enemy2Name << " te ha hecho un ataque de " << enemy2Damage << " puntos de daño.\n";
            cout << "Tienes " << heroHP << " puntos de vida\n";
        }
    }


}

