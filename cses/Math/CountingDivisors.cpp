#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;



void solve(){

  int x; cin >> x;
  int ans = 0;
  for(int i = 1; i*i <= x; ++i){
    if(x % i == 0) ans += 2;
    if(i*i == x) ans--;
  }
  cout << ans << '\n';
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