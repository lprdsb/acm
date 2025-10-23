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

int n, q;

#define maxn 100000
int a[maxn + 5], b[maxn + 5];
vector<int> vec;

int B = 800;
struct Opt {
    int l, r, k, id;
} opt[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int mn[4 * maxn + 5], lpr[4 * maxn + 5];
void mson(int rt, int v) {
    lpr[rt] += v;
    mn[rt] += v;
}
void spr(int rt) {
    if(lpr[rt]) {
        mson(ls, lpr[rt]);
        mson(rs, lpr[rt]);
        lpr[rt] = 0;
    }
}
void upd(int rt) { mn[rt] = min(mn[ls], mn[rs]); }
void mdy(int rt, int l, int r, int ql, int qr, int v) {
    if(ql <= l && qr >= r) return mson(rt, v);
    spr(rt);
    if(ql <= md) mdy(ls, l, md, ql, qr, v);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, v);
    upd(rt);
}

int as[maxn + 5];
int L = 1, R = 0, sum = 0;
void ins(int x) {
    sum += !b[x];
    // cout << x << " " << b[x] << endl;
    // cout << a[x] << " " << n << " " << (b[x] ? 1 : -1) << endl;
    mdy(1, 1, n, a[x], n, b[x] ? 1 : -1);
}
void del(int x) {
    sum -= !b[x];
    mdy(1, 1, n, a[x], n, b[x] ? -1 : 1);
}
int sol(int l, int r) {
    while(R < r) ins(++R);
    while(L > l) ins(--L);
    while(R > r) del(R--);
    while(L < l) del(L++);
    // cout << que(1, 1, n, 1, n) << endl;
    return sum + min(0, mn[1]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    vector<int> vec;
    For(i, 1, n) read(a[i]), read(b[i]), vec.pb(a[i]);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    For(i, 1, n) a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    // For(i, 1, n) cout << a[i] << " "; cout << endl;
    // For(i, 1, n) cout << b[i] << " "; cout << endl;
    For(i, 1, q) {
        int l, r, k; read(l); read(r); read(k);
        opt[i] = { l, r, r - l + 1 - k, i };
    }
    sort(opt + 1, opt + q + 1, [](Opt x, Opt y) {
        if(x.l / B != y.l / B) return x.l < y.l;
        return x.r < y.r;
        });
    For(i, 1, q) as[opt[i].id] = sol(opt[i].l, opt[i].r) - opt[i].k;
    For(i, 1, q) printf("%d\n", max(0, as[i]));
}
