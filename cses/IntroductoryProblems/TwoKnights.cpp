#include <bits/stdc++.h>
#define int long long
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
 int N; cin >> N;
 for(int n = 1; n<=N; ++n)
  cout << (((n*n) * ((n*n)-1))/2) - (4*(n-1)*(n-2)) << '\n';
}


signed main(){
  ios();
  int T = 1;
  while (T--){
    solve();
  }
    return 0;
}