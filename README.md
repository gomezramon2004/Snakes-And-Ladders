[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/7kzMURR7)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=11313198)
# Ejercicio S5T4-Serpientes y Escaleras / Excepciones

## Descripción del Problema

Esta tarea consiste en extender el Juego de Serpientes y Escaleras usando Excepciones.

## Diagrama de Clases
Construye aquí el Diagrama de Clases de tu solución, usando el [Lenguaje Mermaid](https://mermaid.js.org/syntax/classDiagram.html).
```mermaid
classDiagram

    class ValidaCfg {
        +validaCasillas(int) void
        +validaJugadores(int) void
        +validaTurnos(int) void
        +validaCfg(int, int, int) void
    }
    class EndGameException{
        <<Exception>>
        +what() const char*

    }

    class InvalidConfigurationException{
        <<Exception>>
        +what() const char*
    }

    class InvalidOptionException{
        <<Exception>>
        +what() const char*
    }

    class Game {
        <<abstract>>
        #Tablero t
        #Jugador j[MAX_JUGADORES]
        #CDado d
        #bool swio
        #Turno* Pturno;
        #ifstream fi
        #ofstream fo
        +static int turn
        #virtual char getInput()=0 
        +Game()
        +Game(string, bool, bool)
        +start() void
        +outMsg(string) void
        +~Game() virtual
    }

    class GameAutomatic {
        #getInput() *char  
        +GameAutomatic(std::string, bool, bool)
    }

    class GameManual {
        #getInput() *char    
        +GameAutomatic(std::string, bool, bool)

    }

     class Turno {
        -int turno
        -int current_player
        -int current_tile
        -int current_dic
        -std::string current_type_tile
        -int final_tile
        +Turno()
        +Turno(int, int, int, int, std::string, int);]
        +getCurrent_player() int
        +getFinal_tile() int
        +operator<<(std::ostream& out, const Turno& t) friend std::ostream& 

    }

    class Tablero {
        -CCasilla c[MAX_CASILLAS]
        +Tablero()
        +Tablero(string)
        +getCasilla(int) CCasilla
        +setCasilla(CCasilla, int) void
        +contarCasillasCorrectas(vector~string~) bool
        +print() void

    }

    class Jugador {
        -int numero
        -int casilla_actual
        +Jugador()
        +Jugador(int)
        +getCasillaActual() int
        +setCasillaActual() void
        +print() void
    }

    class CDado {
        -bool switchrandom=true
        +static int cara
        +CDado()
        +CDado(bool)
        +resetDado() void;
        +getValorDado() int
        +operator +(int) int;  
    }

    class CCasilla {
        #int numero=1
        #premio_castigo=NOR_PREMIO_CASTIGO
        #string tipo="N"
        +CCasilla()
        +CCasilla(int, string)
        +getNumeroCasilla() int
        +getTipo() string
        +getSiguienteCasilla() int
        +print() void
    }

    class CasillaNormal {
        +CasillaNormal()
        +CasillaNormal(int)
    }

    class CasillaSerpiente {
        +CasillaSerpiente()
        +CasillaSerpiente(int)
    }

    class CasillaEscalera {
        +CasillaEscalera()
        +CasillaEscalera(int)
    }
    
    Game <|-- GameAutomatic
    Game <|-- GameManual
    Game *-- "MAX_TURNOS" Turno
    Game *-- "1" Tablero
    Game *-- "MAX_JUGADORES" Jugador
    Game *-- "1" CDado
    Tablero  *-- "MAX_CASILLAS" CCasilla
    CCasilla <|-- "MAX_CASILLAS - MAX_CASILLAS_S - MAX_CASILLAS_L" CasillaNormal
    CCasilla <|-- "MAX_CASILLAS_S" CasillaSerpiente
    CCasilla <|-- "MAX_CASILLAS_L" CasillaEscalera
    EndGameException <.. Game : throws
    InvalidOptionException<.. Game : throws
    ValidaCfg *-- InvalidConfigurationException
    ValidaCfg *-- InvalidOptionException
```
Puedes apoyarte con el editor [Mermaid-live](https://mermaid.live/).

## Objetivo

- Busca que el código pase correctamente todas las pruebas
   * Solamente cambia los archivos permitidos para lograr este objetivo (abajo se indican las reglas específicas)
   
- Las GitHub Actions deberán presentar una palomita en verde si se han satisfecho todas las pruebas, y una cruz roja cuando alguna (o todas) las pruebas han fallado.
   * **Recomendación:** Puedes dar clic en la cruz roja para verificar cual de las pruebas ha fallado (o si el código no ha compilado correctamente).
   * **Recomendación:** En caso de que el Autograding no muestre pruebas o no funcione, contacta a tu profesor mediante un issue.

## Instrucciones

- Deberás modificar los archivos que consideres conveniente.
Explicación de los otros archivos:

- Archivo `test/tests.cpp` tiene las pruebas de esta actividad (NO LO CAMBIES!)
- Archivo `test/catch.hpp` tiene la biblioteca de pruebas  CATCH2 (NO LA CAMBIES!)
- Archivo `makefile` tienes los comandos para ejecutar la actividad (NO LO CAMBIES!)
- Archivo  `./build/appTests` se generará después de compilar (para **pruebas locales**, solo ejecútalo)

## Comandos para pruebas locales, ejecución y depuración

- Comando para construir y ejecutar pruebas: `make` o `make test`
    * Si el ejecutable ya está construido, sólo teclea : `./build/appTests`

- Comando para construir y ejecutar la aplicación: `make run` 
    * Si el ejecutable ya está construido, sólo teclea : `./build/exercise`

- Comando para depurar por línea de comandos: `make debug`
    * Para conocer los comandos de depuración consulta:
     https://u.osu.edu/cstutorials/2018/09/28/how-to-debug-c-program-using-gdb-in-6-simple-steps/
     
- Comando para depurar la ejecución del programa con `vsCode` o en `GitPod`: `make debugvs` 
    * Utilizar el depurador de la IDE.

- Comando para depurar la ejecución de las pruebas con `vsCode` o en `GitPod`: `make debugtest` 
    * Utilizar el depurador de la IDE.

## Notas

- El código será evaluado solamente si compila.
   * La razón de esto es, si no compila no es posible generar el ejecutable y realizar las pruebas.

- Algunos casos de prueba podrían recibir calificación individual, otros podrían recibir calificación y si pasan todos juntos (o todas las pruebas en conjunto).

- La calificación final se otorgará de manera automática en cada *commit*, y se evaluará solamente hasta la fecha limite de la actividad.

Para dudas adicionales, consulta a tu profesor.

## License

MIT License 2020
