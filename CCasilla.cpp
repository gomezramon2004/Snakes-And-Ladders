#include "CCasilla.hpp"

//Constructor por default de Casilla
CCasilla::CCasilla()
{
}

//Constructor de casilla de numero(val) y de tipo(tipo)
CCasilla::CCasilla(int val, std::string tipo)
{
    this->numero = val;
    this->tipo = tipo;
}

//Consulta el número de la Casilla
int CCasilla::getNumeroCasilla()
{
    return numero;
}

//Consulta el tipo de la Casilla
std::string CCasilla::getTipo()
{
    return tipo;
}

//Dado el tipo de Casilla Actual, determina cual sería la siguiente (después del PREMIO O CASTIGO)
//Valida que no se salga del tablero
int CCasilla::getSiguienteCasilla()
{
    return numero + premio_castigo;
}

//Muestra en Consola la casilla actual
void CCasilla::print()
{
    std::cout << "Casilla #" << numero << "\n Tipo: " << tipo << std::endl;
}