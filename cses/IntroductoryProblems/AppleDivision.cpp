#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int INF = 4e18;
/*
Idea:

*/
int n;
vector<int> A(20);

int subset_sum(int &mask){
  int sum = 0;
  for(int i = 0; i<20; ++i){
    if(mask & (1<<i)) sum += A[i];
  }
  return sum;
}


void solve(){
  cin >> n;
  int sum = 0;
  int mn = INF;
  rep(i,n) {cin >> A[i]; sum += A[i];}
  for(int mask = 0; mask < (1<<n); ++mask){
    int set1_sum = subset_sum(mask);
    int set2_sum = sum - set1_sum;
    mn = min(mn, abs(set1_sum - set2_sum));
  }
  cout << mn << '\n';
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