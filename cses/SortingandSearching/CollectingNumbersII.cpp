#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(A) cerr << #A << ": " << A << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
#define rep1(i,n) for(int i = 1; i<=n; ++i)
using namespace std;

const int MAXN = 2e5+5;

int N, M, A[MAXN], pos[MAXN], cnt;

void update(int a, int b){
    if(pos[A[a]-1] <= pos[A[a]] && b <  pos[A[a]-1]) cnt++;
    if(pos[A[a]-1] >  pos[A[a]] && b >= pos[A[a]-1]) cnt--;
    if(pos[A[a]+1] >= pos[A[a]] && b >  pos[A[a]+1]) cnt++;
    if(pos[A[a]+1] <  pos[A[a]] && b <= pos[A[a]+1]) cnt--;
    pos[A[a]] = b;

    if(pos[A[b]-1] <= pos[A[b]] && a <  pos[A[b]-1]) cnt++;
    if(pos[A[b]-1] >  pos[A[b]] && a >= pos[A[b]-1]) cnt--;
    if(pos[A[b]+1] >= pos[A[b]] && a >  pos[A[b]+1]) cnt++;
    if(pos[A[b]+1] <  pos[A[b]] && a <= pos[A[b]+1]) cnt--;
    pos[A[b]] = a;

    swap(A[a], A[b]);
}

void solve(){
    cin >> N >> M; rep1(i,N) { cin >> A[i]; pos[A[i]] = i; }
    int a, b, ptr = 0; pos[N+1] = N+1; cnt = 1;
    rep1(i,N) { if(ptr > pos[i]) {cnt++;} ptr = pos[i]; }
    rep(i,M)  { cin >> a >> b; update(a, b); cout << cnt << '\n'; }
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