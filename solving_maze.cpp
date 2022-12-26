#include <iostream>

const int MAZE_SIZE = 4;

// The maze grid
// int maze[MAZE_SIZE][MAZE_SIZE] = {
//     { 1, 0, 1, 1, 1, 1, 1, 1 },
//     { 1, 0, 0, 0, 0, 0, 0, 1 },
//     { 1, 0, 1, 1, 1, 1, 0, 1 },
//     { 1, 1, 1, 0, 0, 1, 0, 1 },
//     { 1, 0, 1, 0, 1, 1, 0, 1 },
//     { 1, 0, 0, 0, 0, 0, 0, 1 },
//     { 1, 0, 1, 1, 1, 1, 0, 1 },
//     { 1, 1, 1, 1, 0, 0, 0, 1 }
// };

    int maze[MAZE_SIZE][MAZE_SIZE] = {
    { 0, 0, 0, 0 },
    { 1, 0, 1, 0 },
    { 1, 0, 1, 1 },
    { 1, 0, 0, 0 },
    };

// The starting and ending positions
// int startRow = 0, startCol = 1;
// int endRow = 7, endCol = 4;

int startRow = 0, startCol = 0;
// finish
int endRow = 3, endCol = 3;

// Function to check if a given position is valid or not
bool isValid(int row, int col)
{
    // check if the given position is outside the maze
    if (row < 0 || row >= MAZE_SIZE || col < 0 || col >= MAZE_SIZE)
        return false;

    // check if the given position is a wall
    if (maze[row][col] == 1)
        return false;

    // check if the given position has already been visited
    if (maze[row][col] == 2)
        return false;

    return true;
}

// Recursive function to solve the maze
bool solveMaze(int row, int col)
{
    // base case: if the current position is the ending position, return true
    if (row == endRow && col == endCol)
        return true;

    // check if the current position is valid
    if (isValid(row, col))
    {
        // mark the current position as visited
        maze[row][col] = 2;

        // try to solve the maze by moving to the right, left, up, or down
        if (solveMaze(row + 1, col)) return true;
        if (solveMaze(row - 1, col)) return true;
        if (solveMaze(row, col + 1)) return true;
        if (solveMaze(row, col - 1)) return true;

        // if none of the above movements work, backtrack
        maze[row][col] = 0;
    }

    return false;
}

int main()
{
    // try to solve the maze
    if (solveMaze(startRow, startCol))
    {
        // print the solution
        for (int i = 0; i < MAZE_SIZE; i++)
        {
            for (int j = 0; j < MAZE_SIZE; j++)
                std::cout << maze[i][j] << " ";
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}