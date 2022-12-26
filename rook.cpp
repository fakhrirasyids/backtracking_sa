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

	/* Check upper diagonal on left side */
	for (i = row; i >= 0; i--)
		if (board[i][col])
			return false;

	/* Check lower diagonal on left side */
	for (i = row;i < N; i++)
		if (board[i][col])
			return false;

            /* Check upper diagonal on left side */
	for (j = col;j >= 0; j--)
		if (board[row][j])
			return false;

	/* Check lower diagonal on left side */
	for (j = col;j < N; j++)
		if (board[row][j])
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

int place_rook(int x, int y, int count){
    // Base case: Ketika semua posisi sudah ditentukan
    if (x == N)
        return count;

    // Pindah ke kolom selanjutnya
    if (y == N)
        return place_rook(x + 1, 0, count);

    // Mencoba meletakkan Rook di posisi saat ini
    int max_count = count;
    if (is_safe(x, y))
    {
        board[x][y] = 1;

        // Menempatkan sisa Rook secara rekursif
        int temp = max_count;
        max_count = max(max_count, place_rook(x,- y + 1, count + 1));

        if (temp == max_count) {
             // Backtrack
            board[x][y] = 0;
        }
    }

    // Mencoba meletakkan Rook di posisi saat ini
    max_count = max(max_count, place_rook(x, y + 1, count));

    return max_count;
}

int main()
{
    cout << "Maximum number of bishop that can be placed on the board: " << place_rook(0, 0, 0) << endl;
    
    print_board();
    
    return 0;
}