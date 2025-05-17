#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;



void solve(){

  int n; cin >> n;
  int dp[n+1][3];

  rep(i,n){
    cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    if(i){
      dp[i][0] += max(dp[i-1][1], dp[i-1][2]);
      dp[i][1] += max(dp[i-1][0], dp[i-1][2]);
      dp[i][2] += max(dp[i-1][0], dp[i-1][1]);
    }
  }
  int ans = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
  cout << ans << '\n';
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