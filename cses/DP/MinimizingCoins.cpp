#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int INF = 2e9;


void solve(){

  int n, x; cin >> n >> x;
  vi C(n); rep(i,n) cin >> C[i];
  //lets try push dp
  /*vi dp(x+1,INF);
  dp[0] = 0;
  for(int i = 0; i<=x; ++i)
    for(int j : C) if(i+j <= x){
      dp[i+j] = min(dp[i+j], 1+dp[i]);
    }
*/
/*lets try pull dp
  vi dp(x+1,0);
  for(int i = 1; i<=x; ++i){
    int tmp = INF;
    for(int j : C) if(i-j >= 0){
       tmp = min(tmp,dp[i-j]);
    }
    dp[i] = 1 + tmp;
  }

  cout << (dp[x] >= INF? -1 : dp[x]);
*/

  //another way of doing pull
  vi dp(x+1,INF);
  dp[0] = 0;
  for(int i = 0; i<=x; ++i)
    for(int j : C) if(i-j >= 0){
      dp[i] = min(dp[i], 1+dp[i-j]);
    }
  cout << (dp[x] >= INF? -1 : dp[x]);

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