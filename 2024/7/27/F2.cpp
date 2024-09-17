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

#define maxn 400000
int T, n, s, t, a[maxn + 5];
int mn[4 * maxn + 5];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
void mdy(int rt, int l, int r, int qx, int val) {
    if(l == r) {
        mn[rt] = val;
        return;
    }
    if(qx <= md) mdy(ls, l, md, qx, val);
    else mdy(rs, md + 1, r, qx, val);
    mn[rt] = min(mn[ls], mn[rs]);
}
int que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return mn[rt];
    int res = inf;
    if(ql <= md) res = min(res, que(ls, l, md, ql, qr));
    if(qr > md) res = min(res, que(rs, md + 1, r, ql, qr));
    return res;
}
void build(int rt, int l, int r) {
    mn[rt] = inf;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}

int f[maxn + 5];
vector<int> vec[maxn + 5];
void mian() {
    read(n); read(s); read(t);
    For(i, 1, n) read(a[i]);
    f[s] = 0;
    For(o, 1, 20) {
        build(1, 1, n);
        For(i, 1, n) {
            f[i] = min(f[i], que(1, 1, n, max(1, i - a[i]), i) + 1);
            for(auto j : vec[i]) mdy(1, 1, n, j, inf);
            mdy(1, 1, n, i, f[i]);
            if(i + a[i] <= n) vec[i + a[i]].pb(i);
            vec[i].resize(0);
        }
        For(i, 1, n) if(i < n - i + 1) {
            swap(f[i], f[n - i + 1]);
            swap(a[i], a[n - i + 1]);
        }
        build(1, 1, n);
        For(i, 1, n) {
            f[i] = min(f[i], que(1, 1, n, max(1, i - a[i]), i) + 1);
            for(auto j : vec[i]) mdy(1, 1, n, j, inf);
            mdy(1, 1, n, i, f[i]);
            if(i + a[i] <= n) vec[i + a[i]].pb(i);
            vec[i].resize(0);
        }
        For(i, 1, n) if(i < n - i + 1) {
            swap(f[i], f[n - i + 1]);
            swap(a[i], a[n - i + 1]);
        }
    }
    printf("%d\n", f[t]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) f[i] = inf;
    }
}
