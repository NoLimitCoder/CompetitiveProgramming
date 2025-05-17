#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

struct Edge { int u, v; ll w; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    vector<vector<int>> g(n+1), gr(n+1);
    for(int i = 0; i < m; i++){
        int a, b; ll x;
        cin >> a >> b >> x;

        edges.push_back({a, b, -x});
        g[a].push_back(b);
        gr[b].push_back(a);
    }


    vector<char> reach1(n+1, 0), reachN(n+1, 0);
    queue<int> q;
    reach1[1] = 1; q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g[u]) if(!reach1[v]){
            reach1[v] = 1;
            q.push(v);
        }
    }


    reachN[n] = 1; q.push(n);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : gr[u]) if(!reachN[v]){
            reachN[v] = 1;
            q.push(v);
        }
    }

    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    bool neg_cycle = false;
    for(int iter = 1; iter <= n; iter++){
        bool any = false;
        for(auto &e : edges){
            if(!reach1[e.u] || !reachN[e.v]) 
                continue;
            if(dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                any = true;
                if(iter == n)
                    neg_cycle = true;
            }
        }
        if(!any) break;
    }

    if(neg_cycle) {
        cout << -1 << "\n";
    } else {
        cout << -dist[n] << "\n";
    }
    return 0;
}
