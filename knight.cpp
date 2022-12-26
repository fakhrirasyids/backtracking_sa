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

bool is_safe(int row, int col)
{

	int i,j;
	i = row;
	j = col;
	i = i-2;
	j = j-1;

	if (i >= 0 && j >= 0 && i < N && j < N) {
		if (board[i][j] == 1) {
			return false;
		}
	}

			i = row;
		j = col;
		i = i-2;
		j = j+1;

	if (i >= 0 && j >= 0 && i < N && j < N) {
				if (board[i][j] == 1) {
			return false;
		} 
	}

			i = row;
		j = col;
		i = i-1;
		j = j+2;

	if (i >= 0 && j >= 0 && i < N && j < N) {
				if (board[i][j] == 1) {
			return false;
		} 
	}

			i = row;
		j = col;
		i = i+1;
		j = j+2;

	if (i >= 0 && j >= 0 && i < N && j < N) {
		if (board[i][j] == 1) {
			return false;
		} 
	}

	i = row;
	j = col;
	i = i+2;
	j = j+1;

	if (i >= 0 && j >= 0 && i < N && j < N) {
				if (board[i][j] == 1) {
			return false;
		} 
	}

	
	i = row;
	j = col;
	i = i+2;
	j = j-1;

	if (i >= 0 && j >= 0 && i < N && j < N) {
		if (board[i][j] == 1) {
			return false;
		} 
	}
			
	i = row;
	j = col;
	i = i+1;
	j = j-2;

	if (i >= 0 && j >= 0 && i < N && j < N) {
		if (board[i][j] == 1) {
			return false;
		} 
	}

	i = row;
	j = col;
	i = i-1;
	j = j-2;

	if (i >= 0 && j >= 0 && i < N && j < N) {
		if (board[i][j] == 1) {
			return false;
		}
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

int place_knight(int row, int col, int count){
    // Base case: Ketika semua posisi sudah ditentukan
    if (row == N) {
        return count;
	}

    // Pindah ke kolom selanjutnya
    if (col == N) {
        return place_knight(row + 1, 0, count);
	}

    // Mencoba meletakkan Knight di posisi saat ini
    int max_count = count;
    if (is_safe(row, col))
    {
        board[row][col] = 1;

        int temp = max_count;

		// Menempatkan sisa Knight secara rekursif
        max_count = place_knight(row, col + 1, count + 1);

		if (temp == max_count) {
			// Backtrack
			board[row][col] = 0;
		}
    }

    // Mencoba meletakkan Knight di posisi saat ini
    max_count = max(max_count, place_knight(row, col + 1, count));

    return max_count;
}

int main()
{
    cout << "Maximum number of bishop that can be placed on the board: " << place_knight(0, 0, 0) << endl;
        
		print_board();
    return 0;
}