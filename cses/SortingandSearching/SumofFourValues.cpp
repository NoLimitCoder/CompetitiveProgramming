#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define int long long
#define rep(i,a,n) for(int i = a; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;



void solve(){
  int n, x; cin >> n >> x;
  //idea: generate all pairs, then run 2 pointers on new vector, check for pairs with equal i and j as they're invalid
  vi A(n); rep(i,0,n) cin >> A[i];
  vector<tuple<int,int,int>>V;
  rep(i,0,n){
    rep(j,i+1,n){
      V.push_back({A[i]+A[j],i,j});
    }
  }
  sort(V.begin(), V.end());
  n = V.size();
  int i = 0, j = n-1;
  while(i<j){
    auto [val_a, i_a, j_a] = V[i]; auto [val_b, i_b, j_b] = V[j];
    if(val_a + val_b > x){ --j;}
    else if(val_a + val_b < x){ ++i;}
    else{
      if(i_a != i_b && i_a != j_b && j_a != i_b && j_a != j_b){
        cout << i_a+1 << ' ' << i_b+1 << ' ' << j_a+1 << ' ' << j_b+1 << '\n';
        return;
      }
      else{
        if(i<n-1 && get<0>(V[i]) == get<0>(V[i+1])) ++i;
        else if(j>0 && get<0>(V[j]) == get<0>(V[j-1])) --j;
        else{++i, --j;}
      }
    }
  }
  cout << "IMPOSSIBLE" << '\n';
}


signed main(){
  ios();
  int T = 1;
  //cin >> T;
  while (T--){
    solve();
  }
    return 0;
}