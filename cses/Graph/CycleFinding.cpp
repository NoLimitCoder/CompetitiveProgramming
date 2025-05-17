#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge { int u, v; ll w; };

int main(){
    ios();
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    edges.reserve(m);
    rep(i, m){
        int a, b; ll c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    const ll INF = LLONG_MAX / 4;
    vector<ll> dist(n+1, 0);
    vector<int> parent(n+1, -1);
    int x = -1;

    // Bellman–Ford: n iterations
    rep(iter, n){
        x = -1;
        for(auto &e : edges){
            if(dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if(x == -1){
        cout << "NO\n";
    } else {
        // there is a negative cycle; find a vertex on it
        int y = x;
        rep(i, n) y = parent[y];
        // reconstruct cycle
        vector<int> cycle;
        for(int cur = y;; cur = parent[cur]){
            cycle.push_back(cur);
            if(cur == y && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for(int v : cycle) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}
