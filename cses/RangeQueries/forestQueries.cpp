#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    ios();
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
    string line;
    
    // read grid and build prefix sums
    rep(i, n){
        cin >> line;
        for(int j = 0; j < n; ++j){
            int trees = (line[j] == '*');
            // pref is 1-based
            pref[i+1][j+1] = trees 
                + pref[i][j+1] 
                + pref[i+1][j] 
                - pref[i][j];
        }
    }
    
    // answer queries
    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = pref[y2][x2]
                - pref[y1-1][x2]
                - pref[y2][x1-1]
                + pref[y1-1][x1-1];
        cout << ans << '\n';
    }
    
    return 0;
}
