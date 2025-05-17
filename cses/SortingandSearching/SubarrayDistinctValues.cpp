#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i<n; ++i)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define int long long
using namespace std;


signed main(){
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i,n) cin >> A[i];
  map<int,int> mp;
  int cnt = 0;
  //sliding window
  int r = 0, ans  = 0, i = 0, j = 0;
  for(int j = 0; j<n; ++j){
    if(mp[A[j]] == 0) cnt++;
    mp[A[j]]++;
    while(i < j && cnt > k){
      mp[A[i]]--;
      if(mp[A[i]] == 0) cnt--;
      ans += (j-i);
      ++i;
    }
    if(mp[A[i]] == 0) cnt--;
  }
  while(i < n){
    if(cnt <= k){
      ans += (n-i);
      if(mp[A[i]] == 0) cnt--;
      ++i;
    }
  }
  cout << ans << '\n';
  return 0;
}