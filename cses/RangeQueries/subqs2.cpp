#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

struct SegmentTree {
    struct Node { ll sum, pref, suf, best; };
    int n;
    vector<Node> t;
    SegmentTree(const vector<ll>& A) {
        n = A.size();
        t.resize(4*n);
        build(1, 0, n-1, A);
    }
    Node mg(const Node &L, const Node &R) {
        Node p;
        p.sum  = L.sum + R.sum;
        p.pref = max(L.pref, L.sum + R.pref);
        p.suf  = max(R.suf, R.sum + L.suf);
        p.best = max({L.best, R.best, L.suf + R.pref});
        return p;
    }
    void build(int v, int l, int r, const vector<ll>& A) {
        if (l == r) {
            ll x = A[l];
            t[v] = { x, max(0LL,x), max(0LL,x), max(0LL,x) };
        } else {
            int m = (l + r) >> 1;
            build(v<<1,   l,   m, A);
            build(v<<1|1, m+1, r, A);
            t[v] = mg(t[v<<1], t[v<<1|1]);
        }
    }
    Node query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {0, 0, 0, 0};
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r) >> 1;
        Node L = query(v<<1,   l,   m, ql, qr);
        Node R = query(v<<1|1, m+1, r, ql, qr);
        return mg(L, R);
    }
    ll max_sub(int l, int r) {
        return query(1, 0, n-1, l, r).best;
    }
};

int main(){
    ios();
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    SegmentTree st(A);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << st.max_sub(a-1, b-1) << "\n";
    }
    return 0;
}
