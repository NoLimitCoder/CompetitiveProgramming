#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int INF = 2e9;

//recursive
int DP[505][505];
int dp(int a, int b){
//base cases
if(a == b) return 0;
if(a == 1) return b-1;
if(b == 1) return a-1;
//Memo
if(DP[a][b] != INF) return DP[a][b];
//transitions
  int mn = INF;
  for(int i = 1; i<b; ++i){
    int r1 = 1 + dp(a, b-i) + dp(a,i);
    mn = min(mn, r1);
  }
  for(int j = 1; j<a; ++j){
    int r2 = 1 + dp(a-j, b) + dp(j,b);
    mn = min(mn, r2);
  }
  return DP[a][b] = mn;
}


int dp_iterative(int _a, int _b){
  //compute all base cases first
  for(int a = 1; a<=_a; ++a){
    for(int b = 1; b<=_b; ++b){
      //base cases
      if(a == b) {DP[a][b] =   0; continue;}
      if(a == 1) {DP[a][b] = b-1; continue;}
      if(b == 1) {DP[a][b] = a-1; continue;}
      }
    }

  for(int a = 2; a<=_a; ++a){
    for(int b = 2; b<=_b; ++b){
    //we might hit this base case again
    if(a == b) {DP[a][b] = 0; continue;}
    //transitions
      int mn = INF;
      for(int i = 1; i<b; ++i){
        int r1 = 1 + DP[a][b-i] + DP[a][i];
        mn = min(mn, r1);
      }
      for(int j = 1; j<a; ++j){
        int r2 = 1 + DP[a-j][b] + DP[j][b];
        mn = min(mn, r2);
      }
      DP[a][b] = mn;
    }
  }
    return DP[_a][_b];
}


void solve(){
  int a, b; cin >> a >> b;
  rep(i,a+1) rep(j, b+1) DP[i][j] = INF;
  //cout << dp(a,b) << '\n'; //recursive
  cout << dp_iterative(a,b) << '\n'; //iterative
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