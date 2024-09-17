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
int n, m, q, a[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int tr[4 * maxn + 5], lpr[4 * maxn + 5], num[4 * maxn + 5], mx[4 * maxn + 5];
void build(int rt, int l, int r) {
    lpr[rt] = 0; mx[rt] = -inf; num[rt] = 0;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void mson(int rt, int x) {
    lpr[rt] += x;
    mx[rt] += x;
}
void spr(int rt) {
    if(lpr[rt]) mson(ls, lpr[rt]), mson(rs, lpr[rt]);
    lpr[rt] = 0;
}
void upd(int rt) {
    mx[rt] = max(mx[ls], mx[rs]) + lpr[rt];
}
void mdy(int rt, int l, int r, int ql, int qr, int val) {
    if(ql <= l && qr >= r) return mson(rt, val);
    spr(rt);
    if(ql <= md) mdy(ls, l, md, ql, qr, val);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, val);
    upd(rt);
}
void mdy1(int rt, int l, int r, int qx, int val) {
    if(l == r) {
        num[rt] += val;
        // cout << l << endl;
        if(num[rt]) mx[rt] = l + lpr[rt];
        else mx[rt] = -inf + lpr[rt];
        // cout << mx[rt] << endl;
        return;
    }
    spr(rt);
    if(qx <= md) mdy1(ls, l, md, qx, val);
    else mdy1(rs, md + 1, r, qx, val);
    // cout << mx[ls] << " " << mx[rs] << endl;
    // cout << mx[rt] << " " << l << " " << r << " " << mx[ls] << " " << mx[rs] << endl;
    upd(rt);
}
int que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return tr[rt];
    spr(rt);
    int res = 0;
    if(ql <= md) res = max(res, que(ls, l, md, ql, qr));
    if(qr > md) res = max(res, que(rs, md + 1, r, ql, qr));
    return res;
}

int B = 400;
struct Opt {
    int id, l, r;
} opt[maxn + 5];
bool operator < (cst Opt &x, cst Opt &y) {
    if(x.l / B != y.l / B) return x.l < y.l;
    return x.r < y.r;
}

int L = 1, R = 0;
void ins(int x) {
    // cout << x << endl;
    mdy(1, 0, m + 1, 0, x, 1);
    mdy1(1, 0, m + 1, x, 1);
}
void del(int x) {
    // cout << -x << endl;
    mdy(1, 0, m + 1, 0, x, -1);
    // cout << mx[8] << endl;
    mdy1(1, 0, m + 1, x, -1);
    // cout << mx[8] << endl;
}
void sol(int l, int r) {
    while(R < r) ins(a[++R]);
    while(R > r) del(a[R--]);
    while(L > l) ins(a[--L]);
    while(L < l) del(a[L++]);
}

int as[maxn + 5], b[maxn + 5];

int main() {
    // m = 20;
    // build(1, 0, m + 1);
    // ins(2); ins(2); ins(3); del(2); del(2); del(3); ins(3);
    // cout << mx[1] << endl;
    // ins(3);
    // del(3);
    // cout << mx[1] << endl;
    freopen("in.txt", "r", stdin);
    read(n); read(m); read(q);
    For(i, 1, n) {
        int mx = 0;
        For(j, 1, m) {
            char c; cin >> c;
            b[j] = c - '0';
            if(b[j]) mx = j;
        }
        int o = 0;
        For(j, 1, mx) {
            if()
        }
    }
    For(i, 1, n) cout << a[i] << " "; cout << endl;
    build(1, 0, m + 1);
    For(i, 1, q) {
        int l, r; read(l); read(r);
        opt[i] = { i, l, r };
    }
    sort(opt + 1, opt + q + 1);
    For(i, 1, q) {
        sol(opt[i].l, opt[i].r);
        as[opt[i].id] = mx[1];
        as[opt[i].id]--;
    }
    For(i, 1, q) printf("%d\n", as[i]);
    return 0;
}
