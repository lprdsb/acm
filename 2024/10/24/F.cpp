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
int T, n, q, a[maxn + 5], las[maxn + 5], pre[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int mn[4 * maxn + 5];
void build(int rt, int l, int r) {
    mn[rt] = inf;
    if(l == r) return;
    build(ls, l, md);
    build(rs, md + 1, r);
}
void ins(int rt, int l, int r, int qx, int v) {
    if(l == r) {
        mn[rt] = v;
        return;
    }
    if(qx <= md) ins(ls, l, md, qx, v);
    else ins(rs, md + 1, r, qx, v);
    mn[rt] = min(mn[ls], mn[rs]);
}
int que(int rt, int l, int r, int ql, int qr) {
    if(ql > qr) return inf;
    if(ql <= l && qr >= r) return mn[rt];
    int res = inf;
    if(ql <= md) res = min(res, que(ls, l, md, ql, qr));
    if(qr > md) res = min(res, que(rs, md + 1, r, ql, qr));
    return res;
}

int to[maxn + 5], R[maxn + 5];
void mian() {
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) {
        pre[i] = las[a[i]];
        las[a[i]] = i;
    }
    build(1, 1, n);
    For(i, 1, n + 1) to[i] = inf, R[i] = n + 1;
    // cout << pre[4] << endl;
    Rof(i, n, 1) {
        if(pre[i]) {
            to[pre[i]] = que(1, 1, n, pre[i] + 1, i - 1);
            ins(1, 1, n, pre[i], i);
        }
        // if(i == 2) cout << to[i] << endl;
        R[i] = min(R[i + 1], to[i]);
    }
    while(q--) {
        int l, r; read(l); read(r);
        puts(r < R[l] ? "YES" : "NO");
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n + 1) {
            las[i] = pre[i] = 0;
        }
    }
}
