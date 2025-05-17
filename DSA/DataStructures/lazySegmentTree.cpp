#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define int long long
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int INF = 4e18;

struct SegmentTree{
  int df, n; vector<int> t, lz;
  int combine(int a, int b){return a+b;}

  /*void build(vector<int> A){ 
    df = 0; n = 1; while(n < A.size()) n<<=1; t.resize(2*n,df); lz.resize(2*n,0);
    for(int v = 0; v < A.size(); ++v)t[n+v] = A[v];
    for(int v = n-1; v>0; --v) t[v] = combine(t[v<<1],t[v<<1|1]);
  }*/
  
  SegmentTree(vector<int> A){df = 0; n=A.size(); t.resize(4*n,df); lz.resize(4*n,0); build(1,0,n-1,A);}
  void build(int v, int l, int r, vector<int> &A){
    if(l==r) {t[v] = A[l]; return;}
    int m = (l+r)/2; build(v<<1,l,m,A); build(v<<1|1,m+1,r,A);
    t[v] = combine(t[v<<1], t[v<<1|1]);
 }

	void apply(int v, int l, int r, int val){
		if(l != r) lz[v] = val; //change to += for range adding
		t[v] = (r - l + 1) * val; //change to += for range adding 
	}
	
  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r) { if(val != -1) apply(v, l, r, val); return t[v]; } //apply -> update
    int m = (l+r)/2;
    if(lz[v]) { apply(v<<1, l, m, lz[v]); apply(v<<1|1, m+1, r, lz[v]); lz[v] = 0; }
    int ans = combine(query(v<<1, l, m, i, j, val), query(v<<1|1, m+1, r, i, j, val));
    if(val != -1) t[v] = combine(t[v<<1], t[v<<1|1]); //update
    return ans;
  }

  int query(int i, int j, int val=-1){ return query(1,0,n-1,i,j,val); }
};


void solve(){
    int n, q;
    cin >> n >> q;
    vi A(n);
    for(int i = 0; i<n; ++i){
      cin >> A[i];
    }
  SegmentTree st(A);
  //SegmentTree st; st.build(A);
    while(q--){
      int type; cin >> type;
      if(type == 2){
        int i; cin >> i;
        cout << st.query(i-1,i-1,-1) << '\n';
      }
      else{
        int i, j, v; cin >> i >> j >> v;
        st.query(i-1,j-1,v);
      }
    }
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