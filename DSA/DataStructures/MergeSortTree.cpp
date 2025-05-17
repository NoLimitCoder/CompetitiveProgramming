#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;


struct MergeSortTree{
  int df, n; vector<vector<int>> t;
  
  void merge(vector<int>&c, vector<int> &a, vector<int> &b){
    int i = 0, j = 0;
    while(i<a.size() && j < b.size()) {c.push_back(a[i] < b[j]? a[i++] : b[j++]);}
    while(i<a.size()) c.push_back(a[i++]); while(j<b.size()) c.push_back(b[j++]);
  }
  
  MergeSortTree(){} 
  MergeSortTree(vector<int> A) {df = 0; n = A.size(); t.resize(4*n); build(1,0,n-1,A); }

  void build(int v, int l, int r, vector<int> &A){
    if(l == r) {t[v] = {A[l]}; return;}
    int m = (l+r)/2; build(v<<1,l,m,A); build(v<<1|1,m+1,r,A);
    merge(t[v], t[v<<1], t[v<<1|1]);
  }

  int query(int v, int l, int r, int i, int j, int k){
    if(i > r || j < l) return df;
    if(i<=l && j>=r){
      int pos = lower_bound(t[v].begin(), t[v].end(), k) - t[v].begin(); // <k
    //int pos = t[v].size() - (upper_bound(t[v].begin(), t[v].end(), k) - t[v].begin()); // >k
      return pos;
    }
    int m = (l+r)/2;
    return query(v<<1,l,m,i,j,k) + query(v<<1|1,m+1,r,i,j,k);
  }

  int query(int i, int j, int k){return query(1,0,n-1,i,j,k);}
};



void solve(){
MergeSortTree mst;
mst = MergeSortTree({4,8,3,4,5,6,7,8,9});
cout << mst.query(0,5,4);

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