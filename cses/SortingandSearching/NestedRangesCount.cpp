#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct query{int l, r, i;};
 
bool cmp1(query& a, query& b){
  return (a.r == b.r)? (a.l > b.l) : (a.r < b.r);
}
 
bool cmp2(query& a, query& b){
  return (a.l == b.l)? (a.r > b.r) : (a.l < b.l);
}
 
struct SegmentTree{
  int df, n; vector<int> t;
  int mg(int a, int b){return a+b;}
  SegmentTree(vector<int> A){df=0; n=A.size(); t.resize(4*n,df); build(1,0,n-1,A);}
  void build(int v, int l, int r, vector<int> &A){
    if(l==r) {t[v] = A[l]; return;}
    int m = (l+r)/2; build(v<<1,l,m,A); build(v<<1|1,m+1,r,A);
    t[v] = mg(t[v<<1], t[v<<1|1]);
 }
  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i<= l && j>=r){ if(val!=-1) t[v] += val; return t[v];}
    int m = (l+r)/2, ans = mg(query(v<<1,l,m,i,j,val), query(v<<1|1,m+1,r,i,j,val));
    if(val!=-1) t[v] = mg(t[v<<1], t[v<<1|1]);
    return ans;
  } 
  int query(int i, int j, int val=-1){return query(1,0,n-1,i,j,val);}
};
 
 
 
void solve(){
  int n; cin >> n;
  vector<query> V;
  map<int,int> mp;
  rep(i,n) {
    int x, y; cin >> x >> y;
    V.push_back({x,y,i}); mp[x] = 1; mp[y] = 1;
    //debl(i); debl(V[i].l); debl(V[i].r); deb(V[i].i);
  }
  int idx = 1; for(auto it : mp) mp[it.first] = idx++;
  rep(i,n){V[i].l = mp[V[i].l]; V[i].r = mp[V[i].r];}
 
  sort(V.begin(), V.end(),cmp1);
  vector<int> ans(n), A(idx); //sort by earliest r and perform normal query
  SegmentTree st(A);
  rep(i,n){
    //debl(i); debl(V[i].l); debl(V[i].r); deb(V[i].i);
    ans[V[i].i] = st.query(V[i].l, idx);
    st.query(V[i].l, V[i].l, 1);
  }
 
  A.resize(idx,0);
  st.build(1,0,A.size()-1,A);
  sort(V.begin(), V.end(),cmp2);
  vector<int> ans2(n); //sort by earliest l and query from ending until n
  rep(i,n){
    ans2[V[i].i] = st.query(V[i].r, idx);
    st.query(V[i].r, V[i].r, 1);
  }
  rep(i,n){
    cout << ans[i] << ' ';
  } cout << '\n';
  rep(i,n){
    cout << ans2[i] << ' ';
  } cout << '\n';
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