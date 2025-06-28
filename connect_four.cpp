// Carlyle Ezpeleta - Connect Four in C++

#include <iostream>
#include <ctime>
using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;
const char EMPTY_SPOT = ' ';
const char PLAYER_PIECE = 'x';
const char COMPUTER_PIECE = 'o';

void Print(char board[ROWS][COLUMNS]) {
  for (int i = 0; i < ROWS; i++) {
    cout << "|";
    for (int j = 0; j < COLUMNS; j++) {
      cout << board[i][j] << "|";
    }
    cout << endl;
  }
  cout << endl;
}

bool IsValidMove(char board[ROWS][COLUMNS], int column) {
  return column >= 0 && column < COLUMNS && board[0][column] == EMPTY_SPOT;
}

int GetAvailableRow(char board[ROWS][COLUMNS], int column) {
  for (int i = ROWS - 1; i >= 0; i--) {
    if (board[i][column] == EMPTY_SPOT) return i;
  }
  return -1;
}

void SetPlayerMove(char board[ROWS][COLUMNS]) {
  int col;
  int row;
  do {
