#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

struct SegmentTree {
    struct Node { ll sum, pref; };
    int n;
    vector<Node> t;
    SegmentTree(const vector<ll>& A) {
        n = A.size();
        t.assign(4*n, {0,0});
        build(1,0,n-1,A);
    }
    Node merge(const Node &L, const Node &R){
        Node p;
        p.sum = L.sum + R.sum;
        p.pref = max(L.pref, L.sum + R.pref);
        return p;
    }
    void build(int v,int l,int r,const vector<ll>& A){
        if(l==r){
            t[v].sum = A[l];
            t[v].pref = max(0LL, A[l]);
        } else {
            int m=(l+r)>>1;
            build(v<<1,l,m,A);
            build(v<<1|1,m+1,r,A);
            t[v] = merge(t[v<<1], t[v<<1|1]);
        }
    }
    void update(int v,int l,int r,int pos,ll val){
        if(l==r){
            t[v].sum = val;
            t[v].pref = max(0LL, val);
        } else {
            int m=(l+r)>>1;
            if(pos<=m) update(v<<1, l, m, pos, val);
            else       update(v<<1|1, m+1, r, pos, val);
            t[v] = merge(t[v<<1], t[v<<1|1]);
        }
    }
    Node query(int v,int l,int r,int i,int j){
        if(i>r || j<l) return {0, 0};
        if(i<=l && r<=j) return t[v];
        int m=(l+r)>>1;
        Node L = query(v<<1, l, m, i, j);
        Node R = query(v<<1|1, m+1, r, i, j);
        return merge(L,R);
    }
    void update(int pos,ll val){ update(1,0,n-1,pos,val); }
    ll max_prefix(int l,int r){ return query(1,0,n-1,l,r).pref; }
};

int main(){
    ios();
    int n,q;
    cin>>n>>q;
    vector<ll> A(n);
    rep(i,n) cin>>A[i];
    SegmentTree st(A);
    while(q--){
        int type; cin>>type;
        if(type==1){
            int k; ll u; cin>>k>>u;
            st.update(k-1, u);
        } else {
            int a,b; cin>>a>>b;
            cout<<st.max_prefix(a-1, b-1)<<"\n";
        }
    }
    return 0;
}
