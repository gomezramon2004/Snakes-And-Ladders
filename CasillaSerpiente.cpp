#include "CasillaSerpiente.hpp"

//Construye una Casilla Serpiente de numero (1-SER_PREMIO CASTIGO), con premio-castigo (SER_PREMIO_CASTIGO) y de tipo "S"
CasillaSerpiente::CasillaSerpiente()
{
    this->numero = 1 - SER_PREMIO_CASTIGO;
    this->premio_castigo = SER_PREMIO_CASTIGO;
    this->tipo = "S";
}

//Construye una Casilla Serpiente de numero (numero), con premio-castigo (SER_PREMIO_CASTIGO) y de tipo "S"
CasillaSerpiente::CasillaSerpiente(int numero):CCasilla{numero, "S"}
{
    this->numero = numero;
    this->premio_castigo = SER_PREMIO_CASTIGO;
    this->tipo = "S";
}
