#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;



void solve(){

  int n; cin >> n;
  vi A(n); rep(i,n) cin >> A[i];
  unordered_set<int> st;
  st.insert(0);
  int ans = 1;
  rep(i,n){
    if(st.find(A[i] -1) == st.end()) ++ans;
    st.insert(A[i]);
  }
  cout << ans << '\n';
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