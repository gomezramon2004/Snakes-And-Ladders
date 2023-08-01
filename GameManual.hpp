#pragma once

#include "Game.hpp"

class GameManual:public Game {
protected:
    char getInput() override;   
public:
    GameManual(std::string, bool, bool);
};