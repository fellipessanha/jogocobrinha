#pragma once

#include <snake.h>

namespace visuals {

void draw(snake_game::Snake S, snake_game::Fruit F) {

  //std::system("cls");
  bool print;

  // top line
  printw(" ");
  for (unsigned i = 0; i < snake_game::dimension; i++)
    printw("#");
  printw("\n");

  // Game canvas and side walls
  for (unsigned j = 0; j < snake_game::dimension; j++) {
    printw("!");
    
    for (unsigned i = 0; i < snake_game::dimension; i++) {
      print = true;
      for (unsigned k = 0; k < S.posTail.size(); k++) {
        if (i == S.posTail.at(k).first && j == S.posTail.at(k).second) {
          if (k == 0) {
            printw("S");
            print = false;
          }
          else {
            printw("e");
            print = false;
          }
        }
      }

      if (i == F.pos.first && j == F.pos.second) {
        printw("0");
        print = false;
      }

      if (print == true) {
        if (print = true)
          printw(" ");
      }
    }

    printw("!");
    printw("\n");
  }

  // bottom line
  printw(" ");
  for (unsigned i = 0; i < snake_game::dimension; i++)
    printw("#");
  printw(" \n");

  // here for debug reasons: displays the snake coordinates
  // for (int k = 0; k < S.posTail.size(); k++)
  //         std::cout << k << ": " << S.posTail.at(k).first <<", "<< S.posTail.at(k).second << "\n";
  // std::cout << "\n------------------------------\n";
}

} // end namespace visuals