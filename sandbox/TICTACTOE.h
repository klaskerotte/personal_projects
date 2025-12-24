
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

class board {
public:
  static constexpr int width = 49;
  static constexpr int height = 25;

  bool player_flag = true;
  bool active_flag = true;
  char board[height][width];

  std::string used_coordinates[9];
  int turn = 0;

  void init_board(char (&boardarray)[height][width]);
  void drawboard();
  int draw_circle_cross(char (&boardarray)[height][width], bool &player_flag,
                        std::string (&used_coordinates)[9], int &turn,
                        bool &active_flag);
};

void clear();

#endif
