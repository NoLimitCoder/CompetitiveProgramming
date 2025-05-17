#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
  string s, p; cin >> s >> p;
  int m = p.size(), n = s.size(), ans = 0; vector<int> LPS(m,0);
  //kmp
  for(int i = 1, j = 0; i<m;) {p[i] == p[j]? LPS[i++] = ++j : j? j = LPS[j-1] : ++i;}
  //search
  for(int i = 0, j = 0; i<n;) {s[i] == p[j]?     i++  , ++j : j? j = LPS[j-1] : ++i;
    if(j == m) {++ans; j = LPS[j-1];}
  }
  cout << ans << '\n';
}


int main(){
  ios();
  int T = 1;
  while (T--){
    solve();
  }
    return 0;
}