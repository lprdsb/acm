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

#define maxn 1200000
int T, n, m, k, a[maxn + 5];
LL lpr[maxn + 5];
pair<LL, int> mn[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)

void mson(int rt, LL x) {
    lpr[rt] += x;
    mn[rt].fir += x;
}
void upd(int rt) { mn[rt] = mn[ls] < mn[rs] ? mn[ls] : mn[rs]; }
void build(int rt, int l, int r) {
    if(l == r) {
        mn[rt] = { a[l], -l };
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    upd(rt);
    // cout << l << " " << r << " " << mn[rt].fir << " " << mn[rt].sec << endl;
}
void spr(int rt) {
    if(lpr[rt]) {
        mson(ls, lpr[rt]);
        mson(rs, lpr[rt]);
        lpr[rt] = 0;
    }
}
void mdy(int rt, int l, int r, int ql, int qr, LL x) {
    if(ql > qr) return;
    if(ql <= l && qr >= r) return mson(rt, x);
    spr(rt);
    if(ql <= md) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
    upd(rt);
}

void mian() {
    read(n); read(m); read(k);
    For(i, 1, n) read(a[i]);
    sort(a + 1, a + n + 1);
    LL res = 0;
    For(i, 1, n) {
        int cnt = min(k, m);
        k -= cnt;
        res += 1ll * cnt * a[i] + 1ll * k * cnt;
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
