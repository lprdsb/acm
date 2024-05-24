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
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int mn[4 * maxn + 5], lpr[4 * maxn + 5];
void mson(int rt, int x) {
    mn[rt] += x;
    lpr[rt] += x;
}
void spr(int rt) {
    if(lpr[rt]) {
        mson(ls, lpr[rt]);
        mson(rs, lpr[rt]);
        lpr[rt] = 0;
    }
}
void upd(int rt) {
    mn[rt] = min(mn[ls], mn[rs]);
}
void build(int rt, int l, int r) {
    mn[rt] = lpr[rt] = 0;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void mdy(int rt, int l, int r, int ql, int qr, int x) {
    if(ql > qr) return;
    if(ql <= l && qr >= r) return mson(rt, x);
    spr(rt);
    if(ql <= md) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
    upd(rt);
}
int find(int rt, int l, int r, int x) {
    if(mn[rt]) return 0;
    if(l == r) return l;
    spr(rt);
    int res = 0;
    if(x > md) res = find(rs, md + 1, r, x);
    if(!res) res = find(ls, l, md, x);
    return res;
}


int T, n, a[maxn + 5], pre[maxn + 5], ppre[maxn + 5];
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) pre[i] = ppre[i] = 0;
    build(1, 1, n);
    int res = 0;
    For(i, 1, n) {
        mdy(1, 1, n, ppre[a[i]] + 1, pre[a[i]], -1);
        mdy(1, 1, n, pre[a[i]] + 1, i, 1);
        if(find(1, 1, n, i)) {
            res++;
            mdy(1, 1, n, ppre[a[i]] + 1, pre[a[i]], 1);
            mdy(1, 1, n, pre[a[i]] + 1, i, -1);
            mdy(1, 1, n, 1, i, 1);
        }
        else {
            ppre[a[i]] = pre[a[i]];
            pre[a[i]] = i;
        }
    }
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
