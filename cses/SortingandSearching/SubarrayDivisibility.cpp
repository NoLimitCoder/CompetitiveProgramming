#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
/*
  Idea: if x-y = 0 (mod k), then the subarray at (arg(x) + 1, arg(y)] is divisible under mod k

  why tho?

  let x = a (mod k)
  let y = a (mod k)

  where y = x + z (z is the number of elements between (x, y] since these are subarrays)

  notice that since y = x + z,

  then x = x + z => z = 0

  therefore the subarray at (arg(x), arg(y)] must be divisible under mod k

  special case:
  if x = 0 (mod k), then subarray x is valid, but so is subarray x-y + z (mod k), 
  thus if the current x = 0, we must add 1 to the answer
*/

int ans = 0, k; cin >> k;
vi A(k), P(k); unordered_map<int,int> mp;
rep(i,k){
  //formatting input
  cin >> A[i];
  if(A[i] < 0) {A[i] += ((abs(A[i]) / k) + 1)*k;} A[i] %= k;
  P[i] += A[i];       if(i) P[i] += P[i-1];       P[i] %= k;
  //driver code
  if(P[i] == 0) ans++;
  ans += mp[P[i]]++;
}
cout << ans << '\n';
}


signed main(){
  ios();
  int T = 1;
  //cin >> T;
  while (T--){
    solve();
  }
    return 0;
}