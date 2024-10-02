# Tic Tac Toe Game

This project is a simple **Tic Tac Toe** game written in C++. It allows two players to play against each other in a command-line interface. The game uses a 3x3 grid where players take turns to place their marks (X or O) and the game detects the winner when a player successfully places three of their marks in a row, column, or diagonal.

## Features

- **Player Input**: The game takes player inputs for row and column numbers.
- **Input Validation**: Ensures valid inputs within the game board range and prevents overwriting an already occupied cell.
- **Random Number Generation**: Includes utility functions for random number generation and input handling.
- **Winner Detection**: Automatically detects when a player wins the game by forming a straight line of three identical marks.
- **Draw Condition**: If no player wins within 9 moves, the game ends in a draw.

## How to Play

1. The game starts with a blank 3x3 grid.
2. Players take turns to input their moves (rows and columns) using numbers from 1 to 3.
3. If a player successfully aligns three of their marks (X or O) in a row, column, or diagonal, they win the game.
4. If all 9 cells are filled without a winner, the game ends in a draw.

### Sample Grid
Col 1 2 3
Row 1 [ ] [ ] [ ] 
Row 2 [ ] [ ] [ ] 
Row 3 [ ] [ ] [ ]

### Controls

- Enter the row (1-3) and column (1-3) for your move when prompted.
- The game will notify you if the selected cell is already taken or if your input is invalid.
- The game will automatically update the grid after each move.

## Code Structure

- **`print` function**: Outputs a message followed by a newline.
- **`printNoNewLine` function**: Outputs a message without a newline.
- **`input` function**: Takes a message and returns user input.
- **`GenRandomInt` function**: Generates a random integer within a specified range.
- **`RangeIntInput` function**: Takes input from the user and validates it to ensure it is within the given range.
- **`printBox` function**: Displays the current state of the Tic Tac Toe grid.
- **`checkForWinner` function**: Checks the grid for three consecutive matching marks to declare a winner.

## Requirements

- C++ Compiler (g++, Visual Studio, etc.)
