//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2","fma","bmi2")
#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1, 0) {}
    inline void update(int i, int v) {
        for (; i <= n; i += i & -i)
            f[i] += v;
    }
    inline int query(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
    inline int range(int l, int r) const {
        if (l > r) swap(l, r);
        return query(r) - query(l-1);
    }
};

struct Q { char t; int a, b; };

int main(){
    ios();
    int n, q; cin >> n >> q;
    vector<int> A(n); vector<Q> qs(q);

    for(int i = 0; i < n; ++i) {cin >> A[i];}
    for(int i = 0; i < q; ++i) {cin >> qs[i].t >> qs[i].a >> qs[i].b;}

    //fast path compression
    vector<int> V(n + 2*q);
    for(int x : A) V.push_back(x);
    for(auto &qr : qs) { V.push_back(qr.a); V.push_back(qr.b); }

    sort(V.begin(), V.end()); V.resize(unique(V.begin(), V.end()) - V.begin());
    auto mp = [&](int x){ return int(lower_bound(V.begin(), V.end(), x) - V.begin()) + 1; };

    int M = V.size()+2;
    Fenwick fw(M);

    for(int &x : A) { x = mp(x); fw.update(x, +1); }
    for(auto &qr : qs){
        if(qr.t == '!') { qr.b = mp(qr.b); } 
        else { qr.a = mp(qr.a); qr.b = mp(qr.b); }
    }

    for(auto &qr : qs){
        if(qr.t == '!'){
            int pos = qr.a - 1;   
            fw.update(A[pos], -1);
            A[pos] = qr.b;   
            fw.update(A[pos], +1);
        } 
        else { cout << fw.range(qr.a, qr.b) << "\n"; }
    }

    return 0;
}
