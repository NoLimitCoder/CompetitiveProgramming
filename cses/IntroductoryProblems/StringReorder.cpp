#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    stack<char> stk;
    char prev = s[0];
    string ans = ""; ans += s[0];
    for(int i = 1; i<s.size(); ++i){
      //1st check stack
      while(!stk.empty() && stk.top() != prev){
        char c = stk.top(); stk.pop();
        ans += c; prev = c;
      }
      if(s[i] != prev){ans += s[i]; prev = s[i];}
      else{ stk.push(s[i]); }
    }
    while(!stk.empty() && stk.top() != prev){
      char c = stk.top(); stk.pop();
      ans += c; prev = c;
    }
    //if(!stk.empty()) cout << -1;
     cout << ans << '\n';
    return 0;
}