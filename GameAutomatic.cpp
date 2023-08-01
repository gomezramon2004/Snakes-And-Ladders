#include "GameAutomatic.hpp"
#include <iterator>
#include <istream>

GameAutomatic::GameAutomatic(std::string tf, bool swa, bool swio) : Game{tf, swa, swio} {
}

char GameAutomatic::getInput() {
    return 'C';
}