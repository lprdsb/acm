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
int n, q, a[maxn + 5], b[maxn + 5];
LL c[maxn + 5];

LL f[4 * maxn + 5][3], g[4 * maxn + 5];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
void upd(int rt) {
    if(f[ls][0] < f[rs][1]) {
        f[rt][0] = f[rs][0];
        if(f[rs][1] - f[ls][0] + f[ls][1] <= f[ls][2]) {
            f[rt][1] = f[rs][1] - f[ls][0] + f[ls][1];
            f[rt][2] = f[rt][1] + min(f[ls][2] - f[rt][1], f[rs][2] - f[rs][1]);
        }
        else f[rt][1] = f[rt][2] = f[ls][2];
    }
    else if(f[ls][0] < f[rs][2]) {
        f[rt][0] = f[rs][0] + f[ls][0] - f[rs][1];
        f[rt][1] = f[ls][1];
        f[rt][2] = f[ls][1] + min(f[ls][2] - f[ls][1], f[rs][2] - f[ls][0]);
    }
    else {
        f[rt][0] = f[rs][0] + f[rs][2] - f[rs][1];
        f[rt][1] = f[rt][2] = f[ls][1];
    }
    g[rt] = g[ls] + g[rs] + min(f[ls][0], f[rs][1]);
}
void build(int rt, int l, int r) {
    if(l == r) {
        g[rt] = min(a[l], b[l]);
        if(a[l] <= b[l]) {
            f[rt][0] = 0;
            f[rt][1] = b[l] - a[l];
            f[rt][2] = f[rt][1] + c[l];
        }
        else {
            f[rt][0] = min(1ll * a[l] - b[l], c[l]);
            f[rt][1] = 0;
            f[rt][2] = c[l] - f[rt][0];
        }
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    upd(rt);
    // if(l == 4 && r == 5) {
    //     cout << f[rs][2] << endl;
    // }
}
void mdy(int rt, int l, int r, int qx, int ai, int bi, LL ci) {
    if(l == r) {
        a[l] = ai; b[l] = bi; c[l] = ci;
        g[rt] = min(a[l], b[l]);
        if(a[l] <= b[l]) {
            f[rt][0] = 0;
            f[rt][1] = b[l] - a[l];
            f[rt][2] = f[rt][1] + c[l];
        }
        else {
            f[rt][0] = min(1ll * a[l] - b[l], c[l]);
            f[rt][1] = 0;
            f[rt][2] = c[l] - f[rt][0];
        }
        return;
    }
    if(qx <= md) mdy(ls, l, md, qx, ai, bi, ci);
    else mdy(rs, md + 1, r, qx, ai, bi, ci);
    upd(rt);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n - 1) read(c[i]);
    c[n] = Inf;
    build(1, 1, n);
    while(q--) {
        int p, x, y; LL z; read(p); read(x); read(y); read(z);
        if(p == n) z = Inf;
        mdy(1, 1, n, p, x, y, z);
        printf("%lld\n", g[1]);
    }
    return 0;
}
