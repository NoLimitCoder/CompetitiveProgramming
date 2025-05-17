#include <bits/stdc++.h>
using namespace std;

int G (int &n) {
    return n ^ (n >> 1);
}

int main() {
    int n; cin >> n;
    for(int i = 0; i<(1<<n); ++i){
        bitset<16> b(G(i));
        cout << b.to_string().substr(16 - n) << '\n';
    }
    return 0;
}