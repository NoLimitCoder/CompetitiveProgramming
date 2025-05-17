#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int INF = 2e9;

struct SegmentTree{
  int df, n; vector<int> t;
  int combine(int a, int b){return max(a,b);}
  void build(vector<int> A){
    df = -INF; n = A.size(); while(__builtin_popcount(n) != 1)++n; t.resize(2*n);
    for(int i = 0; i<(int)A.size(); ++i){t[n+i] = A[i];}
    for(int v = n-1; v>0; --v)t[v] = combine(t[v<<1],t[v<<1|1]);
  }
  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i<=l && j >= r){if(val!=-1) t[v] = val; return t[v];}
    int m = (l+r)/2;
    int ans = combine(query(v<<1,l,m,i,j,val), query(v<<1|1,m+1,r,i,j,val));
    t[v] = combine(t[v<<1],t[v<<1|1]);
    return ans;
  }
  int query(int i, int j, int val=-1){return query(1,0,n-1,i,j,val);}
};



void solve(){
  int n; cin >> n;
  //Coordinate Compression
  vector<int> A(n); set<int> st; map<int,int> mp; 
  rep(i,n) {cin >> A[i]; st.insert(A[i]);}
  int idx = 1; for(auto it : st) { mp[it] = idx++; }
  rep(i,n) { A[i] = mp[A[i]];}
  //DP
  SegmentTree DP; DP.build(vector<int>(n,0));
  DP.query(A[0],A[0],1); //base case DP[0] = 1
  int max_len = 0;
  for(int i = 0; i<n; ++i){
    int max_len_in_range = DP.query(0,A[i]-1);  // max length from valid indicies from here back
    DP.query(A[i],A[i], max_len_in_range+1);    // update length at this idx with max achievable length + 1 (1 -> this element)
    max_len = max(max_len, max_len_in_range+1); // update max length we've seen so far
  }
  cout << max_len << '\n';
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