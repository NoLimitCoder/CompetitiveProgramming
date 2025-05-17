#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

struct SegmentTree {
    struct Node { ll sum, pref, suf, best; };
    int n; vector<Node> t;
    SegmentTree(const vector<ll>& A) {
        n = A.size();
        t.assign(4*n, {0,0,0,0});
        build(1,0,n-1,A);
    }
    Node mg(const Node &L, const Node &R) {
        Node p;
        p.sum  = L.sum + R.sum;
        p.pref = max(L.pref, L.sum + R.pref);
        p.suf  = max(R.suf, R.sum + L.suf);
        p.best = max({L.best, R.best, L.suf + R.pref});
        return p;
    }
    void build(int v,int l,int r,const vector<ll>& A){
        if(l==r){
            ll x = A[l];
            t[v] = {x, max(0LL,x), max(0LL,x), max(0LL,x)};
        } else {
            int m=(l+r)>>1;
            build(v<<1,l,m,A);
            build(v<<1|1,m+1,r,A);
            t[v] = mg(t[v<<1], t[v<<1|1]);
        }
    }
    void upd(int v,int l,int r,int pos,ll val){
        if(l==r){
            t[v] = {val, max(0LL,val), max(0LL,val), max(0LL,val)};
        } else {
            int m=(l+r)>>1;
            if(pos<=m) upd(v<<1, l, m, pos, val);
            else       upd(v<<1|1, m+1, r, pos, val);
            t[v] = mg(t[v<<1], t[v<<1|1]);
        }
    }
    void update(int pos,ll val){ upd(1,0,n-1,pos,val); }
    ll query_all(){ return t[1].best; }
};

int main(){
    ios();
    int n,m; cin>>n>>m;
    vector<ll> A(n);
    rep(i,n) cin>>A[i];
    SegmentTree st(A);
    while(m--){
        int k; ll x;
        cin>>k>>x;
        st.update(k-1, x);
        cout<<st.query_all()<<"\n";
    }
    return 0;
}
