#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct DSU{
  int n; vector<int> p, sz;
  DSU(int n): n(n), p(n), sz(n,1){for(int i=0;i<n;++i) p[i]=i;}
  int size(){return n;}
  int get(int x){return p[x]==x? x : p[x] = get(p[x]);}
  bool sameSet(int x, int y){return get(x)==get(y);}
  bool unite(int x, int y){
    x = get(x); y = get(y); if(x==y) return 0;
    if(sz[x] < sz[y]) swap(x,y);
    sz[x] += sz[y]; p[y] = x; --n; return 1;
  }
};



void solve(){
  int n, m; cin >> n >> m;
  DSU dsu(n+1);
  while(m--){
    string query; cin >> query;
    int i, j; cin >> i >> j;
    if(query == "union"){dsu.unite(i,j);}
    else {cout << (dsu.sameSet(i,j)? "YES" : "NO") << '\n';}
    
  }

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