#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    cout << ((1 << n) - 1) << "\n";
    vector<int> pos(n, 0);
    // Rule: If (n - d) is even then move "clockwise" (+1 mod 3),
    //       if odd then move "counterclockwise" (-1 mod 3, which is equivalent to +2 mod 3).
    vector<int> direction(n);
    for (int d = 0; d < n; d++) {
        if ((n - d) % 2 == 0) direction[d] = 1;  // move to (current + 1) mod 3
        else                  direction[d] = 2;  // move to (current + 2) mod 3, i.e., one step counterclockwise
    }
    // Iterate over moves using Gray-code.
    for (int i = 0; i < (1 << n) - 1; i++) {
        int g = i ^ (i >> 1); //cur graycode
        int gNext = (i + 1) ^ ((i + 1) >> 1); //next graycode
        int diff = g ^ gNext; // diff has exactly one bit set – the bit that changes.
        int disk = __builtin_ctz(diff); // Find the index of the changed bit.
        // Record the disk's current peg.
        int from = pos[disk];
        // Compute the new peg for this disk based on its cyclic move direction.
        int to = (from + direction[disk]) % 3;
        // Update the position for the disk.
        pos[disk] = to;
        cout << (from + 1) << " " << (to + 1) << "\n";
    }
    
    return 0;
}
