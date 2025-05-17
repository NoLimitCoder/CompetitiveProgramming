#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vector<vector<int>> AL;
vector<int>color;
bool flag;

void dfs(int u, int col){
  if(color[u] != 0){
    if (color[u] != col) {flag = 1;} 
    return;
  }
  color[u] = col;
  for(int v : AL[u]){
    dfs(v, (col == 1? 2 : 1) );
  }
}
 


int main(){
  int n, m; cin >> n >> m;
  AL = vector<vector<int>>(n);
  color = vector<int>(n,0);
  flag = 0;
  rep(i,m){
    int u,v; cin >> u >> v; --u; --v;
    AL[u].push_back(v); AL[v].push_back(u);
  }
  for(int i = 0; i<n; ++i){
    if(color[i] == 0) dfs(i,1);
  }
  if(flag) cout << "IMPOSSIBLE\n";
  else{
    rep(i,n) cout << color[i] << ' '; cout << '\n';
  }
  return 0;
}