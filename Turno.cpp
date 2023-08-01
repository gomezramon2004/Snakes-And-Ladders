#include "Turno.hpp"
#include <string>
#include <ostream>

Turno::Turno() {
}

Turno::Turno(int tr, int p, int t, int d, std::string tt, int ft) {
    this->turno = tr;
    this->current_player = p;
    this->current_tile = t;
    this->current_dice = d;
    this->current_type_tile = tt;
    this->final_tile = ft;
}

int Turno::getCurrent_player() {
    return current_player;
}

int Turno::getFinal_tile() {
    return final_tile;
}

std::ostream& operator<<(std::ostream& out, const Turno& t)
{
    out << std::to_string(t.turno) << " " << std::to_string(t.current_player) << " " << std::to_string(t.current_tile) << " " << std::to_string(t.current_dice) << " " << t.current_type_tile << " " << std::to_string(t.final_tile);
    return out;
}
