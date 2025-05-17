#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> children;
vector<int> sub;

int dfs(int u){
    int sz = 1;
    for(int v : children[u]){
        sz += dfs(v);
    }
    sub[u] = sz - 1;
    return sz;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    children.assign(n+1, {});
    sub.assign(n+1, 0);

    for(int v = 2; v <= n; ++v){
        int p; 
        cin >> p;
        children[p].push_back(v);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i){
        cout << sub[i] << (i < n ? ' ' : '\n');
    }
    return 0;
}
