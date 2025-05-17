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
we can break this two sets by analyzing how many pairs of adjacent numbers we can make, each pair will have an imbalance of +1 or -1 to the sum of both sets
since we will send the bigger element to the opposite set at every iteration. if there is an even number of sets then it is always valid otherwise it is always invalid
Ex: Valid:    n = 7  =>     1|2 3|4 5|6 7      net imbalance = +1 -1 +1 -1    = 0
              n = 8  =>   1 2|3 4|5 6|7 8      net imbalance = +1 -1 +1 -1    = 0
Ex: Invalid:  n = 9  =>     1|2 3|4 5|6 7|8 9  net imbalance = +1 -1 +1 -1 +1 = 1
              n = 10 =>   1 2|3 4|5 6|7 8|9 10 net imbalance = +1 -1 +1 -1 +1 = 1
Some idea that came to my head and somehow worked was that the number of | separators and by extension the number of pairs can be found by simply doing (n-1)/2
Still don't know why it works
*/

void solve(){
  int n; cin >> n; vector<int> l,r;
  if(((n-1)/2)&1){
    cout << "YES\n";
    bool flag = 1;
    for(int i = n; i>0; i-=2){
      if(flag) {if(i-1) r.push_back(i-1); l.push_back(i);} 
      else     {if(i-1) l.push_back(i-1); r.push_back(i);} 
      flag = !flag;
    }
    cout << l.size() << '\n';
    for(int i : l) {cout << i << ' ';} 
    cout << '\n' << r.size() << '\n';
    for(int i : r) {cout << i << ' ';}
  }
  else {
    cout << "NO\n";
  }
}


int main(){
  ios();
  int T = 1;
  while (T--){
    solve();
  }
    return 0;
}