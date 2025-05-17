#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int INF = 2e9;


void solve(){

  int n; cin >> n;
  vi dp(n+1,INF);
  dp[n] = 0;
  for(int i = n; i>=0; --i){
    int digits = i;
    while(digits != 0){
      int digit = digits % 10;
      if(i-digit>=0) dp[i-digit] = min(dp[i-digit], 1+dp[i]);
      digits/=10;
    }
  }
  cout << dp[0];
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