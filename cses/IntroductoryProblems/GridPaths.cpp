#include <iostream>
#include <string>
using namespace std;

const int N = 7;       // grid is 7x7
const int STEPS = 48;  // total number of moves

// The grid: we mark visited cells
bool visited[N][N] = { {false} };

// The input pattern (48 characters)
string pattern;

// Count the number of valid paths
long long ans = 0;

// Directions: Up, Down, Left, Right.
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
// Corresponding characters for moves.
char dirC[4] = { 'U', 'D', 'L', 'R' };

// Recursive DFS function: r, c are current cell; step is current move index (0-indexed).
void dfs(int r, int c, int step) {
    // If we have used all 48 moves...
    if (step == STEPS) {
        // We have a valid path only if we ended at the target (6,0).
        if (r == N - 1 && c == 0)
            ans++;
        return;
    }
    
    // If we reach the target (6,0) too early, no further moves are allowed.
    if (r == N - 1 && c == 0) return;
    
    // ---- Pruning: if the path is forced into a dead-end, return.
    // If moving in both left and right is blocked and
    // moving up and down are both free, then the path is trapped.
    if (( (r == 0) || visited[r - 1][c] ) &&
        ((r == N - 1) || visited[r + 1][c]) &&
        (c > 0 && c < N - 1) &&
        !visited[r][c - 1] && !visited[r][c + 1])
        return;
    // Similarly, if moving left and right are both blocked and
    // moving up and down are free.
    if (( (c == 0) || visited[r][c - 1] ) &&
        ((c == N - 1) || visited[r][c + 1]) &&
        (r > 0 && r < N - 1) &&
        !visited[r - 1][c] && !visited[r + 1][c])
        return;
    
    // Mark the current cell as visited.
    visited[r][c] = true;
    
    // Determine the move direction for this step from the pattern.
    // If pattern[step] is not '?' then we must use that direction.
    if (pattern[step] != '?') {
        // Find which direction corresponds to pattern[step]
        for (int d = 0; d < 4; d++) {
            if (dirC[d] == pattern[step]) {
                int nr = r + dr[d], nc = c + dc[d];
                // Move only if inside the grid and not visited.
                if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                    dfs(nr, nc, step + 1);
                }
                break; // Only one direction to try.
            }
        }
    } else {
        // Try all 4 possible directions.
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                dfs(nr, nc, step + 1);
            }
        }
    }
    
    // Backtrack: unmark the current cell.
    visited[r][c] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the 48-character description.
    cin >> pattern;
    
    // Start from the top-left cell (0,0) and step 0.
    dfs(0, 0, 0);
    
    // Output the number of valid paths.
    cout << ans << "\n";
    
    return 0;
}
