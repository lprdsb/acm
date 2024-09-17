#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q, hs[500100], n, op[500100], x[500100], po[500100];
const int mod = 1000000007;
struct node {
    ll re, s, num;
    bool fl;//it means that re>1000000007
}t[500100 << 2];
struct res {
    ll t, re;
};
#define ls p<<1
#define rs p<<1|1
#define MID int mid=(l+r)>>1;
void up(int p) {
    t[p].num = t[ls].num + t[rs].num;
    t[p].fl = t[ls].fl | t[rs].fl;
    if(t[ls].re >= t[rs].s || t[ls].fl) {
        // cout<<'?';
        t[p].s = t[ls].s;
        t[p].re = t[rs].re + (t[ls].re - t[rs].s) * po[t[rs].num];
    }
    else {
        int tmp = ceil((double)(t[rs].s - t[ls].re) / po[t[ls].num]);
        t[p].s = t[ls].s + tmp;
        tmp = tmp * po[t[ls].num] + t[ls].re;
        t[p].re = t[rs].re + (tmp - t[rs].s) * po[t[rs].num];
    }
    if(t[p].re > mod) {
        // cout<<"kknd "<<t[p].re<<' '<<p<<endl;
        t[p].fl |= 1;
    }
    t[p].re = (t[p].re % mod + mod) % mod;
    // cout<<"不可"<<' '<<p<<' '<<t[p].s<<' '<<t[p].re<<endl;
}
void build(int l, int r, int p) {
    if(l == r) {
        t[p].s = hs[l + 1] - hs[l];
        return;
    }
    MID;
    build(l, mid, ls), build(mid + 1, r, rs);
    up(p);
    // 
}
void chan(int l, int r, int x, int p) {
    if(l == r) {
        t[p].num++;
        if(t[p].num < 30) {
            t[p].s = ceil((double)(hs[l + 1] - hs[l]) / po[t[p].num]);
            t[p].re = t[p].s * (1 << t[p].num) - (hs[l + 1] - hs[l]);
        }
        else {
            t[p].s = 1;t[p].fl = 1;
            t[p].re = po[t[p].num] - (hs[l + 1] - hs[l]);
            t[p].re = (t[p].re % mod + mod) % mod;
        }
        // cout<<l<<' '<<r<<' '<<t[p].s<<' '<<t[p].re<<endl;
        return;
    }
    MID;
    if(x <= mid)chan(l, mid, x, ls);
    else chan(mid + 1, r, x, rs);
    up(p);
    // cout<<l<<' '<<r<<' '<<t[p].s<<' '<<t[p].re<<endl;
}
res pr(int l, int r, ll x, int p) {
    // cout<<l<<' '<<r<<' '<<t[p].s<<' '<<t[p].re<<endl;
    if(x >= t[p].s)return res{ hs[r + 1] - hs[l],(t[p].re + (x - t[p].s) * po[t[p].num] % mod) % mod };
    if(l == r) {
        return res{ x * po[t[p].num] % mod,0 };
    }
    MID;
    res tmp = pr(l, mid, x, ls);
    if(tmp.re == 0) {
        return tmp;
    }
    else {
        res t2 = pr(mid + 1, r, tmp.re, rs);
        return res{ tmp.t + t2.t,t2.re };
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    po[0] = 1;
    for(int i = 1;i <= 500000;i++)po[i] = po[i - 1] * 2ll % mod;
    cin >> q;
    hs[++n] = 0;hs[++n] = 1e9;
    for(int i = 1;i <= q;i++) {
        cin >> op[i] >> x[i];
        hs[++n] = x[i];
    }
    sort(hs + 1, hs + 1 + n);
    n = unique(hs + 1, hs + 1 + n) - hs - 1;
    build(1, n, 1);
    for(int i = 1;i <= q;i++) {
        if(op[i] == 1) {
            chan(1, n, lower_bound(hs + 1, hs + 1 + n, x[i]) - hs, 1);
        }
        else {
            res tmp = pr(1, n, x[i], 1);
            cout << (tmp.t + tmp.re) % mod << endl;
        }
    }
}
/*
4
2 114514
1 5
1 3
2 5
*/