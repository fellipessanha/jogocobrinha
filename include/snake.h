#pragma once

#include <vector>
#include <random>
#include <deque>
#include <ncurses.h>

namespace snake_game {

const unsigned dimension = 20;

enum class eDirection
{
  STOP = 0,
  L,
  R,
  U,
  D
};

class Snake
{
  eDirection dir;
  void updTail();
  void move(bool &stats);

  public:
    std::deque<std::pair<int, int>> posTail;
    Snake();
    void input(bool &stats);
};

} // end namespace snake_game