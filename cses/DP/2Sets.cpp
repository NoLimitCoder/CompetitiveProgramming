#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 1; i<=n; ++i)
#define rep1(i,n) for(int i = 0; i<=n; ++i)
#define int long long
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MOD = 1e9+7, MAXN = 501, MAXSUM = 65000;

int DP[MAXN][MAXSUM];

int mod_inv(int a, int m) {
    int m0 = m, y = 0, x = 1;
    while (a > 1) {
        int q = a / m, t = m;
        m = a % m, a = t, t = y;
        y = x - q * y, x = t;
    }
    return (x + m0) % m0;
}

void solve(){
  int n; cin >> n;
  int sum = (n*(n+1))/2;
  if(sum&1) {cout << 0 << '\n'; return;} sum /= 2;
  
  rep1(i,n) DP[i][0] = 1;
  
  rep(i,n){
    rep(j,sum){
      DP[i][j] = DP[i-1][j] + DP[i-1][j-i];
      DP[i][j] %= MOD;
    }
  }
  cout << (DP[n][sum] * mod_inv(2, MOD)) % MOD << '\n';
  deb(mod_inv(2, MOD));
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