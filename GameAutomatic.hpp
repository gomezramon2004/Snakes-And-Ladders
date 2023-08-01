#pragma once

#include "Game.hpp"

class GameAutomatic:public Game {
protected:
    char getInput() override;   
public:
    GameAutomatic(std::string, bool, bool);
};