#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
#define int long long
using namespace std;
 
 bool can(vector<int> & A,int &k, int mid){
  int n = A.size(), cur = 0, tmp = 1;
  rep(i,n){
    if(A[i] > mid) return 0;
    cur += A[i];
    if(cur > mid){tmp++; cur = 0; --i;}
  }
  return tmp <= k;
 }

int BS(vector<int> & A,int &k){
  int lo = 0, hi = 1e18, mid, ans = 0;
  while(lo<=hi){
    mid = lo + (hi-lo)/2;
    if(can(A,k,mid)){hi = mid-1; ans = mid;}
    else{lo = mid+1;}
  }
  return ans;
}


void solve(){
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i,n) cin >> A[i];
  cout << BS(A,k);
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