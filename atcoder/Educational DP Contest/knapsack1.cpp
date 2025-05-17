#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;



void solve(){

  int n, w; cin >> n >> w;
  vector<pair<int,int>>A; A.push_back({0,0});
  rep(i,n){ int x,y; cin >> x >> y; A.push_back({x,y});}
  vector<vector<int>>dp(2, vi(w+1));
  for(int i = 1; i<=n; ++i){
    for(int j = 0; j<=w; ++j){
      dp[1][j] = dp[0][j];
      if(j-A[i].first >= 0){
        dp[1][j] = max(dp[1][j], dp[0][j-A[i].first] + A[i].second);
      }
    }
    for(int j = 0; j<=w; ++j) {dp[0][j] = dp[1][j];}
  }
  cout << dp[1][w];
}


signed main(){
  ios();
  int T = 1;
  //cin >> T;
  while (T--){
    solve();
  }
    return 0;
}