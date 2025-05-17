#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int n, x;
vector<pair<int,int>> dp;
vector<int> A;

//dp[mask] = min_rides,min_cost to take these people 

void solve(){
  cin >> n >> x;
  dp.resize(1<<n,{n+1,x+1}); dp[0] = {0,0};
  A.resize(n); rep(i,n) cin >> A[i];
  for(int mask = 0; mask<(1<<n); ++mask){
    //idea: to make the current mask (have these elements), what is the right order? -> which element should get placed last
    for(int i = 0; i<n; ++i) if(mask & (1<<i)){
      int tmp_mask = mask ^ (1<<i); //choosing i to be the element we are placing last
      pair<int,int> cost = dp[tmp_mask]; //min_cost for mask of size k-1 with the remaning elements after we fixate i to be the last one now
      //try to add i to the min_cost found for the remaining k-1 elements ( F(x) )
      if(cost.second + A[i] > x) {cost.first++; cost.second = A[i];}
      else cost.second += A[i];
      dp[mask] = min(dp[mask], cost);
    }
  }
  cout << dp[(1<<n)-1].first + (dp[(1<<n)-1].second != 0);


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