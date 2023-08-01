#pragma once

#include "CCasilla.hpp"
#include <vector>
#include <string>

class Tablero {
private:
    CCasilla c[MAX_CASILLAS];
public:
    Tablero();
    Tablero(std::string);
    CCasilla getCasilla(int);
    void setCasilla(CCasilla, int);
    bool contarCasillasCorrectas(std::vector<std::string>);
    void print();
};
