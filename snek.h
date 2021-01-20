#pragma once

#include <vector>
#include <random>
#include <conio.h>
#include <deque>

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
            int x = posTail.at(0).first;
            int y = posTail.at(0).second;

            switch (dir)
            {
            case STOP:
                break;
            case U:
                posTail.push_front(std::make_pair(x, y--));
                break;
            case L:
                // posTail.at(0).first--;
                posTail.push_front(std::make_pair(x--, y));
                break;
            case R:
                // posTail.at(0).first++;
                posTail.push_front(std::make_pair(x++, y));
                break;
            case D:
                // posTail.at(0).second++;
                posTail.push_front(std::make_pair(x, y++));
                break;
            }
            posTail.pop_back();
            // updTail();

            if (posTail.at(0).second < 0 || posTail.at(0).second > dimension - 1 ||
                posTail.at(0).first < 0 || posTail.at(0).first > dimension - 1)
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
            posTail.push_back(std::make_pair(posTail.at(0).first, posTail.at(0).second + 1));
            posTail.push_back(std::make_pair(posTail.at(0).first, posTail.at(0).second + 2));
            dir = U;
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

} // namespace snekGame