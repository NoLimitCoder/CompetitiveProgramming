#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define int long long
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

//RUPQ
struct SegmentTree{
  int df, n; vector<int> t;
  int mg(int a, int b){return a+b;}
  SegmentTree(vector<int> A){df=0; n=A.size(); t.resize(4*n,df); bld(1,0,n-1,A);}
  void bld(int v, int l, int r, vector<int> &A){
    if(l==r) {t[v] = A[l]; return;}
    int m = (l+r)/2; bld(v<<1,l,m,A); bld(v<<1|1,m+1,r,A);
    t[v] = mg(t[v<<1], t[v<<1|1]);
 }
  int qry(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i<= l && j>=r){ if(val!=-1) t[v] = val; return t[v];}
    int m = (l+r)/2, ans = mg(qry(v<<1,l,m,i,j,val), qry(v<<1|1,m+1,r,i,j,val));
    if(val!=-1) t[v] = mg(t[v<<1], t[v<<1|1]);
    return ans;
  } 
  int qry(int i, int j, int val=-1){return qry(1,0,n-1,i,j,val);}
};


void solve(){
    int n, q;
    cin >> n >> q;
    vi A(n);
    for(int i = 0; i<n; ++i){
      cin >> A[i];
    }
  SegmentTree st(A);
    while(q--){
      int type; cin >> type;
      if(type == 2){
        int i, j; cin >> i >> j;
        cout << st.qry(i-1,j-1) << '\n';
      }
      else{
        int i, v; cin >> i >> v;
        st.qry(i-1,i-1,v);
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