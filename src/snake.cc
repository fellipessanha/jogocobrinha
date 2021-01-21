#include <snake.h>

namespace snake_game {

void Snake::updTail() {
  if (dir != eDirection::STOP) {
    for (unsigned i = posTail.size(); i > 0; i--) {
      posTail.at(i) = posTail.at(i - 1);
    }
  }
}


void Snake::move(bool &stats) {
  switch (dir)
  {
    case eDirection::STOP:
      break;
    case eDirection::U:
      posTail.at(0).second--;
      break;
    case eDirection::L:
      posTail.at(0).first--;
      break;
    case eDirection::R:
      posTail.at(0).first++;
      break;
    case eDirection::D:
      posTail.at(0).second++;
      break;
  }

  if (posTail.at(0).second < 0 || posTail.at(0).second > dimension - 1 ||
      posTail.at(0).first < 0 || posTail.at(0).first > dimension - 1) {
    printw("Game over, man. Game over\n");
    stats = !stats;
  }
}

Snake::Snake() {
  posTail.push_back(std::make_pair(dimension / 2, dimension / 2));
  dir = eDirection::STOP;
}

void Snake::input(bool &stats) {
  switch (getch()) {
    case 'w':
      dir = eDirection::U;
      break;
    case 'a':
      dir = eDirection::L;
      break;
    case 'd':
      dir = eDirection::R;
      break;
    case 's':
      dir = eDirection::D;
      break;
  }
  move(stats);
}

} // end namespace snake_game