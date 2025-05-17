#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;

void rebalance(multiset<int>& l, multiset<int>& r) {
    while (l.size() > r.size()+1) { r.insert(*prev(l.end())); l.erase(prev(l.end())); }
    while (r.size() > l.size()  ) { l.insert(*r.begin())    ; r.erase(r.begin())    ; }
}

int main(){
  int n, k; cin >> n >> k;
  vector<int> ans, A(n); rep(i,n) cin >> A[i];
  multiset<int> l, r; 
  rep(i,k){l.insert(A[i]);}
  rebalance(l,r);
  if(k&1) {ans.push_back(*prev(l.end()));}
  else    {ans.push_back(min(*prev(l.end()),*r.begin()));}
  // Slide the window
  for (int i = k; i < n; ++i) {
      // Add the new element
      if (A[i] <= *prev(l.end())) { l.insert(A[i]); } 
      else { r.insert(A[i]); }
      // Remove the outgoing element
      if (A[i - k] <= *prev(l.end())) { l.erase(l.find(A[i - k])); }
      else { r.erase(r.find(A[i - k])); }
      // Rebalance the heaps
      rebalance(l, r);
      if(k&1) {ans.push_back(*prev(l.end()));}
      else    {ans.push_back(min(*prev(l.end()),*r.begin()));}
  }
  for(int i : ans) cout << i << ' ';
  return 0;
}