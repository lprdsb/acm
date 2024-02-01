#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 300000
int n, m, q;

#define md (l + r >> 1)
#define ls (rt << 1)
#define rs (rt << 1 | 1)
LL sv[4 * maxn + 5], sr[4 * maxn + 5], ss[4 * maxn + 5];
int lprv[4 * maxn + 5], lprr[4 * maxn + 5];
void build(int rt, int l, int r) {
    sv[rt] = sv[rt] = ss[rt] = 0;
    lprv[rt] = lprr[rt] = -1;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void mson(int rt, int l, int r, int vi, int ri) {
    if(vi != -1) sv[rt] = lprv[rt] = vi;
    if(ri != -1) sr[rt] = lprr[rt] = ri;
    ss[rt] = 1ll * (r - l + 1) * sv[rt] * sr[rt] - 1ll * sv[rt] * (l + r) * (r - l + 1) / 2;
}
void spr(int rt, int l, int r) {
    if(lprv[rt] != -1 || lprr[rt] != -1) {
        mson(ls, l, md, lprv[rt], lprr[rt]);
        mson(rs, md + 1, r, lprv[rt], lprr[rt]);
        lprv[rt] = lprr[rt] = -1;
    }
}
void upd(int rt) {
    sv[rt] = sv[ls];
    sr[rt] = sr[ls];
    ss[rt] = ss[ls] + ss[rs];
}
void mdy(int rt, int l, int r, int ql, int qr, int vi, int ri) {
    if(ql <= l && qr >= r) return mson(rt, l, r, vi, ri);
    spr(rt, l, r);
    if(ql <= md) mdy(ls, l, md, ql, qr, vi, ri);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, vi, ri);
    upd(rt);
}
LL que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return ss[rt];
    spr(rt, l, r);
    LL res = 0;
    if(ql <= md) res += que(ls, l, md, ql, qr);
    if(qr > md) res += que(rs, md + 1, r, ql, qr);
    return res;
}

int X[maxn + 5], V[maxn + 5];
set<pair<int, int> > se;
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(q);
    build(1, 2, n);
    For(i, 1, m) read(X[i]);
    For(i, 1, m) read(V[i]);
    For(i, 1, m) se.insert({ X[i], V[i] });
    int pre = 0;
    for(auto [x, v] : se) {
        if(x != n) mdy(1, 2, n, x + 1, n, v, -1);
        if(pre) mdy(1, 2, n, pre + 1, x, -1, x);
        pre = x;
    }
    while(q--) {
        int op; read(op);
        if(op == 1) {
            int x, v; read(x); read(v);
            auto it = se.lower_bound({ x, 0 });
            mdy(1, 2, n, x + 1, it->fir, v, -1);
            it--;
            mdy(1, 2, n, it->fir + 1, x, -1, x);
            se.insert({ x, v });
        }
        else {
            int l, r; read(l); read(r);
            if(r == 1) {
                puts("0");
                continue;
            }
            printf("%lld\n", que(1, 2, n, l, r));
        }
    }
    return 0;
}
