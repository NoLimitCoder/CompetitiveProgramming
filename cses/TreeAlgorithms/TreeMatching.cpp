#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n+1, 0), order;
    order.reserve(n);
    parent[1] = -1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        order.push_back(u);
        for(int v : adj[u]){
            if(parent[v] == 0){
                parent[v] = u;
                q.push(v);
            }
        }
    }
    // dp0[u]: max matching in subtree rooted at u when u is free
    // dp1[u]: max matching if u is matched to parent (so can't match children)
    vector<int> dp0(n+1, 0), dp1(n+1, 0);
    for(int idx = n-1; idx >= 0; --idx){
        int u = order[idx];
        ll sum0 = 0;
        // gather children's dp
        for(int v : adj[u]){
            if(parent[v] == u){
                sum0 += dp0[v];
                dp1[u] += dp0[v];
            }
        }
        ll best_delta = 0;
        for(int v : adj[u]){
            if(parent[v] == u){
                ll delta = 1 + (ll)dp1[v] - dp0[v];
                if(delta > best_delta) best_delta = delta;
            }
        }
        dp0[u] = sum0 + best_delta;
    }

    cout << dp0[1] << "\n";
    return 0;
}
