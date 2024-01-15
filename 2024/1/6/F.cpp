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

#define maxn 500000
int n, q;
LL a[maxn + 5], b[maxn + 5], c[maxn + 5];

LL mx[4 * maxn + 5], lpr[4 * maxn + 5];
#define ls rt << 1
#define rs (rt << 1 | 1)
#define md (l + r >> 1)

void build(int rt, int l, int r) {
    mx[rt] = lpr[rt] = 0;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void mson(int rt, LL x) {
    lpr[rt] += x;
    mx[rt] += x;
}
void spr(int rt) {
    if(lpr[rt]) mson(ls, lpr[rt]), mson(rs, lpr[rt]);
    lpr[rt] = 0;
}
void upd(int rt) { mx[rt] = max(mx[ls], mx[rs]); }
void mdy(int rt, int l, int r, int ql, int qr, LL x) {
    if(ql <= l && qr >= r) return mson(rt, x);
    spr(rt);
    if(ql <= l) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
    upd(rt);
}
LL que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return mx[rt];
    spr(rt);
    LL res = 0;
    if(ql <= md) res = max(res, que(ls, l, md, ql, qr));
    if(qr > md) res = max(res, que(rs, md + 1, r, ql, qr));
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n - 1) read(c[i]);
    build(1, 1, n + 1);
    LL res = 0;
    For(i, 1, n) mdy(1, 1, n + 1, 1, i, a[i] - b[i]), res += a[i];
    while(q--) {
        int p, x, y, z; read(p); read(x); read(y); read(z);
        res -= a[p];
        mdy(1, 1, n + 1, 1, p, -a[p] + b[p]);
        a[p] = x; b[p] = y;
        res += a[p];
        mdy(1, 1, n + 1, 1, p, a[p] - b[p]);
        printf("%lld\n", res - que(1, 1, n + 1, 1, n + 1));
    }
    return 0;
}
