#include <iostream>
#include <cstring>

using namespace std;

const int N = 4;

// int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
//                     { 0, 0, 0, 0, 0, 0, 0, 0 },
//                     { 0, 0, 0, 0, 0, 0, 0, 0 },
//                     { 0, 0, 0, 0, 0, 0, 0, 0 },
//                     { 0, 0, 0, 0, 0, 0, 0, 0 },
//                     { 0, 0, 0, 0, 0, 0, 0, 0 },
//                     { 0, 0, 0, 0, 0, 0, 0, 0 },
//                     { 0, 0, 0, 0, 0, 0, 0, 0 } };

int board[N][N] = { { 0, 0, 0, 0},
                    { 0, 0, 0, 0},
                    { 0, 0, 0, 0},
                    { 0, 0, 0, 0}};

bool is_safe(int row, int col){
    
    if (board[row-1][col]) {
        return false;
    }
    if (board[row-1][col-1]) {
        return false;
    }
    if (board[row][col-1]) {
        return false;
    }
    if (board[row-1][col+1]) {
        return false;
    }
    if (board[row][col+1]) {
        return false;
    }
    if (board[row+1][col+1]) {
        return false;
    }
    if (board[row+1][col]) {
        return false;
    }
    if (board[row+1][col-1]) {
        return false;
    }

	return true;
}

void print_board()
{
    // Print the board
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int place_kings(int x, int y, int count)
{
    // Base case: Ketika semua posisi sudah ditentukan
    if (x == N)
        return count;

    // Pindah ke kolom selanjutnya
    if (y == N)
        return place_kings(x + 1, 0, count);

    // Mencoba meletakkan King di posisi saat ini
    int max_count = count;
    if (is_safe(x, y))
    {
        board[x][y] = 1;

        // Menempatkan sisa King secara rekursif
        int temp = max_count;
        max_count = max(max_count, place_kings(x, y + 1, count + 1));

        if (temp == max_count) {
             // Backtrack
            board[x][y] = 0;
        }
    }

    // Mencoba meletakkan King di posisi saat ini
    max_count = max(max_count, place_kings(x, y + 1, count));

    return max_count;
}

int main()
{
    cout << "Maximum number of kings that can be placed on the board: " << place_kings(0, 0, 0) << endl;
    
    print_board();
    
    return 0;
}