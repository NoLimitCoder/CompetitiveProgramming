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
  string s; cin >> s;
  vector<int> mp(26,0);
  for(char c : s) mp[c-'A']++;
  int odd = 0; char mid = ' ';
  for(int i = 0; i<26; ++i){
    if(mp[i]&1) {odd++; mid = 'A' +i;}
  }
  if(odd > 1) cout << "NO SOLUTION\n";
  else{
    int n = s.size();
    deque<char> dq; 
    if(odd) dq.push_back(mid);
    for(int i = 0; i<26; ++i){
      if(mp[i]==1)continue;
      else{
        while(mp[i]>1){dq.push_back(i+'A'); dq.push_front(i+'A'); mp[i]-=2;}
      }
    }
    for(char c : dq) cout << c;
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