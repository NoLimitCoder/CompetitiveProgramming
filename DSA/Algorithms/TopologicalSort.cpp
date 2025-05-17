#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//CSES Course Schedule: https://cses.fi/problemset/task/1679

//TopoSort
vector<vector<int>> adj;
vector<int> vis, order;        // 0 = unvisited, 1 = visiting, 2 = done
bool has_cycle = false;

  void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v]) 
            dfs(v);
        else if(vis[v] == 1) {has_cycle = 0; return;}
    }
    vis[u] = 2;
    order.push_back(u);
  }

int main() {
    ios();
    int n, m; cin >> n >> m;
    adj.assign(n+1, {}); vis.assign(n+1, 0); order.clear();
    rep(i, m) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) {
            dfs(u);
            if (has_cycle) { cout << "IMPOSSIBLE\n"; return 0; }
        }
    }
    reverse(order.begin(), order.end());
    for (int u : order) { cout << u << ' '; } cout << '\n';
    return 0;
}
