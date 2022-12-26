#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define N 8
using namespace std;

vector<vector<int>> tupple;
int currentTupple = 0;
int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 } };

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}

void printTupple(vector<int> tupple) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(tupple[j] == i)
                cout << "Q ";
            else cout<<". ";
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQUtil(int board[N][N], int col)
{
	/* base case: If all queens are placed
	then return true */
	if (col >= N) {
        tupple.push_back(vector<int>());

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(board[j][i])
                    tupple[currentTupple].push_back(j);
            }
        }

        currentTupple++;

        return true;
	}

	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;

			if (solveNQUtil(board, col + 1)) {
                board[i][col] = 0;
                continue;
			}

			board[i][col] = 0;
		}
	}

	return false;
}

bool solveNQ()
{
	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	return true;
}

int main()
{
	solveNQ();
	int counter = 1;
	for (vector<int> i: tupple) {
        cout << endl;
        cout << "possible " << counter << ". : ";

        for (int j: i)
            cout << j << ' ';

        counter++;
	}
    cout << endl;

	int input;
	while (input != 0) {
        cout << "print possibility ke : ";
        cin >> input;

        printTupple(tupple[input-1]);
	}

	return 0;
}