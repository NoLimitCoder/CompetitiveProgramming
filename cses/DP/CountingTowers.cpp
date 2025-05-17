#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MOD = 1e9+7;

int dp(int i, bool ceiling, bool bar){
  if(i == 0 && ceiling == 0) return 0;
  if(i == 0 && bar == 1) return 0;
 // if(i == 0) return 1;
  if(i == 0 && ceiling == 1 && bar == 0) return 1;
  //options: ceiling, bar, no ceiling, no bar
  //ceiling
  int r1 = dp(i-1,1,0);
  int r2 = dp(i-1,1,1);
  int r3 = dp(i-1,0,1);
  int r4 = dp(i-1,0,0);
  return r1+r2+r3+r4;
}


void solve(){

  int n; cin >> n;
  cout << dp(n,1,0) + dp(n,1,1)<< '\n';
}


int main(){
  ios();
  int T = 1;
  cin >> T;
  while (T--){
    solve();
  }
    return 0;
}