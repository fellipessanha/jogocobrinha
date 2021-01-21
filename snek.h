#pragma once

#include <vector>
#include <random>
#include <conio.h>
#include <deque>
#include "frut.h"

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

        bool collision()
        {

            if (posTail.front().second < 0 || posTail.front().second > dimension - 1 ||
                posTail.front().first < 0 || posTail.front().first > dimension - 1)
            {
                std::cout << "Game over, man. Game over"
                          << "\n";
                return true;
            }

            for (int k = 1; k < posTail.size(); k++)
            {
                if (posTail.front() == posTail.at(k))
                {
                    std::cout << "Game over, man. Game over"
                              << "\n";
                    return true;
                }
            }
            return false;
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
                if(dir != D)
                    y--;
                break;
            case L:
                if(dir != R)
                    x--;
                break;
            case R:
                if(dir != L)
                    x++;
                break;
            case D:
                if(dir != U)
                    y++;
                break;
            }
            if (dir != STOP)
            {
                posTail.push_front(std::make_pair(x, y));
                posTail.pop_back();
            }

            if (collision())
                stats = !stats;
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
                    if (dir != D)
                        dir = U;
                    break;
                case 'a':
                    if (dir != R)
                        dir = L;
                    break;
                case 'd':
                    if (dir != L)
                        dir = R;
                    break;
                case 's':
                    if (dir != U)
                        dir = D;
                    break;
                }
            }
            Move(stats);
        }
    };

    // class Frut
    // {
    // public:
    //     std::pair<int, int> pos;
    //     unsigned pts;
    //     unsigned score;

    //     void refresh(std::deque<std::pair<int, int>> body)
    //     {
    //         pos.first = distrib(gen);
    //         pos.second = distrib(gen);

    //         for (std::pair<int, int> Spos: body)
    //         {
    //             if (pos == Spos)
    //                 refresh(body);
    //         }
    //     }

    //     void ate(snekGame::Snek &S)
    //     {
    //         if (S.posTail.front() == pos)
    //         {
    //             score += pts;
    //             pts++;
    //             S.posTail.push_front(S.posTail.front());
    //             refresh(S.posTail);
    //         }
    //     }

    //     void showScore()
    //     {
    //         std::cout << "score: " << score << "\n";
    //     }
    // };

} // namespace snekGame