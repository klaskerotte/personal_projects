#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

// Source - https://stackoverflow.com/a
// Posted by Cat Plus Plus
// Retrieved 2025-12-24, License - CC BY-SA 3.0

void clear() {
  // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
  std::cout << "\x1B[2J\x1B[H";
};

class board {
public:
  static constexpr int width = 49;  // Multiples of 16 + 1 in mind
  static constexpr int height = 25; // Multiples of 8 + 1

  bool player_flag = true;
  bool active_flag = true;
  char board[height][width];

  std::string used_coordinates[9];
  int turn = 0;

  // Board initializer with width and height.
  void init_board(char (&boardarray)[height][width]) {
    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++) {
        if (((i % 8) == 0) || i == height - 1) {
          boardarray[i][j] = '-';
        } else {
          boardarray[i][j] = '.';
        }
        if (((j % 16) == 0) || j == width - 1) {
          boardarray[i][j] = '|';
        }
      }
  }

  // Draws the current state of the board
  void drawboard() {
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++)
        std::cout << board[i][j];
      std::cout << '\n';
    }
  }

  // Draws a circle or a cross depending on the player turn.
  int draw_circle_cross(char (&boardarray)[height][width], bool &player_flag,
                        std::string (&used_coordinates)[9], int &turn,
                        bool &active_flag) {
    std::string coordinate;

    std::cout << "What coordinate does player " << player_flag
              << " want to choose? \nGive input in the form of two integers "
                 "choosing row and column"
              << std::endl;

    std::cin >> coordinate;
    if (coordinate == "quit") {
      std::cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n"
                << std::endl;

      std::cout << "\tThanks for playing!, byebye :D\n" << std::endl;

      std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n"
                << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));

      active_flag = !active_flag;
      return 0;
    }

    // Update used coordinates and turn count.
    used_coordinates[turn] = coordinate;
    turn++;

    // Update player turn and switch between patched drawing and clear drawing
    if (player_flag) {
      int add_height, add_width;
      add_height = (coordinate[0] - '0' - 1) * 8;
      add_width = (coordinate[1] - '0' - 1) * 16;

      for (int i = add_height + 2; i < 7 + add_height; i++)
        for (int j = add_width + 2; j < 15 + add_width; j++)
          boardarray[i][j] = 'O';
    }

    if (!player_flag) {
      int add_height, add_width;
      add_height = (coordinate[0] - '0' - 1) * 8;
      add_width = (coordinate[1] - '0' - 1) * 16;

      for (int i = add_height + 2; i < 7 + add_height; i += 2)
        for (int j = add_width + 2; j < 15 + add_width; j += 2)
          boardarray[i][j] = 'X';
    }

    // Flip the player
    player_flag = !player_flag;

    return 0;
  }
};

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
      std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n"
                << std::endl;
      std::cout << "\tGame is over, reloading new board" << std::endl;
      std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n"
                << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(2500));

      tictactoe.init_board(tictactoe.board);
      tictactoe.turn = 0;
      clear();
    }
  }
  clear();

  return 0;
}
