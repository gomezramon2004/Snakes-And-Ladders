#pragma once

#include "Ctesconf.hpp"
#include "Tablero.hpp"
#include "Jugador.hpp"
#include "CDado.hpp"
#include "Turno.hpp"
#include <fstream>
#include <ostream>

class Game {
protected:
    Tablero t;
    Jugador j[MAX_JUGADORES];
    CDado d;
    bool swio;
    Turno* Pturno;
    std::ifstream fi{"input"};
    std::ofstream fo{"output"};
    virtual char getInput()=0;   
public:
    static int turn;
    Game();
    Game(std::string, bool, bool);
    void start();
    template<class M> void outMsg(M);
    virtual ~Game();
};