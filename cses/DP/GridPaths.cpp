#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MOD = 1e9 + 7;


void solve(){

  //idea: same stuff just if the value of grid is * don't propagate
  int n; cin >> n;
  vector<vector<char>>grid(n+1, vector<char>(n+1));
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<n; ++j){
      cin >> grid[i][j]; 
    }
  }
  vector<vector<int>>dp(n+1, vector<int>(n+1,0));
  if(grid[0][0] != '*') dp[0][0] = 1;
  for(int i = 0; i<n; ++i)
    for(int j = 0; j<n; ++j){
      //propagate ways down and right
      if(grid[i+1][j] != '*') {dp[i+1][j] += dp[i][j]; dp[i+1][j]%=MOD;}
      if(grid[i][j+1] != '*') {dp[i][j+1] += dp[i][j]; dp[i][j+1]%=MOD;}
      
    }
  cout << dp[n-1][n-1];
}


int main(){
  ios();
  int T = 1;
  //cin >> T;
  while (T--){
    solve();
  }
    return 0;
}