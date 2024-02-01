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

#define maxn 100000
int n, a[maxn + 5];

#define md (l + r >> 1)
#define ls (rt << 1)
#define rs (rt << 1 | 1)
int mn[4 * maxn + 5], lpr[4 * maxn + 5];
void build(int rt, int l, int r) {
    mn[rt] = inf; lpr[rt] = 0;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
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
void upd(int rt) { mn[rt] = min(mn[ls], mn[rs]); }
void mdy(int rt, int l, int r, int ql, int qr, int x) {
    if(ql <= l && qr >= r) return mson(rt, x);
    spr(rt);
    if(ql <= md) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
    upd(rt);
}
int find(int rt, int l, int r, int x) {
    if(l == r) return l;
    spr(rt);
    if(mn[rs] <= x) return find(rs, md + 1, r, x);
    return find(ls, l, md, x);
}
void ins(int rt, int l, int r, int x, int y) {
    if(l == r) {
        mn[rt] = y;
        return;
    }
    spr(rt);
    if(x <= md) ins(ls, l, md, x, y);
    else ins(rs, md + 1, r, x, y);
    upd(rt);
}

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= n) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    build(1, 0, n);
    ins(1, 0, n, 0, -inf);
    a[0] = -1;
    int sum = 0;
    For(i, 1, n) {
        int p, t; read(p); read(t);
        if(t == 0) {
            sum--;
            ins(p, -1);
            mdy(1, 0, n, p, n, -1);
        }
        else {
            int x; read(x); a[p] = x;
            sum++;
            ins(p, 1);
            mdy(1, 0, n, p, n, 1);
            ins(1, 0, n, p, que(p));
        }
        printf("%d\n", a[find(1, 0, n, sum)]);
    }
}
