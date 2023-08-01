#pragma once

// Atributos parametrizables
#define MAX_CASILLAS       30   // Tiles
#define MAX_CASILLAS_S      3   // Snakes
#define MAX_CASILLAS_L      3   // Ladders
#define SER_PREMIO_CASTIGO -3   // Penalty
#define ESC_PREMIO_CASTIGO  3   // Reward
#define MAX_JUGADORES       2   // Players
#define MAX_TURNOS        100   // Turns

#define NOR_PREMIO_CASTIGO 0

// Game Type = (0-Manual / 1-Automatic)
#define MANUAL              0
#define AUTOMATIC           1
#define GAME_TYPE           MANUAL