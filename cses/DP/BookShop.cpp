#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;



void solve(){

  int n, x; cin >> n >> x;
  vector<int> V(n+1), W(n+1);
  rep(i,n) cin >> W[i];
  rep(i,n) cin >> V[i];
  //state dp[i][j] -> at money j, only using coins up till i, whats the maximum we can have
  //decision 1 take this element V[i]+dp[i-1][j-W[i]]
  //decision 2 not take dp[i-1][j]
  //dp[i][j] = max(V[i]+dp[i-1][j-W[i]] ,dp[i-1][j])
  vector<vector<int>> dp(n+1, vector<int>(x+1,0));

  for(int i = n-1; i>=0; --i){
    for(int j = x; j>=0; --j){
      dp[i][j] = dp[i+1][j];
      if(j-W[i]>=0)
        dp[i][j] = max(dp[i][j], V[i] + dp[i+1][j-W[i]]);
    }
  }
  cout << dp[0][x];

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