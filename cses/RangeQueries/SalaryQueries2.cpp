#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef vector<int> vi;
 
struct SegmentTree{
  int df, n; vector<int> t;
  int combine(int a, int b){return a+b;}
  void build(vector<int> A){ 
    df = 0; n = 1; while(n < (int)A.size()) n<<=1; t.resize(2*n,df);
    for(int v = 0; v < (int)A.size(); ++v)t[n+v] = A[v];
    for(int v = n-1; v>0; --v) t[v] = combine(t[v<<1],t[v<<1|1]);
  }
  int qry(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r) { if(val != -2) t[v] += val; return t[v]; }
    int m = (l+r)/2;
    int ans = combine(qry(v<<1, l, m, i, j, val), qry(v<<1|1, m+1, r, i, j, val));
    if(val != -2) t[v] = combine(t[v<<1], t[v<<1|1]); 
    return ans;
  }
  int qry(int &i, int &j, int val=-2){ return qry(1,0,n-1,i,j,val); }
};
 
struct Q{ char t; int a, b; };
 
int main(){
  ios();
  int n, q; cin >> n >> q;
  vi A(n); vector<int> V;
  for(int i = 0; i<n; ++i){ cin >> A[i]; V.push_back(A[i]);}
  vector<Q> qs;
  while(q--){
    char t; int a, b; cin >> t >> a >> b;
    qs.push_back({t,a,b});
    V.push_back(a); V.push_back(b);
  }

  //path compression
  sort(V.begin(), V.end()); V.resize(unique(V.begin(), V.end()) - V.begin());
  auto mp = [&](int x){ return int(lower_bound(V.begin(), V.end(), x) - V.begin()) + 1; };

  SegmentTree st; st.build(vector<int>(V.size()+1));

  rep(i,n){ A[i] = mp(A[i]); st.qry(A[i],A[i],1); }
  
  rep(i,(int)qs.size()){
    auto &[t, a, b] = qs[i];
    if(t == '!'){
      a--; b = mp(b);
      st.qry(A[a],A[a],-1); A[a] = b;
      st.qry(b,b,1);
    }
    else{
      a = mp(a); b = mp(b);
      cout << st.qry(a,b) << '\n';
    }
  }
  return 0;
}