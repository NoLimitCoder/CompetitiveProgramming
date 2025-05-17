#include <iostream>
#include <string>
using namespace std;

const int N = 8;

// Global board to store the input
char board[N][N];

// Arrays to mark whether a column or diagonal is occupied
bool col[N] = { false };
bool diag1[15] = { false };  // diag1: row - col + 7, range: 0 .. 14
bool diag2[15] = { false };  // diag2: row + col, range: 0 .. 14

// Global variable to count the number of valid solutions
unsigned long long solutionCount = 0;

// Recursive function to place queens row by row.
void backtrack(int row) {
    // If we've placed queens in all 8 rows, we've found a valid solution.
    if (row == N) {
        solutionCount++;
        return;
    }
    
    // Try placing a queen in each column of the current row.
    for (int j = 0; j < N; j++) {
        // Check if the cell (row, j) is free and safe.
        if (board[row][j] == '.' && !col[j] && !diag1[row - j + 7] && !diag2[row + j]) {
            // Place the queen by marking the column and diagonals as used.
            col[j] = true;
            diag1[row - j + 7] = true;
            diag2[row + j] = true;
            
            // Recurse for the next row.
            backtrack(row + 1);
            
            // Backtrack: remove the queen and mark the column/diagonals as free.
            col[j] = false;
            diag1[row - j + 7] = false;
            diag2[row + j] = false;
        }
    }
}

int main() {
    // Read the chessboard: 8 lines of 8 characters.
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            board[i][j] = line[j];
        }
    }
    
    // Start the recursive backtracking from row 0.
    backtrack(0);
    
    // Output the number of valid arrangements.
    cout << solutionCount << "\n";
    
    return 0;
}
