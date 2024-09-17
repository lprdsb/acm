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
#define max(x, y) ((x) > (y) ? (x) : (y))
int poi_tot = 0;
struct Poi {
    int ch[2];
    int mx;
} poi[400 * maxn + 5];
int qx, qy;
int tot = 0;
void mdy(int rt, int l, int r) {
    if(l == r) {
        poi[rt].mx = qy;
        return;
    }
    int md = l + r >> 1;
    if(qx <= md) {
        if(!poi[rt].ch[0]) poi[rt].ch[0] = ++poi_tot;
        mdy(poi[rt].ch[0], l, md);
    }
    else {
        if(!poi[rt].ch[1]) poi[rt].ch[1] = ++poi_tot;
        mdy(poi[rt].ch[1], md + 1, r);
    }
    poi[rt].mx = max(poi[poi[rt].ch[0]].mx, poi[poi[rt].ch[1]].mx);
}
int que(int rt, int l, int r) {
    if(!rt) return -inf;
    if(qx <= l && qy >= r) return poi[rt].mx;
    int res = -inf, md = l + r >> 1;
    if(qx <= md) res = max(res, que(poi[rt].ch[0], l, md));
    if(qy > md) res = max(res, que(poi[rt].ch[1], md + 1, r));
    return res;
}

int n, m, a[maxn + 5], b[maxn + 5], c[maxn + 5];
int Rt[2][maxn + 5];
void mdy(int o, int x, int y, int val) {
    while(x <= n) {
        qx = y; qy = val;
        mdy(Rt[o][x], 1, n), x += x & -x;
    }
}
void mdy1(int x, int y, int val) {
    mdy(0, x, y, val);
    mdy(1, n - x + 1, n - y + 1, -val);
}
void del(int x, int y) {
    mdy(0, x, y, -inf);
    mdy(1, n - x + 1, n - y + 1, -inf);
}
int que1(int o, int x, int y) {
    int res = -inf;
    while(x) {
        qx = 1; qy = y;
        res = max(res, que(Rt[o][x], 1, n)), x -= x & -x;
    }
    return res;
}
int chk(int x) {
    return c[x] > que1(0, a[x] - 1, b[x] - 1) && c[x] < -que1(1, n - a[x], n - b[x]);
}

int q[4 * maxn + 5], l = 1, r = 0, vis[maxn + 5];
int main() {
    poi[0].mx = -inf;
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) Rt[0][i] = ++poi_tot, Rt[1][i] = ++poi_tot;
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n) read(c[i]);

    // For(i, 1, n) a[i] = b[i] = c[i] = i;
    For(i, 1, n) q[++r] = i;
    while(m--) {
        int x = 1, y = 2; read(x); read(y);
        if(vis[x]) {
            del(a[x], b[x]);
            q[++r] = x;
            vis[x] = 0;
        }
        if(vis[y]) {
            del(a[y], b[y]);
            q[++r] = y;
            vis[y] = 0;
        }
        swap(c[x], c[y]);
        while(l <= r && chk(q[l])) {
            // cout << m << " " << l << " " << r << endl;
            mdy1(a[q[l]], b[q[l]], c[q[l]]);
            vis[q[l]] = 1;
            l++;
        }
        if(l <= r) puts("No");
        else puts("Yes");
    }
    return 0;
}
