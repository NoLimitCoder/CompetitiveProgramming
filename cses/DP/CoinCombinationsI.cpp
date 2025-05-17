#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MOD = 1e9 + 7;


void solve(){

  int n, x; cin >> n >> x;
  vi C(n); rep(i,n) cin >> C[i];
  vi dp(x+1,0);
  dp[0] = 1;
  for(int i = 0; i<=x; ++i)
    for(int j : C) if(i+j <= x){
      dp[i+j] += dp[i]; dp[i+j]%=MOD;
    }
  cout << dp[x];
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