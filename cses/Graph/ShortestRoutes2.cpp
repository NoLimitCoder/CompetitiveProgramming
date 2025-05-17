#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main(){
    ios();
    int n, m, q;
    cin >> n >> m >> q;
    // dist[i][j] = shortest distance from i to j (dp lol)
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i,n) dist[i][i] = 0;
    rep(i, m){
        int a, b; ll c;
        cin >> a >> b >> c;
        --a; --b;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    // Floyd–Warshall
    rep(k,n) rep(i,n) rep(j,n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    // queries
    rep(i, q){
        int u, v;
        cin >> u >> v;
        --u; --v;
        ll d = dist[u][v];
        cout << (d >= INF ? -1 : d) << '\n';
    }
    return 0;
}
