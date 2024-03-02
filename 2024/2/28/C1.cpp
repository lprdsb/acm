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
int T, n, q;
LL a[maxn + 5];
struct Opt {
    int l, r, x;
} opt[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
LL mn[4 * maxn + 5];
void build(int rt, int l, int r) {
    mn[rt] = 0;
    if(l == r) return;
    build(ls, l, md);
    build(rs, md + 1, r);
}
void mdy(int rt, int l, int r, int x, int y) {
    if(l == r) {
        mn[rt] += y;
        return;
    }
    if(x <= md) mdy(ls, l, md, x, y);
    else mdy(rs, md + 1, r, x, y);
    if(mn[ls]) mn[rt] = mn[ls];
    else mn[rt] = mn[rs];
}
void init(int rt, int l, int r) {
    if(!mn[rt]) return;
    mn[rt] = 0;
    if(l == r) return;
    init(ls, l, md);
    init(rs, md + 1, r);
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    Rof(i, n, 1) a[i] -= a[i - 1];
    read(q);
    int t = 0;
    build(1, 1, n);
    For(_, 1, q) {
        int l, r, x; read(l); read(r); read(x);
        opt[_] = { l, r, x };
        mdy(1, 1, n, l, x);
        if(r != n) mdy(1, 1, n, r + 1, -x);
        if(mn[1] < 0) init(1, 1, n), t = _;
    }
    For(i, 1, t) a[opt[i].l] += opt[i].x, a[opt[i].r + 1] -= opt[i].x;
    For(i, 1, n) a[i] += a[i - 1];
    For(i, 1, n) printf("%lld ", a[i]); puts("");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
