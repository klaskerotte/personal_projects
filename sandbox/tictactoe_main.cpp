#include "TICTACTOE.h"
#include <chrono>
#include <iostream>
#include <thread>

int main() {
  clear();
  board tictactoe;

  tictactoe.init_board(tictactoe.board);

  std::cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n"
            << std::endl;

  std::cout << "\tWelcome to tic tac toe\n" << std::endl;
  std::cout << "\tMade by Samuel Haugum\n" << std::endl;
  std::cout << "\tType quit to exit game\n" << std::endl;

  std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));

  clear();
  tictactoe.drawboard();

  // draw a circle

  while (tictactoe.active_flag) {
    tictactoe.draw_circle_cross(tictactoe.board, tictactoe.player_flag,
                                tictactoe.used_coordinates, tictactoe.turn,
                                tictactoe.active_flag);
    clear();
    tictactoe.drawboard();

    if (tictactoe.turn >= 9) {

      std::this_thread::sleep_for(std::chrono::milliseconds(2500));
      clear();
      std::cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n"
                << std::endl;
      std::cout << "\tGame is over, reloading new board" << std::endl;
      std::cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n"
                << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(2500));

      tictactoe.init_board(tictactoe.board);
      tictactoe.turn = 0;
      clear();
      tictactoe.drawboard();
    }
  }
  clear();

  return 0;
}
