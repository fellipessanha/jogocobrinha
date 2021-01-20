#pragma once

#include <vector>
#include <random>
#include <conio.h>
#include <deque>



namespace snekGame
{

enum eDirection{STOP = 0, L, R, U, D};
const unsigned dimension = 20;

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> distrib(0, dimension - 1);

class Snek
{
private:
    eDirection dir;

    void updTail()
    {
        if (dir != STOP)
        {
            for (unsigned i = posTail.size(); i >0 ; i--)
            {
            posTail.at(i) = posTail.at(i - 1);
            }
        }
    }

    void Move(bool& stats)
    {
        switch (dir)
        {
        case STOP:
            break;
        case U:
            posTail.at(0).second--;
            break;
        case L:
            posTail.at(0).first--;
            break;
        case R:
            posTail.at(0).first++;
            break;
        case D:
            posTail.at(0).second++;
            break;
        }

        if (posTail.at(0).second < 0 || posTail.at(0).second > dimension - 1 || 
            posTail.at(0).first  < 0 || posTail.at(0).first  > dimension - 1 )
        {
            std::cout << "Game over, man. Game over" << "\n";
            stats = !stats;
        }
    }
public:

    std::deque<std::pair<int,int>> posTail;

    Snek(){
        
        posTail.push_back(std::make_pair(dimension/2, dimension/2));
        dir = STOP;        
    }


    void Input(bool& stats)
    {
        if( _kbhit())
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

    std::pair<int,int> pos;
    unsigned pts;
    unsigned score;

    void refresh(std::pair<int, int> Spos){

        pos.first  = distrib(gen);
        pos.second = distrib(gen);
        if (pos == Spos) refresh(Spos);
    }

    void ate(Snek& S){
        if (S.posTail.at(0) == pos){
            score += pts;
            pts++;
            refresh(S.posTail.at(0));
        }
    }

    void showScore(){
        std::cout << "score: " << score << "\n";
    }
};
}