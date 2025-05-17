#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
#define ll long long
using namespace std;


void rebalance(multiset<ll>& l, multiset<ll>& r, ll &l_sum, ll &r_sum) {
    while (l.size() > r.size()+1) { 
      r_sum += *prev(l.end()); r.insert(*prev(l.end()));
      l_sum -= *prev(l.end()); l.erase(prev(l.end())); 
    }
    while (r.size() > l.size()  ) { 
      l_sum += *r.begin(); l.insert(*r.begin()); 
      r_sum -= *r.begin(); r.erase(r.begin()); 
    }
}

void compute_cost(multiset<ll>& l, multiset<ll>& r, ll &l_sum, ll &r_sum, vector<ll> &ans, ll &k){
  if(k&1) {
    ll median = *prev(l.end());
    ans.push_back( ((median*l.size()) - l_sum) + (r_sum - (median*r.size())) );
  }
  else {
    ll median1 = *prev(l.end()), median2 = *r.begin();
    ans.push_back(min(
      ((median1*l.size()) - l_sum) + (r_sum - (median1*r.size())),
      ((median2*l.size()) - l_sum) + (r_sum - (median2*r.size())) 
    ));
  }
}

int main(){
  ll n, k; cin >> n >> k;
  vector<ll> ans, A(n); rep(i,n) cin >> A[i];
  multiset<ll> l, r;
  ll l_sum = 0, r_sum = 0;
  rep(i,k){l.insert(A[i]); l_sum += A[i];}
  rebalance(l, r, l_sum, r_sum);   compute_cost(l,r,l_sum,r_sum,ans,k);
  for (int i = k; i < n; ++i) {
    // Add the new element
    if (A[i]     <= *prev(l.end())) { l.insert(A[i]); l_sum += A[i];} 
    else                            { r.insert(A[i]); r_sum += A[i];}
    // Remove the old element
    if (A[i - k] <= *prev(l.end())) { l.erase(l.find(A[i - k])); l_sum -= A[i-k];}
    else                            { r.erase(r.find(A[i - k])); r_sum -= A[i-k];}
    // Rebalance the heaps
    rebalance(l, r, l_sum, r_sum); compute_cost(l,r,l_sum,r_sum,ans,k);
  }
  for(ll i : ans) cout << i << ' ';
  return 0;
}