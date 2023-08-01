#include "CasillaNormal.hpp"

//Construye una Casilla Normal como una Casilla general
CasillaNormal::CasillaNormal() : CCasilla{}
{
}

//Construye una Casilla Normal asignandole un numero especifico
CasillaNormal::CasillaNormal(int numero):CCasilla{numero, "N"}
{
    this->numero = numero;
    this->premio_castigo = NOR_PREMIO_CASTIGO;
    this->tipo = "N";
}