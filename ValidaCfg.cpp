#include "ValidaCfg.hpp"

void validaCasillas(int casillas) {
    if (casillas > MAX_CASILLAS) {
        throw InvalidConfigurationException("Invalid tiles value " + std::to_string(casillas));
    }
    else {
        return;
    }
}

void validaJugadores(int jugadores) {
    if (jugadores > MAX_JUGADORES) {
        throw InvalidConfigurationException("Invalid players value " + std::to_string(jugadores));
    }
    else {
        return;
    }
}

void validaTurnos(int turnos) {
    if (turnos > MAX_TURNOS) {
        throw InvalidConfigurationException("Invalid turns value " + std::to_string(turnos));
    }
    else {
        return;
    }
}

void validaCfg(int casillas, int jugadores, int turnos) {
    validaCasillas(casillas);
    validaJugadores(jugadores);
    validaTurnos(turnos);
}