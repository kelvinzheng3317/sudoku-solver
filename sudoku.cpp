#include <iostream>
using namespace std;

int grid[9][9] = {{0, 0, 0, 0, 0, 0, 2, 0, 0},
                  {0, 8, 0, 0, 0, 7, 0, 9, 0},
                  {6, 0, 2, 0, 0, 0, 5, 0, 0},
                  {0, 7, 0, 0, 6, 0, 0, 0, 0},
                  {0, 0, 0, 9, 0, 1, 0, 0, 0},
                  {0, 0, 0, 0, 2, 0, 0, 4, 0},
                  {0, 0, 5, 0, 0, 0, 6, 0, 3},
                  {0, 9, 0, 4, 0, 0, 0, 7, 0},
                  {0, 0, 6, 0, 0, 0, 0, 0, 0}};

void printGrid()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValidMove(int row, int col, int n)
{
    for (int i = 0; i < 9; ++i)
    {
        if (grid[row][i] == n)
        {
            return false;
        }
        if (grid[i][col] == n)
        {
            return false;
        }
    }

    // checks the box to see if the number is already present
    int boxRow = row / 3;
    int boxCol = col / 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[boxRow * 3 + i][boxCol * 3 + j] == n)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveGrid()
{
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            if (grid[row][col] == 0)
            {
                for (int n = 1; n <= 9; ++n)
                {
                    if (isValidMove(row, col, n))
                    {
                        grid[row][col] = n;
                        solveGrid();
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    cout << "Grid solved" << endl;
    printGrid();
    return true;
}

int main()
{
    printGrid();
    solveGrid();
    return 0;
}
