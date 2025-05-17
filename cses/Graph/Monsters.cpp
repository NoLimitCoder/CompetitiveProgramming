#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using pii = pair<int,int>;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

const int INF = 1e9;
int main(){
    ios();
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];
    queue<pii> q;
    vector<vector<int>> d_mon(n, vector<int>(m, INF));
    int sx=-1, sy=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='M'){
                d_mon[i][j]=0;
                q.emplace(i,j);
            }
            if(g[i][j]=='A'){
                sx=i; sy=j;
            }
        }
    }
    // 1) multi-source BFS from all monsters, record min steps to each cell
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k], ny=y+dy[k];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(g[nx][ny]=='#') continue;
            if(d_mon[nx][ny] > d_mon[x][y]+1){
                d_mon[nx][ny] = d_mon[x][y]+1;
                q.emplace(nx,ny);
            }
        }
    }

    // 2) BFS from A, but only enter cells if hero arrives strictly before any monster
    vector<vector<int>> d_hero(n, vector<int>(m, INF));
    vector<vector<int>> from_dir(n, vector<int>(m,-1));
    q.emplace(sx,sy);
    d_hero[sx][sy] = 0;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        // if on boundary, we can stop
        if(x==0||x==n-1||y==0||y==m-1){
            // reconstruct path
            string path;
            int cx=x, cy=y;
            while(cx!=sx || cy!=sy){
                int d = from_dir[cx][cy];
                // d: 0=D,1=U,2=R,3=L (we stored the move we took to reach cx,cy)
                if(d==0){ path.push_back('D'); cx--; }
                else if(d==1){ path.push_back('U'); cx++; }
                else if(d==2){ path.push_back('R'); cy--; }
                else if(d==3){ path.push_back('L'); cy++; }
            }
            reverse(path.begin(), path.end());
            cout<<"YES\n"<<path.size()<<"\n"<<path<<"\n";
            return 0;
        }
        for(int k=0;k<4;k++){
            int nx=x+dx[k], ny=y+dy[k];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(g[nx][ny]=='#') continue;
            // hero step number would be d_hero[x][y]+1
            if(d_hero[nx][ny] > d_hero[x][y]+1 
               && d_hero[x][y]+1 < d_mon[nx][ny])
            {
                d_hero[nx][ny] = d_hero[x][y]+1;
                from_dir[nx][ny] = k; 
                q.emplace(nx,ny);
            }
        }
    }

    cout<<"NO\n";
    return 0;
}
