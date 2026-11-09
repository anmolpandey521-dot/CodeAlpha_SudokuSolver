# Sudoku Solver Using C++

A console-based Sudoku solver written in C++. It represents the board with a 9×9 two-dimensional array and uses recursive backtracking to solve the puzzle.

## Features
- Takes a Sudoku puzzle as user input.
- Uses `0` for empty cells.
- Checks row, column, and 3×3 subgrid constraints.
- Solves the puzzle using recursion and backtracking.
- Detects conflicting starting values and puzzles with no solution.
- Displays the original and solved grids.

## Requirements
- A C++ compiler such as GCC (`g++`).
- Visual Studio Code (optional).

## Compile

```bash
g++ Sudoku_Solver.cpp -o Sudoku_Solver
```

## Run

Windows:
```bash
Sudoku_Solver.exe
```

Linux/macOS:
```bash
./Sudoku_Solver
```

## Sample Input

Enter these nine rows when prompted:

```text
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

## How the Algorithm Works
1. Find an empty cell (value `0`).
2. Try numbers from `1` to `9`.
3. Check whether each number is valid in the cell's row, column, and 3×3 subgrid.
4. Place a valid number and recursively solve the remaining cells.
5. If a choice leads to a dead end, reset the cell to `0` and try another number.
6. When no empty cells remain, the puzzle is solved.

## C++ Concepts Used
- Two-dimensional arrays
- Functions
- Loops and conditional statements
- Recursion
- Backtracking

## Note
This project uses a console interface. It solves an entered puzzle; it does not generate puzzles or include a GUI.
