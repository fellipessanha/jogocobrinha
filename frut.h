#pragma once

#include <iostream>
#include "snek.h"
    
    
    namespace snekGame
    {
    
    class Frut
    {
    public:
        std::pair<int, int> pos;
        unsigned pts;
        unsigned score;

        void refresh(std::pair<int, int> Spos)
        {

            pos.first = distrib(gen);
            pos.second = distrib(gen);
            if (pos == Spos)
                refresh(Spos);
        }

        void ate(Snek &S)
        {
            if (S.posTail.at(0) == pos)
            {
                score += pts;
                pts++;
                S.posTail.push_front(S.posTail.at(0));
                refresh(S.posTail.at(0));
            }
        }

        void showScore()
        {
            std::cout << "score: " << score << "\n";
        }
    };
    }