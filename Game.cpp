#include "Game.h"
#include <iostream>

Game::Game() {
  showString();
  generateBoard();
  showBoard();
}

void Game::generateBoard() {
  int number{1};
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      board_[i][j] = std::to_string(number).c_str()[0];
      number++;
    }
  }
}

void Game::showBoard() {
  std::cout << '\n';
  std::cout << " +---+---+---+\n";
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << " | " << board_[i][j];
    }
    std::cout << " |\n";
    std::cout << " +---+---+---+\n";
  }
}

void Game::showString() { std::cout << "\nWelcome to XOXOXOXO !!!\n"; }

bool Game::checkCharacter(const char &input) {
  bool check{};
  if (input != ' ') {
    check = (input >= '1' && input <= '9') ? true : false;
  }
  return check;
}

int Game::castCharacter(const char &input) {
  int index = (static_cast<int>(input) - static_cast<int>('0')) - 1;
  return index;
}

int Game::calculateColumn(const int &index) { return index % 3; }

int Game::calculateRow(const int &index) { return index / 3; }

bool Game::checkBoard(const int &indexRow, const int &indexColumn) {
  char boardPosition = board_[indexRow][indexColumn];
  if (boardPosition == 'X' || boardPosition == 'O') {
    return false;
  }
  return true;
}

void Game::printBoardX(const int &indexRow, const int &indexColumn) {
  board_[indexRow][indexColumn] = 'X';
}

void Game::printBoardO(const int &indexRow, const int &indexColumn) {
  board_[indexRow][indexColumn] = 'O';
}

char Game::enterCharacter(const char player) {
  while (true) {
    char input{};
    std::cout << "\nPlease eneter moves (1-9): " << player << '\n';
    std::cin >> input;
    if (checkCharacter(input)) {
      return input;
    } else {
      std::cout << "You have to play in range 1-9!\n";
    }
  }
}


bool Game:: checkEnd(const int counter) {
  if (counter == 9) {
    std:: cout << "\n**************** Draw!!! ****************\n";
    return true;
  }
  return false;
}


void Game::checkForWins(const char player) {
  const std::array<std::string, 8> winningMoves{"123", "147", "159", "258",
                                                "369", "357", "456", "789"};
  static int counter{};
  for (int i = 0; i < 8; ++i) {
    bool winner = true;
    char previousBoard = '0';
    std::string winningMove = winningMoves[i];
    for (int j = 0; j < 3; ++j) {
      char characters = winningMove[j];
      const int indexRow = calculateRow(castCharacter(characters));
      const int indexColumn = calculateColumn(castCharacter(characters));
      char boardChar = board_[indexRow][indexColumn];
      if (previousBoard == '0') {
        previousBoard = boardChar;
      } else if (previousBoard == boardChar) {
        continue;
      } else {
        winner = false;
        break;
      }
    }
    if (winner) {
      std::cout << "\n**************** We have a winner ****************\n"
                << "\n#####           THE PLAYER HAS WON  " << player
                << "       #####" << '\n';
      exit(0);
      break;
    }
  }
  counter++;
  if(checkEnd(counter)) {
    exit(0);
  }
}

void Game::playerNumber1() {
  const char player{'X'};
  std::cout << "\nPLAYER X\n";
  char input = enterCharacter(player);
  int indexRow = calculateRow(castCharacter(input));
  int indexColumn = calculateColumn(castCharacter(input));

  while (true) {
    if (checkBoard(indexRow, indexColumn)) {
      printBoardX(indexRow, indexColumn);
      showBoard();
      checkForWins(player);
      break;
    } else {
      std::cout << "That board position is already taken!\n";
      input = enterCharacter(player);
      indexRow = calculateRow(castCharacter(input));
      indexColumn = calculateColumn(castCharacter(input));
    }
  }
}

void Game::playerNumber2() {
  const char player{'O'};
  std::cout << "\nPLAYER O\n";
  char input = enterCharacter(player);
  int indexRow = calculateRow(castCharacter(input));
  int indexColumn = calculateColumn(castCharacter(input));

  while (true) {
    if (checkBoard(indexRow, indexColumn)) {
      printBoardO(indexRow, indexColumn);
      showBoard();
      checkForWins(player);
      break;
    } else {
      std::cout << "That board position is already taken!\n";
      input = enterCharacter(player);
      indexRow = calculateRow(castCharacter(input));
      indexColumn = calculateColumn(castCharacter(input));
    }
  }
}

void Game::playGame() {
  while (true) {
    playerNumber1();
    playerNumber2();
  }
}