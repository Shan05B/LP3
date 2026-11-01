
#include <iostream>
using namespace std;

int board[20][20];

// Check whether position is safe
bool isSafe(int row, int col, int n) {

    // Check upper column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Solve using Backtracking
bool solveNQueens(int row, int n) {

    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {

        if (isSafe(row, col, n)) {

            board[row][col] = 1;

            if (solveNQueens(row + 1, n))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Invalid size";
        return 0;
    }

    if (solveNQueens(0, n)) {

        cout << "\nN-Queens Matrix:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

    } else {
        cout << "Solution does not exist";
    }

    return 0;
}
