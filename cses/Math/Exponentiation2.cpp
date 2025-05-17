#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
#define int long long
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

int pw(int a, int b, int m){
  if(b == 0) return 1;
  int t = pw(a,b/2,m) %m; t = (1LL * t * t)%m;
  if(b&1){
    t = (1LL * t * a) % m;
  }
  return t;   
}

void solve(){
  int a, b, c; cin >> a >> b >> c;
  int r;
  if(b==0 && c == 0) r = 1;
  else r = pw(b,c,MOD-1);
  cout << pw(a,r,MOD) << '\n';
}


signed main(){
  ios();
  int T = 1;
  cin >> T;
  while (T--){
    solve();
  }
    return 0;
}