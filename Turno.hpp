#pragma once
#include <string>

class Turno {
private:
    int turno{0};
    int current_player{0};
    int current_tile{0};
    int current_dice{0};
    std::string current_type_tile{""};
    int final_tile{0};
public:
    Turno();
    Turno(int, int, int, int, std::string, int);
    int getCurrent_player();
    int getFinal_tile();
    friend std::ostream& operator<<(std::ostream& out, const Turno& t);  
};