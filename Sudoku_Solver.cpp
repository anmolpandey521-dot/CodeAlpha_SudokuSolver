#include <iostream>
using namespace std;

const int SIZE = 9;

void printGrid(int grid[SIZE][SIZE])
{
    cout << "\n+-------+-------+-------+\n";
    for (int row = 0; row < SIZE; row++)
    {
        cout << "| ";
        for (int col = 0; col < SIZE; col++)
        {
            cout << (grid[row][col] == 0 ? ". " : to_string(grid[row][col]) + " ");
            if ((col + 1) % 3 == 0) cout << "| ";
        }
        cout << '\n';
        if ((row + 1) % 3 == 0) cout << "+-------+-------+-------+\n";
    }
}

bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    for (int i = 0; i < SIZE; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool isValidGrid(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            int num = grid[row][col];
            if (num < 0 || num > 9) return false;

            if (num != 0)
            {
                grid[row][col] = 0;
                bool valid = isSafe(grid, row, col, num);
                grid[row][col] = num;
                if (!valid) return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) return true;
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int grid[SIZE][SIZE];

    cout << "========== SUDOKU SOLVER ==========\n";
    cout << "Enter 9 rows of 9 numbers. Use 0 for empty cells.\n\n";

    for (int row = 0; row < SIZE; row++)
    {
        cout << "Row " << row + 1 << ": ";
        for (int col = 0; col < SIZE; col++)
        {
            if (!(cin >> grid[row][col]))
            {
                cout << "Invalid input. Enter integers only.\n";
                return 1;
            }
        }
    }

    if (!isValidGrid(grid))
    {
        cout << "\nInvalid puzzle: conflicting or out-of-range values.\n";
        return 1;
    }

    cout << "\nOriginal Sudoku:";
    printGrid(grid);

    if (solveSudoku(grid))
    {
        cout << "\nSolved Sudoku:";
        printGrid(grid);
    }
    else
    {
        cout << "\nThis Sudoku puzzle has no solution.\n";
    }

    return 0;
}
