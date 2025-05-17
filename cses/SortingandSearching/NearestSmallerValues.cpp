#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

struct SegmentTree{
  int df, n; vector<int> t;
  
  int combine(int a, int b){return max(a,b);}

  void build(vector<int> A){ 
    df = INT_MIN; n = A.size(); while(__builtin_popcount(n)!= 1)n++; t.resize(2*n,df);
    for(int v = 0; v<(int)A.size(); ++v)t[n+v] = A[v];
    for(int v = n-1; v>0; --v) t[v] = combine(t[v<<1],t[v<<1|1]);
  }

  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r) { if(val != -1) t[v] = val; return t[v]; }
    int m = (l+r)/2;
    int ans = combine(query(v<<1, l, m, i, j, val), query(v<<1|1, m+1, r, i, j, val));
    if(val != -1) t[v] = combine(t[v<<1], t[v<<1|1]);
    return ans;
  }

  int query(int i, int j, int val = -1){return query(1,0,n-1,i,j,val);}
};

void solve(){

  int n; cin >> n;
  vi A(n);
  rep(i,n){
    cin >> A[i];
  }
  //path compression
  vi B = A;
  sort(B.begin(), B.end());
  unordered_map<int,int> mp;
  int idx = 1;
  rep(i,n){
    if(!mp[B[i]]){mp[B[i]] = idx++;}
    B[i] = mp[B[i]];
  }
  //segment tree
  SegmentTree st; st.build(vector<int>(idx+1));
  rep(i,n){
    cout << st.query(0,mp[A[i]]-1) << ' ';
    st.query(mp[A[i]], mp[A[i]], i+1);
  }
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