#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll NOSET = LLONG_MAX;

struct SegmentTree {
    int n;
    vector<ll> t, lz_add, lz_set;
    SegmentTree(const vector<ll> &A) {
        n = A.size();
        t.assign(4*n, 0);
        lz_add.assign(4*n, 0);
        lz_set.assign(4*n, NOSET);
        build(1,0,n-1,A);
    }
    void build(int v,int l,int r,const vector<ll> &A){
        if(l==r){
            t[v] = A[l];
        } else {
            int m=(l+r)>>1;
            build(v<<1,  l,   m, A);
            build(v<<1|1,m+1, r, A);
            t[v] = t[v<<1] + t[v<<1|1];
        }
    }
    void apply_set(int v,int l,int r,ll x){
        t[v] = x * (r-l+1);
        lz_set[v] = x;
        lz_add[v] = 0;
    }
    void apply_add(int v,int l,int r,ll x){
        t[v] += x * (r-l+1);
        if(lz_set[v]!=NOSET) lz_set[v] += x;
        else                lz_add[v] += x;
    }
    void push(int v,int l,int r){
        if(l==r) return;
        int m=(l+r)>>1;
        if(lz_set[v]!=NOSET){
            apply_set(v<<1,   l,   m, lz_set[v]);
            apply_set(v<<1|1, m+1, r, lz_set[v]);
            lz_set[v] = NOSET;
        }
        if(lz_add[v]!=0){
            apply_add(v<<1,   l,   m, lz_add[v]);
            apply_add(v<<1|1, m+1, r, lz_add[v]);
            lz_add[v] = 0;
        }
    }
    ll query(int v,int l,int r,int ql,int qr){
        if(ql>r || qr<l) return 0;
        if(ql<=l && r<=qr) return t[v];
        push(v,l,r);
        int m=(l+r)>>1;
        return query(v<<1,  l,   m, ql,qr)
             + query(v<<1|1,m+1, r, ql,qr);
    }
    void update_set(int v,int l,int r,int ql,int qr,ll x){
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr){
            apply_set(v,l,r,x);
            return;
        }
        push(v,l,r);
        int m=(l+r)>>1;
        update_set(v<<1,  l,   m, ql,qr,x);
        update_set(v<<1|1,m+1, r, ql,qr,x);
        t[v] = t[v<<1] + t[v<<1|1];
    }
    void update_add(int v,int l,int r,int ql,int qr,ll x){
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr){
            apply_add(v,l,r,x);
            return;
        }
        push(v,l,r);
        int m=(l+r)>>1;
        update_add(v<<1,  l,   m, ql,qr,x);
        update_add(v<<1|1,m+1, r, ql,qr,x);
        t[v] = t[v<<1] + t[v<<1|1];
    }
    // wrappers
    ll query(int l,int r){ return query(1,0,n-1,l,r); }
    void update_set(int l,int r,ll x){ update_set(1,0,n-1,l,r,x); }
    void update_add(int l,int r,ll x){ update_add(1,0,n-1,l,r,x); }
};

int main(){
    ios();
    int n,q;
    cin >> n >> q;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    SegmentTree st(A);
    while(q--){
        int t; cin >> t;
        int a,b; ll x;
        if(t==1){
            cin >> a >> b >> x;
            st.update_add(a-1,b-1,x);
        } else if(t==2){
            cin >> a >> b >> x;
            st.update_set(a-1,b-1,x);
        } else {
            cin >> a >> b;
            cout << st.query(a-1,b-1) << "\n";
        }
    }
    return 0;
}
