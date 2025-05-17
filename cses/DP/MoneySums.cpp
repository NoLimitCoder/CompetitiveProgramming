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
  set<int> st; st.insert(0);
  for(int i : A){
    vector<int> tmp;
    for(int j : st){
      tmp.push_back(i+j);
    }for(auto it : tmp) st.insert(it); 
  }
  cout << st.size()-1 << '\n';
  for(int i : st){if(i!=0) cout << i << ' ';}
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