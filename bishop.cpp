#include <iostream>
#include <cstring>

using namespace std;

const int N = 8;

int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 } };

// int board[N][N] = { { 0, 0, 0, 0},
//                     { 0, 0, 0, 0},
//                     { 0, 0, 0, 0},
//                     { 0, 0, 0, 0}};

bool is_safe(int row, int col)
{
    int i,j;

	/* Cek diagonal atas di sisi kiri */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Cek diagonal bawah di sisi kiri */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

    /* Cek diagonal atas sisi kanan */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j++)
		if (board[i][j])
			return false;

	/* Cek diagonal bawah sisi kanan */
	for (i = row, j = col; j >= 0 && i < N; i++, j++)
		if (board[i][j])
			return false;

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

int place_bishop(int row, int col, int count)
{
    // Ketika semua posisi sudah ditentukan
    if (row == N){
        return count;
    }   

    // Pindah ke kolom selanjutnya
    if (col == N) {
        return place_bishop(row + 1, 0, count);
    }  

    // Mencoba meletakkan bishop di posisi saat ini
    int max_count = count;
    if (is_safe(row, col))
    {
        board[row][col] = 1;
        int temp = max_count;
    
        // Menempatkan sisa bishop secara rekursif
        max_count = place_bishop(row, col + 1   , count + 1);

        if (temp == max_count) {
             // Backtrack
             cout << "fakhri" << endl;
            board[row][col] = 0;
        }
    }

    // Mencoba meletakkan bishop di posisi saat ini
    max_count = max(max_count, place_bishop(row, col + 1, count));

    return max_count;
}

int main()
{
    cout << "Maximum number of bishop that can be placed on the board: " << place_bishop(0, 0, 0) << endl;
    
    print_board();
    
    return 0;
}