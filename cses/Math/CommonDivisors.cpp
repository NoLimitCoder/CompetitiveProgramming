#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;


void solve(){
  int n, mx = 0, ans = 1;
  cin >> n;
  vi A(n,0);     rep(i,n){cin >> A[i]; mx = max(mx,A[i]);} 
  vi st(mx+1,0); rep(i,n) {st[A[i]]++;}
  vi div(mx+1,0); 
  for(int i = 1; i<=mx; ++i){ //O(mx)
    for(int j = i; j<=mx; j+=i){ //this is O(ln(mx)), crazy right
      //O( mx * ln(mx) )
      if(st[j]) {div[i]+=st[j]; if(div[i] > 1) ans = max(ans,i);}
    }
  }
  cout << ans << '\n';
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