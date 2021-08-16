#include <array>
#include <iostream>

class Game {
  std::array<std::array<char, 3>, 3> board_;

public:
  Game();

  void generateBoard();
  void showBoard();
  void showString();
  void printBoardX(const int &indexRow, const int &indexColumn);
  void printBoardO(const int &indexRow, const int &indexColumn);
  void playGame();
  void checkForWins(const char player);
  void playerNumber1();
  void playerNumber2();
  int calculateColumn(const int &index);
  int castCharacter(const char &input);
  int calculateRow(const int &index);
  bool checkCharacter(const char &input);
  bool checkBoard(const int &indexRow, const int &indexColumn);
  bool checkEnd(const int counter);
  char enterCharacter(const char player);
};