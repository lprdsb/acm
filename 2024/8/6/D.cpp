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
int T, n, k, a[maxn + 5], b[maxn + 5], cnt = 0, L[maxn + 5];
vector<int> vec[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int mn[4 * maxn + 5], sum[4 * maxn + 5], lpr[4 * maxn + 5];
void build(int rt, int l, int r) {
    mn[rt] = lpr[rt] = 0; sum[rt] = r - l + 1;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void mson(int rt, int x) {
    mn[rt] += x; lpr[rt] += x;
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
    sum[rt] = 0;
    if(mn[ls] == mn[rt]) sum[rt] += sum[ls];
    if(mn[rs] == mn[rt]) sum[rt] += sum[rs];
}
void mdy(int rt, int l, int r, int ql, int qr, int x) {
    if(ql <= l && qr >= r) return mson(rt, x);
    spr(rt);
    if(ql <= md) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
    upd(rt);
}
int que(int rt, int l, int r, int ql, int qr) {
    // cout << l << " " << r << " " << mn[rt] << " " << sum[rt] << endl;
    if(ql <= l && qr >= r) {
        if(mn[rt]) return 0;
        return sum[rt];
    }
    spr(rt);
    int res = 0;
    if(ql <= md) res += que(ls, l, md, ql, qr);
    if(qr > md) res += que(rs, md + 1, r, ql, qr);
    return res;
}

void mian() {
    read(n); read(k);
    cnt = 0;
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    LL res = 0;
    For(i, 1, cnt) vec[i].pb(n + 1);
    build(1, 1, n + 1);
    Rof(i, n, 1) {
        mdy(1, 1, n + 1, i, vec[a[i]].back() - 1, 1);
        vec[a[i]].pb(i);
        while(L[a[i]] < vec[a[i]].size() && vec[a[i]].size() - L[a[i]] > k) {
            mdy(1, 1, n + 1, vec[a[i]][L[a[i]] + 1], vec[a[i]][L[a[i]]] - 1, -1);
            mdy(1, 1, n + 1, vec[a[i]][L[a[i]]], n + 1, 1);
            L[a[i]]++;
        }
        res += que(1, 1, n + 1, i, n);
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, cnt) {
            vec[i].resize(0);
            L[i] = 0;
        }
    }
}
