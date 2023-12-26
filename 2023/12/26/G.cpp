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

#define maxn 200000
#define U unsigned
U int poi[4 * maxn + 5][20];
U int lpr[4 * maxn + 5];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)

int n, q, a[maxn + 5];
U int c[maxn + 5][20], mod = (1 << 20) - 1;
void build(int rt, int l, int r) {
    if(l == r) {
        poi[rt][0] = 1; poi[rt][1] = a[l] - 1;
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    For(i, 0, 19) {
        poi[rt][i] = 0;
        For(j, 0, i) poi[rt][i] += poi[ls][j] * poi[rs][i - j];
    }
}
void mson(int rt, int l, int r, U int x) {
    lpr[rt] += x;
    Rof(i, 19, 0) {
        int dd = max(0, i - (r - l + 1));
        U int pw = 1, tem = 0;
        For(o, 1, dd) pw *= x;
        For(j, dd, i) {
            // assert(r - l + 1 - (i - j) >= 0);
            tem += poi[rt][i - j] * pw * c[r - l + 1 - (i - j)][j];
            pw *= x;
        }
        poi[rt][i] = tem;
    }
    // cout << po
}
void spr(int rt, int l, int r) {
    if(lpr[rt]) {
        mson(ls, l, md, lpr[rt]);
        mson(rs, md + 1, r, lpr[rt]);
        lpr[rt] = 0;
    }
}
void mdy(int rt, int l, int r, int ql, int qr, int x) {
    if(ql <= l && qr >= r) return mson(rt, l, r, x);
    spr(rt, l, r);
    if(ql <= md) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
    For(i, 0, 19) {
        poi[rt][i] = 0;
        For(j, 0, i) poi[rt][i] += poi[ls][j] * poi[rs][i - j];
    }
}
int as[20];
void que(int rt, int l, int r, int ql, int qr) {
    if(rt == 1) {
        as[0] = 1;
        For(i, 1, 19) as[i] = 0;
    }
    if(ql <= l && qr >= r) {
        Rof(i, 19, 0) {
            U int tem = 0;
            For(j, 0, i) tem += as[j] * poi[rt][i - j];
            as[i] = tem;
        }
        return;
    }
    spr(rt, l, r);
    if(ql <= md) que(ls, l, md, ql, qr);
    if(qr > md) que(rs, md + 1, r, ql, qr);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    build(1, 1, n);
    c[0][0] = 1;
    For(i, 1, n) {
        c[i][0] = 1;
        For(j, 1, 19) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    while(q--) {
        int op, l, r, x; read(op); read(l); read(r);
        if(op == 1) {
            read(x);
            mdy(1, 1, n, l, r, x);
        }
        else {
            que(1, 1, n, l, r);
            U int res = 0;
            For(i, 0, 19) res += as[i];
            printf("%u\n", res & mod);
        }
    }
    return 0;
}
