#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "game.hpp"
using namespace std;
#define N 10
#define RESET "\033[0m"


int main(int argc, char *argv[])
{
    srand (time(NULL));
    string action;
    for(int i=0; i<1000;i++){
      cout << "\u001b[2000D" <<endl;
      cout << "\u001b[1A" <<endl;
    }
    cout << "\u001b[37;1m                                                                                                                Welcome to the Game."  << RESET << endl;
    cout << "\033[33;5m\u001b[34;1m                                                                                                                    PRESS START" << RESET << endl;
    //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\u001b[34m";
    std::cout << R"(
                                                                                                             _________________________
                                                                                                            |<><><>     |  |    <><><>|
                                                                                                            |<>         |  |        <>|
                                                                                                            |           |  |          |
                                                                                                            |  (______ <\-/> ______)  |
                                                                                                            |  /_.-=-.\| " |/.-=-._\  |
                                                                                                            |   /_    \(o_o)/    _\   |
                                                                                                            |    /_  /\/ ^ \/\  _\    |
                                                                                                            |      \/ | / \ | \/      |
                                                                                                            |_______ /((( )))\ _______|
                                                                                                            |      __\ \___/ /__      |
                                                                                                            |--- (((---'   '---))) ---|
                                                                                                            |           |  |          |
                                                                                                            |           |  |          |
                                                                                                            :           |  |          :
                                                                                                             \<>        |  |       <>/
                                                                                                              \<>       |  |      <>/
                                                                                                               \<>      |  |     <>/
                                                                                                                `\<>    |  |   <>/'
                                                                                                                  `\<>  |  |  <>/'
                                                                                                                    `\<>|  |<>/'
                                                                                                                      `-.  .-`
                                                                                                                        '--'
    )" << '\n';
    cout << "\n\n\n\n\n\n\n\n\n" << RESET;

    getline(cin,action);

    for(int i=0; i<1000;i++){
      cout << "\u001b[2000D" <<endl;
      cout << "\u001b[1A" <<endl;
    }
    if(action=="q")
        return 0;
    Grid* grid = new Grid(N);
    grid->displayMap();
    grid->play();

    delete grid;

    for(int i=0; i<1000;i++){
      cout << "\u001b[2000D" <<endl;
      cout << "\u001b[1A" <<endl;
    }
    cout << "\u001b[37;1m                                                                                                               Thank you for playing."  << RESET << endl;
    cout << "\033[33;5m\u001b[30;1m                                                                                                                        BYE" << RESET << endl;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    getline(cin,action);
    for(int i=0; i<100;i++){
      cout << "\u001b[2000D" <<endl;
      cout << "\u001b[1A" <<endl;
    }
    return 1;
}
