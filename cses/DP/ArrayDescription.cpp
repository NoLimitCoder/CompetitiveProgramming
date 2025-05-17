#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI; typedef vector<VI> VVI;
#define rep(i,n) for(int i = 0; i<n; ++i)
const int MOD = 1e9 + 7;
int main()
{
    int n, m; cin >> n >> m;
    VI A(n); rep(i,n) cin >> A[i];
    VVI DP(n+1, VI(m+1,0));
    if(A[0] == 0)
        { rep(i,m) DP[0][i+1] = 1; }
    else 
        { DP[0][A[0]] = 1; }
    
    for(int i = 0; i<n; ++i){
        if(A[i+1] != 0){
            //push 3 items
           int j = A[i+1];
           if(j+1 <= m) {DP[i+1][j] += DP[i][j+1];} DP[i+1][j]%=MOD;
           if(    j   ) {DP[i+1][j] += DP[i][ j ];} DP[i+1][j]%=MOD;
           if(j-1 >= 1) {DP[i+1][j] += DP[i][j-1];} DP[i+1][j]%=MOD;
        }
        else{
            for(int j = 1; j<=m; ++j){
                if(DP[i][j] != 0){
                    if(j+1 <= m) {DP[i+1][j+1] += DP[i][j]; DP[i+1][j+1]%=MOD;}
                    if(    j   ) {DP[i+1][j  ] += DP[i][j]; DP[i+1][ j ]%=MOD;}
                    if(j-1 >= 1) {DP[i+1][j-1] += DP[i][j]; DP[i+1][j-1]%=MOD;}
                }
            }
        }
    }
    int ans = 0;
    for(int j = 1; j<=m; ++j){
        ans += DP[n-1][j]; ans %=MOD;
    }
    cout << ans << '\n';
    return 0;
}