#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
using namespace __gnu_pbds;


struct ost_ms {
    typedef tree< pair<int, unsigned>, null_type, less<pair<int, unsigned>>, rb_tree_tag, tree_order_statistics_node_update>ost; 
    unsigned idx = 0; ost s; ost_ms() = default; ost_ms(initializer_list<int> l) {for (int x : l) insert(x); }
    void insert(int x) { s.insert({x, idx++}); }
    int find_by_order(int k) { return k >= s.size()? -1 : s.find_by_order(k)->first; }
    pair<int,unsigned> find_by_order_p(int k) { return {s.find_by_order(k)->first,s.find_by_order(k)->second};}
    int order_of_key(int x){ return s.order_of_key({x, 0}); }
    void erase(int x) { auto it = s.lower_bound({x, 0}); while (it != s.end() && it->first == x) erase(it++); }
    void erase(ost::iterator it) {s.erase(it);} 
    size_t size() const { return s.size(); }
};

int main(){
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i,n) cin >> A[i];
  ost_ms ost;
  long long sum = 0;
  int i = -1, j = 0; for(; j<k-1; ++j) {ost.insert(A[j]); sum += A[j];}

  for(; j<n; ++j, ++i){
    if(i>=0) {sum -= A[i]; ost.erase(A[i]);}
    sum += A[j]; ost.insert(A[j]);
    int m = ost.find_by_order(k/2), idx = ost.find_by_order_p(k/2).second;
    long long sum = 0, tmp = m*(k/2 -1);
    sum += tmp - st.query(i, idx-1);
    sum += st.query(idx+1, j-1) - tmp;
    cout << sum << ' ';
    debl(i); debl(idx); deb(j-1);
  }
  return 0;
}