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
int T, n, q, a[maxn + 5], b[2 * maxn + 5], cnt = 0;
pair<int, int> opt[maxn + 5];

int tr[2 * maxn + 5];
void ins(int x, int y) {
    while(x <= cnt) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

multiset<int> se[2];
void se_ins(int x, int y) {
    se[0].insert(y);
    se[1].insert(-x);
}
void se_del(int x, int y) {
    se[0].erase(se[0].find(y));
    se[1].erase(se[1].find(-x));
}
set<pair<int, int> > seg[2 * maxn + 5];
void seg_ins(int p, int x) {
    pair<int, int> pa = { p, p };
    auto it = seg[x].lower_bound({ p, p });
    if(it != seg[x].begin()) {
        it--;
        if(it->sec + 1 == p) {
            pa.fir = it->fir;
            seg[x].erase(it);
        }
    }
    it = seg[x].lower_bound({ p, p });
    if(it != seg[x].end()) {
        if(p + 1 == it->fir) {
            pa.sec = it->sec;
            seg[x].erase(it);
        }
    }
    seg[x].insert(pa);
}
void seg_del(int p, int x) {
    auto it = --seg[x].lower_bound({ p + 1, p + 1 });
    pair<int, int> pa = *it;
    seg[x].erase(it);
    if(pa.fir < p) seg[x].insert({ pa.fir, p - 1 });
    if(p < pa.sec) seg[x].insert({ p + 1, pa.sec });
}
pair<int, int> sol() {
    if(!se[0].size()) return { -1, -1 };
    int mn = *se[0].begin(), mx = -*se[1].begin();
    int l = que(mn - 1), r = que(mx) + 1;
    if(l + 1 == seg[mn].begin()->fir) l = seg[mn].begin()->sec;
    auto it = --seg[mx].end();
    // cout << mx << endl;
    if(it->sec + 1 == r) r = it->fir;
    return { l + 1, r - 1 };
}
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    cnt = 0;
    For(i, 1, n) b[++cnt] = a[i];
    read(q);
    For(i, 1, q) {
        int p, x; read(p); read(x);
        opt[i] = { p, x };
        b[++cnt] = x;
    }
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    For(i, 1, q) opt[i].sec = lower_bound(b + 1, b + cnt + 1, opt[i].sec) - b;
    For(i, 1, n) ins(a[i], 1), seg_ins(i, a[i]);
    For(i, 1, n - 1) if(a[i] > a[i + 1]) se_ins(a[i], a[i + 1]);

    pair<int, int> res = sol();
    printf("%d %d\n", res.fir, res.sec);
    For(i, 1, q) {
        int p = opt[i].fir, x = opt[i].sec;
        if(p > 1 && a[p - 1] > a[p]) se_del(a[p - 1], a[p]);
        if(p < n && a[p] > a[p + 1]) se_del(a[p], a[p + 1]);
        ins(a[p], -1);
        seg_del(p, a[p]);
        a[p] = x;
        seg_ins(p, a[p]);
        ins(a[p], 1);
        if(p > 1 && a[p - 1] > a[p]) se_ins(a[p - 1], a[p]);
        if(p < n && a[p] > a[p + 1]) se_ins(a[p], a[p + 1]);
        pair<int, int> res = sol();
        printf("%d %d\n", res.fir, res.sec);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, cnt) {
            tr[i] = 0;
            seg[i].clear();
        }
        For(o, 0, 1) {
            se[o].clear();
        }
    }
}
