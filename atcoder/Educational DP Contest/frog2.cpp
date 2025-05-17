#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;



void solve(){

  int n, k; cin >> n >> k;
  vi A(n); rep(i,n) cin >> A[i];
  vi dp(n+1, INT_MAX);
  dp[0] = 0;
  rep(i,n){
    for(int j = 1; j<=k; ++j) if(i-j >= 0){
      dp[i] = min(dp[i], dp[i-j] + abs(A[i-j] - A[i]));
    }
  }
  cout << dp[n-1] << '\n';
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