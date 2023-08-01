#include "GameManual.hpp"
#include <iostream>
#include <string>

GameManual::GameManual(std::string tf, bool swa, bool swio) : Game{tf, swa, swio} {
}

char GameManual::getInput() {
    if (!swio) {
        char input;
        std::cin >> input;
        return input;
    }
    else {
        std::string line;
        while (std::getline(fi, line)) {
            return line[0];
        }
        return 'E'; 
    }
}