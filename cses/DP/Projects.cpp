#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;


struct project{ ll s, e, w; };

void solve(){
  int n; cin >> n; vector<project> P(n); 
  rep(i,n){ cin >> P[i].s >> P[i].e >> P[i].w; }
  sort(P.begin(), P.end(), [](const project &a, const project &b){
    return (a.e < b.e || (a.e==b.e && a.w < b.w));
  });
  set<pair<ll,ll>>st; st.insert({0,0});
  ll ans = 0;
  for(int i = 0; i<n; ++i){
    auto it = st.lower_bound({P[i].s,-1}); it--; //guaranteed to end before this starts
    ans = max(ans, it->second + P[i].w);
    st.insert({P[i].e, ans});
  }
  cout << ans;
}


int main(){
  ios();
  int T = 1;
  while (T--){
    solve();
  }
    return 0;
}