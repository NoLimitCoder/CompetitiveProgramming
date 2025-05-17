#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;
vll primes;
void sieve(ll upperbound) {
  _sieve_size = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i);
  }
}


bool isPrime(ll N) {
  if (N < _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size() && primes[i]*primes[i] <= N; ++i)
    if (N%primes[i] == 0) return 0;
  return 1;
}


void solve(){
  int n = 100;
  for(int i = 0; i<n; ++i){
    cout << primes[i] << " \n"[i == n - 1];
  }
}


int main(){
  ios();
  int T = 1;
  sieve(10000000); //up to 10^14 prime checks
  //cin >> T;
  while (T--){
    solve();
  }
    return 0;
}