#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL __int128_t
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

int n, m, q;

// #define i128 __int128_t

#define maxn 300000
struct Tree {
    LL tr[4][maxn + 5];
    void ins(int x, LL y) {
        LL _x = x;
        For(o, 0, 3) {
            x = _x;
            while(x <= maxn) tr[o][x] += y, x += x & -x;
            y *= _x;
        }
    }
    LL que(int o, int x) {
        LL res = 0;
        while(x) res += tr[o][x], x -= x & -x;
        return res;
    }
} tr[2];

LL a[maxn + 5], b[maxn + 5];
LL as = 0, s[2][maxn + 5];
LL sol(int o, int x) {
    LL res = 0;
    res += 3 * x * tr[o ^ 1].que(2, x) - tr[o ^ 1].que(3, x) + (3 * x + 1) * tr[o ^ 1].que(1, x);
    res /= 6;
    res += (tr[o ^ 1].que(1, maxn) - tr[o ^ 1].que(1, x)) * (1ll * x * x - s[0][x - 1]);
    res += (tr[o ^ 1].que(0, maxn) - tr[o ^ 1].que(0, x)) * (s[1][x - 1] - 1ll * x * s[0][x - 1]);
    return res;
}
set<int> se[2];
void ins(int o, int x) {
    auto it = se[o].lower_bound(x);
    int r = *it, l = *--it;
    tr[o].ins(r - l, -1); as -= sol(o, r - l);
    tr[o].ins(r - x, 1); as += sol(o, r - x);
    tr[o].ins(x - l, 1); as += sol(o, x - l);
    se[o].insert(x);
}
void del(int o, int x) {
    auto it = se[o].lower_bound(x);
    int l = *--it; it++; it++;
    int r = *it;
    tr[o].ins(r - x, -1); as -= sol(o, r - x);
    tr[o].ins(x - l, -1); as -= sol(o, x - l);
    tr[o].ins(r - l, 1); as += sol(o, r - l);
    se[o].erase(x);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxn) {
        s[0][i] = s[0][i - 1] + i;
        s[1][i] = s[1][i - 1] + 1ll * i * i;
    }
    read(n); read(m); read(q);
    se[0].insert(1); se[0].insert(n + 1); tr[0].ins(n, 1);
    se[1].insert(1); se[1].insert(m + 1); tr[1].ins(m, 1);
    as = 0;
    For(i, 0, min(n, m) - 1) as += 1ll * (n - i) * (m - i);
    For(i, 1, n) read(a[i]);
    For(i, 1, m) read(b[i]);
    Rof(i, n, 2) a[i] -= a[i - 1];
    Rof(i, m, 2) b[i] -= b[i - 1];
    For(i, 2, n) if(!a[i]) ins(0, i);
    For(i, 2, m) if(!b[i]) ins(1, i);
    printf("%.0Lf\n", (LD)as);
    while(q--) {
        int op, l, r, x; read(op); read(l); read(r); read(x);
        if(op == 1) {
            if(l != 1) {
                if(!a[l]) del(0, l);
                a[l] += x;
                if(!a[l]) ins(0, l);
            }
            if(r != n) {
                if(!a[r + 1]) del(0, r + 1);
                a[r + 1] -= x;
                if(!a[r + 1]) ins(0, r + 1);
            }
        }
        else {
            if(l != 1) {
                if(!b[l]) del(1, l);
                b[l] += x;
                if(!b[l]) ins(1, l);
            }
            if(r != m) {
                if(!b[r + 1]) del(1, r + 1);
                b[r + 1] -= x;
                if(!b[r + 1]) ins(1, r + 1);
            }
        }
        printf("%.0Lf\n", (LD)as);
    }
    return 0;
}
