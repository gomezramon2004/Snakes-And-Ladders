#include "CasillaEscalera.hpp"

//Constructor por default : inicializada con premio o castigo=ESC_PREMIO_CASTIGO y de Tipo "L"
CasillaEscalera::CasillaEscalera()
{
    this->premio_castigo =  ESC_PREMIO_CASTIGO;
    this->tipo = "L";
}

//Constructor por default: inicializada en cierto numero y con premio o castigo=ESC_PREMIO_CASTIGO y de Tipo "L"
CasillaEscalera::CasillaEscalera(int numero):CCasilla{numero, "L"}
{
    this->numero = numero;
    this->premio_castigo =  ESC_PREMIO_CASTIGO;
    this->tipo = "L";
}