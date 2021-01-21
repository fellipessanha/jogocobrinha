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

        void refresh(std::deque<std::pair<int, int>> body)
        {
            pos.first = snekGame::distrib(snekGame::gen);
            pos.second = snekGame::distrib(snekGame::gen);

            for (std::pair<int, int> Spos: body)
            {
                if (pos == Spos)
                    refresh(body);
            }
        }

        void ate(snekGame::Snek &S)
        {
            if (S.posTail.front() == pos)
            {
                score += pts;
                pts++;
                S.posTail.push_front(S.posTail.front());
                refresh(S.posTail);
            }
        }

        void showScore()
        {
            std::cout << "score: " << score << "\n";
        }
    };
}