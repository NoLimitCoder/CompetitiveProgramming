#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

/*
Idea:

*/

void solve(){
  int a, b; cin >> a >> b;
  cout << ( ((a+b)%3 == 0 && max(a,b) <= 2*(min(a,b)))? "YES\n" : "NO\n");
}


int main(){
  ios();
  int T = 1; 
  cin >> T;
  while (T--){
    solve();
  }
    return 0;
}