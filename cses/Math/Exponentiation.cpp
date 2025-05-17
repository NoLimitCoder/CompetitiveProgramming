#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

int pw(int a, int b, int m){
  if(b == 0) return 1;
  int t = pw(a,b/2, m); t = (1LL * t * t) % m;
  return ( b&1? (1LL * a * t) % m : t);
}

void solve(){

  int a, b; cin >> a >> b;
  cout << pw(a,b, MOD) << '\n'; 
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