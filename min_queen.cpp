#include <iostream>
#include <algorithm>
#define N 8

using namespace std;

int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 } };

int minCount = 99999999;

bool isAttacked(int row, int col) {
    int i, j;

    // Check the 'col'th column for any queen.
    for (i = 0; i < N; i++)
        if (board[i][col])
            return true;

    // Check the 'row'th row for any queen.
    for (j = 0; j < N; j++)
        if (board[row][j])
            return true;

    // Check the diagonals for any queen.
    for (i = 0; i < N; i++) {
        if (row - i >= 0 && col - i >= 0 && board[row - i][col - i])
            return true;
        else if (row - i >= 0 && col + i < N && board[row - i][col + i])
            return true;
        else if (row + i < N && col - i >= 0 && board[row + i][col - i])
            return true;
        else if (row + i < N && col + i < N && board[row + i][col + i])
            return true;
    }

    // This square is unattacked. Hence return 'false'.
    return false;
}

void printLayout() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}



void placeQueen(int countSoFar) {
    int i, j;
    bool squareNotAttacked = false;

    if (countSoFar >= minCount)
        return;

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (!isAttacked(i, j)) {
                squareNotAttacked = true;
                break;
            }
        }

        if (squareNotAttacked)
            break;
    }

    if (! squareNotAttacked) {
        minCount = countSoFar;
        printLayout();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!isAttacked(i, j)) {
                board[i][j] = 1;

                placeQueen(countSoFar + 1);

                board[i][j] = 0;
            }
        }
    }
}

int main() {
    placeQueen(0);

    cout << endl;
    cout << "Minimun N Queen : " << minCount << endl;

    return 0;
}