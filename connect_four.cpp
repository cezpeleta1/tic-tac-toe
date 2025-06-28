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
  int column;
  do {
    cout << "Enter a column (0 to 6): ";
    cin >> column;
    if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
      column = -1;
    }
  } while (!IsValidMove(board, column));
  int row = GetAvailableRow(board, column);
  board[row][column] = PLAYER_PIECE;
}

void SetComputerMove(char board[ROWS][COLUMNS]) {
  int column;
  do {
    column = rand() % COLUMNS;
  } while (!IsValidMove(board, column));
  int row = GetAvailableRow(board, column);
  board[row][column] = COMPUTER_PIECE;
  cout << "Computer played column: " << column << endl;
}

bool CheckLine(char board[ROWS][COLUMNS], int startRow, int startCol, int dRow, int dCol, char piece) {
  for (int i = 0; i < 4; i++) {
    int r = startRow + i * dRow;
    int c = startCol + i * dCol;
    if (r < 0 || r >= ROWS || c < 0 || c >= COLUMNS || board[r][c] != piece) {
      return false;
    }
  }
  return true;
}

bool IsWinner(char board[ROWS][COLUMNS], char piece) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (CheckLine(board, i, j, 0, 1, piece) ||     // horizontal
          CheckLine(board, i, j, 1, 0, piece) ||     // vertical
          CheckLine(board, i, j, 1, 1, piece) ||     // diagonal down-right
          CheckLine(board, i, j, 1, -1, piece)) {    // diagonal down-left
        return true;
      }
    }
  }
  return false;
}

bool IsBoardFull(char board[ROWS][COLUMNS]) {
  for (int j = 0; j < COLUMNS; j++) {
    if (board[0][j] == EMPTY_SPOT) return false;
  }
  return true;
}

int main() {
  srand(time(0));
  char board[ROWS][COLUMNS];

  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLUMNS; j++)
      board[i][j] = EMPTY_SPOT;

  Print(board);

  while (true) {
    SetPlayerMove(board);
    Print(board);
    if (IsWinner(board, PLAYER_PIECE)) {
      cout << "You win!" << endl;
      break;
    }
    if (IsBoardFull(board)) {
      cout << "It's a draw!" << endl;
      break;
    }

    SetComputerMove(board);
    Print(board);
    if (IsWinner(board, COMPUTER_PIECE)) {
      cout << "Computer wins!" << endl;
      break;
    }
    if (IsBoardFull(board)) {
      cout << "It's a draw!" << endl;
      break;
    }
  }

  return 0;
}
