#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> VI; typedef vector<VI> VVI;
const int INF = 2e9;
string s1, s2;

int DP[5005][5005];

int dp_recursive(int i, int j){
  //base cases:
  if(i == -1 && j == -1) return 0;
  if(i == -1 && j >= 0)  return j+1;
  if(j == -1 && i >= 0)  return i+1;
  //Memo
  if(DP[i][j] != INF) return DP[i][j];
  //transitions:
    //1 first one is the best because it gives us 0 distance, if we can reach that we should take it
    int r0 = (s1[i] == s2[j])? 0 + dp_recursive(i-1,j-1) : INF;
    //2 remove from 1 / append at 2
    int r1 = 1 + dp_recursive(i-1,j);
    //3 remove from 2 / append at 1
    int r2 = 1 + dp_recursive(i,j-1);
    //4 replace s1[i] with s2[j] / s2[j] with s1[i]
    int r3 = 1 + dp_recursive(i-1,j-1);
    return DP[i][j] = min({r0,r1,r2,r3});
}


int dp_iterative(int n, int m){
  //base cases
  DP[0][0] = 0;
  rep(i,n+1) DP[i][0] = i;
  rep(j,m+1) DP[0][j] = j;
  //Memo
  for(int i = 1; i<=n; ++i)
    for(int j = 1; j<=m; ++j){
      //transitions:
      //1 first one is the best because it gives us 0 distance, if we can reach that we should take it
      int r0 = (s1[i-1] == s2[j-1])? DP[i-1][j-1] : INF;
      //2 remove from 1 / append at 2
      int r1 = 1 + DP[i-1][j];
      //3 remove from 2 / append at 1
      int r2 = 1 + DP[i][j-1];
      //4 replace s1[i] with s2[j] / s2[j] with s1[i]
      int r3 = 1 + DP[i-1][j-1];
      DP[i][j] = min({r0,r1,r2,r3});
    }
    return DP[n][m];
}


void solve(){
   cin >> s1 >> s2;
   int n = s1.size(), m = s2.size();
   
   //recursive:
   //rep(i,n) rep(j,m) DP[i][j] = INF;
   //cout << dp_recursive(n-1,m-1) << '\n';
   
  //iterative: (pad everything by 1 because we can not reference idx = -1)
  rep(i,n+1) rep(j,m+1) DP[i][j] = 0;
  cout << dp_iterative(n,m) << '\n';

}


int main(){
  ios();
  int T = 1;
  //cin >> T;
  while (T--){
    solve();
  }
    return 0;
}