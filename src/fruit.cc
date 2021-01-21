#include <fruit.h>

namespace snake_game {

Fruit::Fruit() :
  gen((std::random_device())())
  {}

void Fruit::refresh(std::pair<int, int> Spos) {
  std::uniform_int_distribution<int> dist(0, dimension - 1);
  pos.first = dist(gen);
  pos.second = dist(gen);
  if (pos == Spos)
    refresh(Spos);
}

void Fruit::ate(Snake &S) {
  if (S.posTail.at(0) == pos) {
    score += pts;
    pts++;
    refresh(S.posTail.at(0));
  }
}

void Fruit::showScore() const {
  printw("score: ", score, "\n");
}

} // end namespace snake_game