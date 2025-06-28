# 🎮 Connect Four — C++ Game

Welcome to my version of **Connect Four**, built in C++!  
This is a 2-player console-based game inspired by my Tic Tac Toe project, extended with logic for vertical gravity and 4-in-a-row win conditions.

## 🧠 What I Learned
- How to reuse and modify existing code (from my Tic Tac Toe game) to build something more complex
- How to implement game logic for different win conditions: horizontal, vertical, and diagonal
- Handling edge cases like full columns and invalid inputs
- Using functions and loops for better structure and clarity

## 🎯 Game Rules
- The game board is **7 columns x 6 rows**
- Player and computer take turns dropping pieces into a column
- A piece drops to the **lowest available row** in the selected column
- The first to connect **4 in a row** horizontally, vertically, or diagonally wins

## 🕹 Sample Board
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | |o| | |
| | | |o|x| | |
|x| |o|x|x| | |

## 🧪 Features
- Validates user and computer moves (only allows selecting columns with space)
- Automatically alternates turns
- Detects win and draw states
- Ends game after win or draw
- Optionally allows simple AI (extra credit)

## 💻 How to Compile & Run
```bash
g++ connect_four.cpp -o connect_four
./connect_four
