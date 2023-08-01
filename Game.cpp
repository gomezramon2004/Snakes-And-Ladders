#include "Game.hpp"
#include "Turno.hpp"
#include "Ctesconf.hpp"
#include "Tablero.hpp"
#include "CDado.hpp"
#include "Jugador.hpp"
#include <iterator>
#include <istream>
#include "EndGameException.hpp"
#include "InvalidConfigurationException.hpp"
#include "ValidaCfg.hpp"

// Se asigna valor al miembro público turno como 1
int Game::turn = 1;

// Construye un juego configurado para dado aleatorio/no aleatorio e I/O - Consola o Archivo
Game::Game(std::string tf, bool swa, bool swio)
{   
    this->t    = Tablero(tf);
    this->d    = CDado(swa);
    this->swio = swio;          //Switch IO: false = keyboard : true = input file

    for (auto i=0; i < MAX_JUGADORES;i++) {
        this->j[i] = Jugador(i+1);
    }
}

// Imprime un mensaje en Consola/Archivo 
template<class M>
void Game::outMsg(M msg) 
{   
    if (!swio) {
        std::cout << msg << "\n";
    }
    else {
        fo << msg << "\n";
    }
}

// Arranca y simula el Juego
void Game::start()
{   
     //Constructor de variables que serán modificadas por cada turno
    int current_player; int current_tile; int current_dice; std::string current_type_tile; int counter = 1;
    outMsg("Press C to continue next turn, or E to end the game");

    while (turn <= MAX_TURNOS){
        switch (this->getInput()) {
            case 'C':

                //Asignación de valores y salida de información en el archivo de texto
                current_player = turn % MAX_JUGADORES != 0 ? turn % MAX_JUGADORES : MAX_JUGADORES;
                current_tile = j[current_player-1].getCasilla_actual();
                current_dice = d+1;
                Pturno = new Turno(turn, current_player, current_tile, current_dice, t.getCasilla(current_tile + current_dice).getTipo(), t.getCasilla(current_tile + current_dice).getSiguienteCasilla());
                outMsg(*Pturno);
                
                //Condicionales en caso de que se haya superado el número de casillas
                if (Pturno->getFinal_tile() >= 30){
                    outMsg("--GAME OVER--");
                    outMsg("Player " + std::to_string(Pturno->getCurrent_player()) + " is the winner!!!");
                    fo.close();
                    delete Pturno;
                    this -> turn = 1;
                    return;
                }

                //Asignación de la casilla final al objeto jugador actual, así como un incremento postfijo en la variable turno
                j[Pturno->getCurrent_player()-1].setCasilla_actual(Pturno->getFinal_tile());
                delete Pturno;
                turn ++;
                break;
            
            case 'E':

                outMsg("--GAME OVER--");
                outMsg("Thanks for playing!!!");
                fo.close();
                this -> turn = 1;
                return;

            default:

                try{
                    if (counter < 5) {
                        counter ++;
                        throw InvalidOptionException("Invalid option, please C to continue next turn or E to End the game");
                    }
                    throw EndGameException("Invalid menu choice exceeded\n--GAME OVER--");
                }
                catch (InvalidOptionException& e) {
                    outMsg(e.what());
                }
                catch (EndGameException& e) {
                    fo << e.what(); // Utilizo el ofstream debido a que el archivo toutput no tiene un brinco de linea.
                    //Outmsg() está programado para que cada linea en el archivo de texto tenga un brinco de linea.
                    //A su vez, al final del codgio en los tests y en exercise.cpp se imprime el resultado en consola.
                    //Por lo tanto, si el codigo no tuviera estos percances, emplearía el outmsg()
                    throw;
                }

        }
    }
    outMsg("The maximum number of turns has been reached...");
    fo.close();
}

Game::~Game() {
}
