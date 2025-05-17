#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s; cin >> s;
    // Sort the string to start with the lexicographically smallest permutation.
    sort(s.begin(), s.end());
    vector<string> permutations;
    do {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << permutations.size() << "\n";
    for (auto &perm : permutations) { cout << perm << "\n"; }
    return 0;
}