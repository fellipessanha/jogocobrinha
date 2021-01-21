#pragma once

#include <iostream>
#include "snek.h"
// #include "frut.h"

namespace visuals
{

    void draw(snekGame::Snek S, snekGame::Frut F)
    {
        // the improvisation relies on the cmd clearing, so that's the big boy here
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

                // this for is the snek's body
                for (unsigned k = 0; k < S.posTail.size(); k++)
                {
                    if (i == S.posTail.at(k).first && j == S.posTail.at(k).second)
                    {
                        if (k == 0)
                        {
                            std::cout << "S";
                            print = false;
                        }
                        else if (k == 1)
                        {
                            std::cout << "n";
                            print = false;
                        }

                        else if (k < S.posTail.size() - 1)
                        {
                            std::cout << "e";
                            print = false;
                        }

                        else
                        {
                            std::cout << "k";
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
            // for (int k = 0; k < S.posTail.size(); k++)
            //         std::cout << k << ": " << S.posTail.at(k).first <<", "<< S.posTail.at(k).second << "\n";
            // std::cout << "\n------------------------------\n";
    }
}
