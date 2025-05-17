#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
vector<ll> A;
const ll INF = 4e18;

ll DP[5005][5005];
ll dp(ll l, ll r){
  //base cases
  if(l == r){ return A[l];}
  if(r-l == 1) return max(A[l], A[r]);
  //memo
  if(DP[l][r] != -INF) return DP[l][r];
  //transitions
    //1 choose First and go to next player
    ll r1 = A[l] + min( dp(l+1+1,r), dp(l+1,r-1) );
    //2 choose Last and go to next player
    ll r2 = A[r] + min( dp(l+1,r-1), dp(l,r-1-1) );
    return DP[l][r] = max(r1,r2);
  }


void solve(){
  int n; cin >> n;
  A.resize(n); rep(i,n) cin >> A[i];
  rep(i,n+1) rep(j, n+1) DP[i][j] = -INF;
  cout << dp(0,n-1);
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