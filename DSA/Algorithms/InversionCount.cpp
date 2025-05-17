#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct SegmentTree{
  ll df, n; vector<ll> t;
  ll combine(ll a, ll b){return a+b;}
  void build(vector<ll> A){ 
    df = 0; n = A.size(); while(__builtin_popcount(n)!= 1)n++; t.resize(2*n,df);
    for(int v = 0; v<(int)A.size(); ++v)t[n+v] = A[v];
    for(int v = n-1; v>0; --v) t[v] = combine(t[v<<1],t[v<<1|1]);
  }
  int query(int v, int l, int r, int i, int j, ll val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r) { if(val != -1) t[v] = val; return t[v]; }
    int m = (l+r)/2;
    int ans = combine(query(v<<1, l, m, i, j, val), query(v<<1|1, m+1, r, i, j, val));
    if(val != -1) t[v] = combine(t[v<<1], t[v<<1|1]);
    return ans;
  }
  int query(int i, int j, int val = -1){ return query(1,0,n-1,i,j,val); }
};


ll invCount(vector<ll> A){
    int n = A.size();
    unordered_map<ll,int> mp; rep(i,n){ mp[A[i]] = i; }
    sort(A.begin(), A.end());
    vector<ll> B(n); rep(i,n){ B[i] = mp[A[i]]; }
    SegmentTree st; st.build(vector<ll>(n));
    rep(i,n){ mp[B[i]] = i; }
    ll invCount = 0;
    rep(i,n){
        invCount += st.query(B[i],n-1);
        st.query(B[i],B[i],1);
    }
    return invCount;
}


void solve(){
    int n; cin >> n;
    vector<ll> A(n); rep(i,n) cin >> A[i];
    ll a = invCount(A);
    cout << invCount(A);
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