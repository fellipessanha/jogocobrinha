#include <vector>
#include <snake.h>
#include <fruit.h>
#include <visuals.h>

// global variables
bool gameOver;
snake_game::Snake snek;
snake_game::Fruit frut;

// functions
void setup() {
  gameOver = false;
  frut.refresh(snek.posTail.at(0));
  frut.pts = 1;
}

int main()
{
  initscr();
  cbreak();
  noecho();
  scrollok(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  
  setup();

  while (!gameOver) {
      visuals::draw(snek, frut);
      snek.input(gameOver);
      frut.ate(snek);
      // frut.showScore();
  }
  return 0;
}