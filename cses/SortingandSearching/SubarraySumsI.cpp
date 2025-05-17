#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define int long long
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
  int n, x; cin >> n >> x;
  vi A(n); map<int,int> mp; mp[0]++; int ans = 0, p = 0;
  rep(i,n){ 
    cin >> A[i]; p += A[i];
    ans += mp[p - x];
    mp[p]++;
  }
  cout << ans << '\n';
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