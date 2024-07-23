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
int n, q;
LL a[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
struct Node {
    int pos;
    LL mx, sum;
};
struct Poi {
    int mx, mxp;
    LL sum;
    vector<Node> pa[2];
} poi[4 * maxn + 5];
Poi operator + (cst Poi &x, cst Poi &y) {
    if(x.mx == -2) return y;
    Poi res = {};
    res.mx = max(x.mx, y.mx);

    int now = 0;
    For(i, 0, x.pa[1].size() - 1) {
        while(now < y.pa[0].size() && y.pa[0][now].mx <= x.pa[1][i].mx) now++;
        if(now && 2 * max(x.pa[1][i].mx, y.pa[0][now - 1].mx) - x.pa[1][i].sum - y.pa[0][now - 1].sum < 0)
            res.mx = max(res.mx, y.pa[0][now - 1].pos - x.pa[1][i].pos - 1);
    }
    now = 0;
    For(i, 1, y.pa[0].size() - 1) {
        while(now < x.pa[1].size() && x.pa[1][now].mx <= y.pa[0][i].mx) now++;
        if(now && 2 * max(x.pa[1][now - 1].mx, y.pa[0][i].mx) - y.pa[0][i].sum - x.pa[1][now - 1].sum < 0)
            res.mx = max(res.mx, y.pa[0][i].pos - x.pa[1][now - 1].pos - 1);
    }

    res.pa[0] = x.pa[0];
    for(auto [pos, mx, sum] : y.pa[0]) if(a[pos] - sum - x.sum >= 0) res.pa[0].pb({ pos, max(mx, a[x.mxp]), x.sum + sum });
    res.pa[1] = y.pa[1];
    for(auto [pos, mx, sum] : x.pa[1]) if(a[pos] - sum - y.sum >= 0) res.pa[1].pb({ pos, max(mx, a[y.mxp]), sum + y.sum });

    res.sum = x.sum + y.sum;
    res.mxp = a[x.mxp] > a[y.mxp] ? x.mxp : y.mxp;

    return res;
}

void build(int rt, int l, int r) {
    poi[rt].pa[0].resize(0);
    poi[rt].pa[1].resize(0);
    if(l == r) {
        poi[rt].mx = -1;
        poi[rt].sum = a[l];
        poi[rt].mxp = l;
        poi[rt].pa[0].pb({ l, 0, 0 });
        poi[rt].pa[1].pb({ l, 0, 0 });
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    poi[rt] = poi[ls] + poi[rs];
}

void mdy(int rt, int l, int r, int x, LL y) {
    if(l == r) {
        a[x] = y;
        poi[rt].sum = a[x];
        return;
    }
    if(x <= md) mdy(ls, l, md, x, y);
    else mdy(rs, md + 1, r, x, y);
    poi[rt] = poi[ls] + poi[rs];
}

Poi que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return poi[rt];
    Poi res = { -2 };
    if(ql <= md) res = res + que(ls, l, md, ql, qr);
    if(qr > md) res = res + que(rs, md + 1, r, ql, qr);
    return res;
}

int T;

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        read(n); read(q);
        For(i, 1, n) read(a[i]);
        build(1, 1, n);
        while(q--) {
            int op, x; LL y; read(op); read(x); read(y);
            if(op == 1) {
                Poi res = que(1, 1, n, x, y);
                int as = res.mx;
                for(auto [pos, mx, sum] : res.pa[0]) if(2 * mx - sum < 0) as = max(as, pos - x);
                for(auto [pos, mx, sum] : res.pa[1]) if(2 * mx - sum < 0) as = max((LL)as, y - pos);
                if(2 * a[res.mxp] - res.sum < 0) as = y - x + 1;
                printf("%d\n", as);
            }
            else mdy(1, 1, n, x, y);
        }
    }
    return 0;
}
