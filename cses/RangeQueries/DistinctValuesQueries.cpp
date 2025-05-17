#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

struct SegmentTree {
    int n, df = 0;
    vector<int> t;
    SegmentTree(int _n): n(_n), t(4*n, df) {}
    int mg(int a, int b){ return a + b; }
    void upd(int v, int l, int r, int pos, int val){
        if(l == r){
            t[v] = val;
        } else {
            int m = (l + r) >> 1;
            if(pos <= m) upd(v<<1, l, m, pos, val);
            else          upd(v<<1|1, m+1, r, pos, val);
            t[v] = mg(t[v<<1], t[v<<1|1]);
        }
    }
    int qry(int v, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return df;
        if(ql <= l && r <= qr) return t[v];
        int m = (l + r) >> 1;
        return mg(qry(v<<1, l, m, ql, qr),
                  qry(v<<1|1, m+1, r, ql, qr));
    }
    void update(int pos, int val){ upd(1, 0, n-1, pos, val); }
    int query(int l, int r){ return qry(1, 0, n-1, l, r); }
};

int main(){
    ios();
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    // compress
    vector<int> vals = A;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    rep(i, n) {
        A[i] = lower_bound(vals.begin(), vals.end(), A[i]) - vals.begin();
    }
    // read queries grouped by right endpoint
    vector<vector<pair<int,int>>> qs(n);
    rep(i, q){
        int l, r;
        cin >> l >> r;
        --l; --r;
        qs[r].emplace_back(l, i);
    }
    vector<int> ans(q);
    SegmentTree st(n);
    vector<int> last(vals.size(), -1);
    // sweep
    rep(i, n){
        int v = A[i];
        if(last[v] != -1){
            st.update(last[v], 0);
        }
        st.update(i, 1);
        last[v] = i;
        for(auto &pr : qs[i]){
            int l = pr.first, idx = pr.second;
            ans[idx] = st.query(l, i);
        }
    }
    // output
    rep(i, q) cout << ans[i] << "\n";
    return 0;
}
