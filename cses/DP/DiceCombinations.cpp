#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

void solve(){

  int n; cin >> n;
  vi dp(n+10,0);
  dp[0] = 1;
  for(int i = 1; i<=n; ++i)
    for(int j = 1; j<=6; ++j) if(i-j >=0){
      dp[i] += dp[i-j]; dp[i]%=MOD;
    }
  cout << dp[n];
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