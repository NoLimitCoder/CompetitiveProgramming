#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
using ll = long long;

int main(){
    ios();
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto bfs = [&](int src){
        vector<int> dist(n+1, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        int far = src;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if(dist[v] > dist[far]) far = v;
                }
            }
        }
        return make_pair(far, dist[far]);
    };
    // first BFS from 1 (or any node) to find farthest
    int start = bfs(1).first;
    // second BFS from start to find diameter
    int diameter = bfs(start).second;
    cout << diameter << "\n";
    return 0;
}
