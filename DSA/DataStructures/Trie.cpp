#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct vertex{
  char l; bool end; vector<vertex*>child;
  vertex(char c): l(c), end(0) {child.assign(26,NULL);}
};


struct Trie{
  vertex* root;
  Trie(){root = new vertex('l');}
  void insert(){
    
  }
};


void solve(){

  

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