#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds; 
typedef long long ll;
typedef vector<int> vi;


struct query{ int l, r, i; };
 
bool cmp1(query& a, query& b){ return (a.r == b.r)? (a.l > b.l) : (a.r < b.r); }
 
bool cmp2(query& a, query& b){ return (a.l == b.l)? (a.r > b.r) : (a.l < b.l); }

struct ost_ms {
    typedef tree< pair<int, unsigned>, null_type, less<pair<int, unsigned>>, rb_tree_tag, tree_order_statistics_node_update>ost; 
    unsigned cnt = 0; ost s; ost_ms() = default; ost_ms(initializer_list<int> l) {for (int x : l) insert(x); }
    void insert(int x) { s.insert({x, cnt++}); }
    int find_by_order(int k) { return k >= s.size()? -1 : s.find_by_order(k)->first; }
    int order_of_key(int x){ return s.order_of_key({x, 0}); } 
    void erase(int x) { auto it = s.lower_bound({x, 0}); while (it != s.end() && it->first == x) erase(it++); }
    void erase(ost::iterator it) {s.erase(it);} size_t size() const { return s.size(); }
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
  vector<int> ans(n); //sort by earliest r and perform normal query
  ost_ms ost;
  rep(i,n){
    //debl(i); debl(V[i].l); debl(V[i].r); deb(V[i].i);
   // ans[V[i].i] = st.query(V[i].l, idx);
    ans[V[i].i] = ost.order_of_key(V[i].l);
    ost.insert(V[i].l);
    //st.query(V[i].l, V[i].l, 1);
  }
 
  ost_ms ost2;
  sort(V.begin(), V.end(),cmp2);
  vector<int> ans2(n); //sort by earliest l and query from ending until n
  rep(i,n){
   // ans2[V[i].i] = st.query(V[i].r, idx);
   // st.query(V[i].r, V[i].r, 1);
    ans2[V[i].i] = ost2.order_of_key(V[i].r);
    ost2.insert(V[i].r);
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