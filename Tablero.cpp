#include "Tablero.hpp"
#include "CasillaEscalera.hpp"
#include "CasillaSerpiente.hpp"
#include "CasillaNormal.hpp"
#include <fstream>
#include <vector>
#include <iterator>

// Crea un Tablero de sólo casillas Normales
Tablero::Tablero()
{
    for (auto i=0; i < MAX_CASILLAS; i++){
        this->c[i] = CCasilla(i+1,"N");
    }
}

// Cargar un Tablero desde un archivo
Tablero::Tablero(std::string f)
{
    std::ifstream input(f); std::vector<std::string> outputs;
    outputs = std::vector<std::string> (std::istream_iterator<std::string>(input), std::istream_iterator<std::string>());
    input.close();

    if (!contarCasillasCorrectas(outputs)){
        std::cout << "Error. No hay suficientes casillas de escaleras o serpientes" << std::endl;
        exit(0);
    }
    
    for (auto i=0; i < MAX_CASILLAS;i++) {
        if (outputs[i] == "N"){
            this->c[i] = CasillaNormal(i+1);
        }
        if (outputs[i] == "S"){
            this->c[i] = CasillaSerpiente(i+1);
        }
        if (outputs[i] == "L"){
            this->c[i] = CasillaEscalera(i+1);
        }
    }
}

// Muestra el tablero casilla x casilla
void Tablero::print() 
{
    for (auto i=0; i < MAX_CASILLAS;i++) {
        std::cout << c[i].getNumeroCasilla() << c[i].getTipo() << (i+1 < MAX_CASILLAS ? " - " : "\n");
    }
    std::cout << std::endl;
}

// Devuelve la casilla en la posición i
CCasilla Tablero::getCasilla(int i)
{
    return c[i-1];
}

// Contar las casillas del vector tablero que sean serpiente o escalera.
// Si los valores dados en el conteo son los mismos que el de las (Ctesconf.hpp) constantes de la cantidad correcta de casillas, entonces se devolvera como verdadero
bool Tablero::contarCasillasCorrectas(std::vector<std::string> v)
{
    int count_s = 0; int count_l = 0;

    for (const auto& casilla : v) {
        if (casilla == "S") {
            count_s++;
        }
        if (casilla == "L") {
            count_l++;
        }
    }

    return (count_s == MAX_CASILLAS_S && count_l == MAX_CASILLAS_L);
}

// Inserta una casilla en una posición i
void Tablero::setCasilla(CCasilla c, int i)
{
    this->c[i-1] = CCasilla();
}
