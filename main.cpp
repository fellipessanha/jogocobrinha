#include <vector>
#include <iostream>

#include "snek.h"
#include "visuals.h"
//#include "controls.h"



// global variables
bool gameOver;
snekGame::Snek snek;
snekGame::Frut frut;

// functions
void setup(){

    gameOver = false;

    frut.refresh(snek.posTail.at(0));
    frut.pts = 1;
}

int main()
{
    setup();

    while (!gameOver)
    {
        visuals::draw(snek, frut);

        snek.Input(gameOver);
        frut.ate(snek);
        // frut.showScore();
    }
    return 0;
}