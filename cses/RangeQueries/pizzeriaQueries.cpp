#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

struct SegmentTree {
    int n;
    ll INF = LLONG_MAX / 4;
    vector<ll> t;
    SegmentTree(int _n): n(_n), t(4*n, INF) {}
    ll mg(ll a, ll b){ return a < b ? a : b; }
    void build(int v, int l, int r, const vector<ll>& A){
        if(l == r){
            t[v] = A[l];
        } else {
            int m = (l+r)>>1;
            build(v<<1,   l,   m, A);
            build(v<<1|1, m+1, r, A);
            t[v] = mg(t[v<<1], t[v<<1|1]);
        }
    }
    void update(int v, int l, int r, int pos, ll val){
        if(l == r){
            t[v] = val;
        } else {
            int m = (l+r)>>1;
            if(pos <= m) update(v<<1, l, m, pos, val);
            else          update(v<<1|1, m+1, r, pos, val);
            t[v] = mg(t[v<<1], t[v<<1|1]);
        }
    }
    ll query(int v, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return INF;
        if(ql <= l && r <= qr) return t[v];
        int m = (l+r)>>1;
        return mg(query(v<<1,   l,   m, ql, qr),
                  query(v<<1|1, m+1, r, ql, qr));
    }
    // wrappers
    void build(const vector<ll>& A){ build(1, 0, n-1, A); }
    void update(int pos, ll val){ update(1, 0, n-1, pos, val); }
    ll query(int l, int r){ 
        if(l > r) return INF;
        return query(1, 0, n-1, l, r); 
    }
};

int main(){
    ios();
    int n, q;
    cin >> n >> q;
    vector<ll> p(n);
    rep(i, n) cin >> p[i];
    // build arrays A[i]=p[i]-(i+1), B[i]=p[i]+(i+1)
    vector<ll> A(n), B(n);
    rep(i, n){
        A[i] = p[i] - (i+1);
        B[i] = p[i] + (i+1);
    }
    SegmentTree stA(n), stB(n);
    stA.build(A);
    stB.build(B);
    while(q--){
        int type, k;
        cin >> type >> k;
        if(type == 1){
            ll x;
            cin >> x;
            int i = k-1;
            // update p[i]
            stA.update(i, x - (i+1));
            stB.update(i, x + (i+1));
        } else {
            int i = k-1;
            // min over a: p[a]+|a+1 - k| = min( A[a] + k, B[a] - k )
            ll res = LLONG_MAX;
            ll v1 = stA.query(0, i) + k;
            ll v2 = stB.query(i, n-1) - k;
            res = min(v1, v2);
            cout << res << "\n";
        }
    }
    return 0;
}
