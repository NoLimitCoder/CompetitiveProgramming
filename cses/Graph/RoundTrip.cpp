#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> state;     // 0 = unvisited, 1 = visiting, 2 = visited
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

void dfs(int u, int p) {
    state[u] = 1;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;           
        if (state[v] == 0) {
            dfs(v, u);
            if (cycle_start != -1) return; 
        } else if (state[v] == 1) {
            cycle_start = v;
            cycle_end = u;
            return;
        }
    }
    state[u] = 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.assign(n, {});
    state.assign(n, 0);
    parent.assign(n, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (state[i] == 0) {
            dfs(i, -1);
            if (cycle_start != -1) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycle_start + 1);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v + 1);
    }
    cycle.push_back(cycle_start + 1);

    cout << cycle.size() << "\n";
    for (int x : cycle) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
