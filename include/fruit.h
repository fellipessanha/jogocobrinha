#pragma once 

#include <snake.h>
#include <utility>

namespace snake_game {

class Fruit
{
std::mt19937 gen; // Standard mersenne_twister_engine seeded with rd()
public:
  std::pair<int, int> pos;
  unsigned pts;
  unsigned score;

  Fruit();

  void refresh(std::pair<int, int> Spos);
  void ate(Snake &S);
  void showScore() const;
};

} // end namespace snake_game