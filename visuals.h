#pragma once

#include <iostream>
#include "snek.h"

namespace visuals
{

    void draw(snekGame::Snek S, snekGame::Frut F)
    {

        std::system("cls");
        bool print;

        // top line
        std::cout << " ";
        for (unsigned i = 0; i < snekGame::dimension; i++)
            std::cout << "#";
        std::cout << "\n";    

        // Game canvas and side walls
        for (unsigned j = 0; j < snekGame::dimension; j++)
        {
            std::cout << "!";
            

            for (unsigned i = 0; i < snekGame::dimension; i++)
            {
                print = true;   
               
                for (unsigned k = 0; k < S.posTail.size(); k++)
                {
                    if (i == S.posTail.at(k).first && j == S.posTail.at(k).second)
                    {
                        if (k == 0)
                        {
                            std::cout << "S";
                            print = false;
                        }
                        else
                        {
                            std::cout << "e";
                            print = false;
                        }
                    }
                }

                if (i == F.pos.first && j == F.pos.second)
                {
                    std::cout << "0";
                    print = false;
                }

                if (print == true)
                {
                    if (print = true)
                        std::cout << " ";                    
                }
                
            }

            std::cout << "!";
            std::cout << "\n";
        }
        
        // bottom line
        std::cout << ' ';
        for (unsigned i = 0; i < snekGame::dimension; i++)
            std::cout << "#";
        std::cout << " \n";

        // here for debug reasons: displays the snake coordinates
        for (int k = 0; k < S.posTail.size(); k++)
                std::cout << k << ": " << S.posTail.at(k).first <<", "<< S.posTail.at(k).second << "\n";
        std::cout << "\n------------------------------\n";
    }
}
