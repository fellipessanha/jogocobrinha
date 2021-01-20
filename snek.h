#pragma once

#include <vector>
#include <random>
#include <conio.h>
#include <deque>
// #include "frut.h"

namespace snekGame
{

    enum eDirection
    {
        STOP = 0,
        L,
        R,
        U,
        D
    };
    const unsigned dimension = 20;

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, dimension - 1);

    class Snek
    {
    private:
        eDirection dir;

        // used on movement, with the commented line change instructions        
        void updTail()
        {
            if (dir != STOP)
            {
                for (unsigned i = 1; i > posTail.size(); i--)
                {
                    posTail.at(i) = posTail.at(i - 1);
                }
            }
        }

        void Move(bool &stats)
        {
            int x = posTail.front().first;
            int y = posTail.front().second;
            switch (dir)
            {
            case STOP:
                break;
            case U:
                y--;
                break;
            case L:
                x--;
                break;
            case R:
                x++;
                break;
            case D:
                y++;
                break;
            }
            posTail.push_front(std::make_pair(x, y));
            posTail.pop_back();
            // updTail();

            if (posTail.front().second < 0 || posTail.front().second > dimension - 1 ||
                posTail.front().first < 0 || posTail.front().first > dimension - 1)
            {
                std::cout << "Game over, man. Game over"
                          << "\n";
                stats = !stats;
            }
        }

    public:
        std::deque<std::pair<int, int>> posTail;

        Snek()
        {

            posTail.push_back(std::make_pair(dimension / 2, dimension / 2));
            posTail.push_back(std::make_pair(posTail.front().first, posTail.front().second + 1));
            posTail.push_back(std::make_pair(posTail.front().first, posTail.front().second + 2));
            dir = STOP;
        }

        void Input(bool &stats)
        {
            if (_kbhit())
            {
                switch (_getch())
                {
                case 'w':
                    dir = U;
                    break;
                case 'a':
                    dir = L;
                    break;
                case 'd':
                    dir = R;
                    break;
                case 's':
                    dir = D;
                    break;
                }
            }
            Move(stats);
        }
    };

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
                S.posTail.push_back(S.posTail.back());
                refresh(S.posTail.front());
            }
        }

        void showScore()
        {
            std::cout << "score: " << score << "\n";
        }
    };

} // namespace snekGame
