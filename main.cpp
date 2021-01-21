#include <vector>
#include <iostream>

#include "frut.h"
#include "snek.h"
#include "visuals.h"



// global variables
bool gameOver;
snekGame::Snek snek;
snekGame::Frut frut;


// functions
void setup(){

    gameOver = false;

    frut.refresh(snek.posTail);
    frut.pts = 1;
}

int main()
{
    setup();

    while (!gameOver)
    {

        snek.Input(gameOver);
        std::cout << ',';
        frut.ate(snek);
        std::cout << '.';
        visuals::draw(snek, frut);
        frut.showScore();
    }
    return 0;
}