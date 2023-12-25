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

#define maxn 200000
int n, a[maxn + 5];

#define ls rt << 1
#define rs rt << 1 | 1
int mx[4 * maxn + 5];
void build(int rt, int l, int r) {
    mx[rt] = n + 1;
    if(l == r) return;
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}
void mdy(int rt, int l, int r, int qx, int val) {
    if(l == r) {
        mx[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    if(qx <= mid) mdy(ls, l, mid, qx, val);
    else mdy(rs, mid + 1, r, qx, val);
    mx[rt] = max(mx[ls], mx[rs]);
}
int que(int rt, int l, int r, int qx) {
    if(qx >= r) return mx[rt];
    int mid = l + r >> 1, res = que(ls, l, mid, qx);
    if(qx > mid) res = max(res, que(rs, mid + 1, r, qx));
    return res;
}
int find(int rt, int l, int r, int qx) {
    if(l == r) return l;
    int mid = l + r >> 1;
    if(mx[ls] > qx) return find(ls, l, mid, qx);
    return find(rs, mid + 1, r, qx);
}


int mn[4 * maxn + 5], lpr[4 * maxn + 5];
void build1(int rt, int l, int r) {
    mn[rt] = n + 1;
    lpr[rt] = inf;
    if(l == r) return;
    int mid = l + r >> 1;
    build1(ls, l, mid);
    build1(rs, mid + 1, r);
}
void mson(int rt, int x) {
    mn[rt] = min(mn[rt], x);
    lpr[rt] = min(lpr[rt], x);
}
void spr(int rt) {
    if(lpr[rt] != inf) {
        mson(ls, lpr[rt]);
        mson(rs, lpr[rt]);
        lpr[rt] = inf;
    }
}
void upd(int rt) {
    mn[rt] = min(mn[ls], mn[rs]);
}
void mdy(int rt, int l, int r, int ql, int qr, int x) {
    if(ql <= l && qr >= r) return mson(rt, x);
    spr(rt);
    int mid = l + r >> 1;
    if(ql <= mid) mdy(ls, l, mid, ql, qr, x);
    if(qr > mid) mdy(rs, mid + 1, r, ql, qr, x);
    upd(rt);
}
void que(int rt, int l, int r) {
    if(l == r) {
        printf("%d ", mn[rt]);
        return;
    }
    spr(rt);
    int mid = l + r >> 1;
    que(ls, l, mid); que(rs, mid + 1, r);
}

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

vector<pair<int, int> > vec[maxn + 5];

int to[maxn + 5], mex[maxn + 5], R[maxn + 5], las[maxn + 5];
int main() {
    freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) {
        read(a[i]);
        if(!a[i] && a[i - 1]) vec[0].pb({ 1, i - 1 - las[0] });
        las[a[i]] = i;
    }
    // cout << las[0] << endl;
    if(a[n]) vec[0].pb({ 1, n - las[0] });

    build(1, 0, n + 1);
    // cout << que(1, 0, n + 1, 0) << endl;
    For(i, 0, n) las[i] = n + 1;
    Rof(i, n, 1) {
        las[a[i]] = i;
        mdy(1, 0, n + 1, a[i], i);
        to[i] = que(1, 0, n + 1, a[i]);
        mex[i] = find(1, 0, n + 1, to[i]);
        // if(i == n) cout << mex[i] << endl;
        R[i] = las[mex[i]] - 1;
    }
    For(i, 1, maxn) las[i] = 0;
    For(i, 1, n) if(to[i] <= n) {
        las[a[i]] = i;
        vec[mex[i]].pb({ to[i] - i + 1 , R[i] - las[mex[i]] });
    }

    For(i, 1, n) if(i < n - i + 1) swap(a[i], a[n - i + 1]);
    build(1, 0, n + 1);
    For(i, 0, n) las[i] = n + 1;
    Rof(i, n, 1) {
        las[a[i]] = i;
        mdy(1, 0, n + 1, a[i], i);
        to[i] = que(1, 0, n + 1, a[i]);
        mex[i] = find(1, 0, n + 1, to[i]);
        R[i] = las[mex[i]] - 1;
        // cout << i << " " << mex[i]
    }
    For(i, 1, maxn) las[i] = 0;
    For(i, 1, n) if(to[i] <= n) {
        las[a[i]] = i;
        vec[mex[i]].pb({ to[i] - i + 1 , R[i] - las[mex[i]] });
        // cout << i << " " << to[i] << " " << R[i] << " " << mex[i] << endl;
    }
    // for(auto [l, r] : vec[2]) cout << l << " " << r << endl;

    build1(1, 1, n);
    Rof(i, n + 1, 0) {
        sort(vec[i].begin(), vec[i].end());
        int now = 0;
        for(auto [l, r] : vec[i]) {
            if(l > now + 1) mdy(1, 1, n, now + 1, l - 1, i);
            if(r > now) now = r;
        }
        // if(i == 0) cout << now + 1 << endl;
        if(now + 1 <= n) mdy(1, 1, n, now + 1, n, i);
    }
    que(1, 1, n);
    return 0;
}