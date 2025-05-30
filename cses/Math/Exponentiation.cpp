#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

int pw(int a, int b){
  if(b == 0) return 1;
  int t = pw(a,b/2) %MOD; t = (1LL * t * t)%MOD;
  if(b&1){
    t = (1LL * t * a) % MOD;
  }
  return t;
  
    
}

void solve(){

  int a, b; cin >> a >> b;
  cout << pw(a,b) << '\n'; 
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