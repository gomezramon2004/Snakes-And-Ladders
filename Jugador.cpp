#include <iostream>
#include "Jugador.hpp"

// Constructor por default: jugador (1) en casilla (1)
Jugador::Jugador()
{
    this->numero = 1;
    this->casilla_actual = 1;
}

// Constructor de jugador (n) en casilla (1)
Jugador::Jugador(int n)
{
    this->numero = n;
    this->casilla_actual = 1;
}

// Consulta la casilla donde está el jugador
int Jugador::getCasilla_actual()
{
    return casilla_actual;
}

// Coloca/mueve al jugador a la casilla(n)
void Jugador::setCasilla_actual(int n)
{
    this->casilla_actual = n;
}

// Muestra en Consola al Jugador
void Jugador::print() {
     std::cout << "Jugador #" << numero << "\n Casilla Actual: " << casilla_actual << std::endl;
}