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
int n, X, Y, a[maxn + 5];

int poi_tot = 0;
struct Poi {
    Poi *ch[2];
    int mn;
} poi[40 * maxn + 5];
Poi *get_new() {
    poi[++poi_tot] = { {}, n + 1 };
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
#define md (l + r >> 1)
void upd(Poi *rt) {
    rt->mn = n + 1;
    For(o, 0, 1) if(rt->ch[o]) rt->mn = min(rt->mn, rt->ch[o]->mn);
}
void ins(Poi *rt, int l, int r, int x, int y) {
    if(l == r) {
        rt->mn = y;
        return;
    }
    if(x <= md) ins(get_o(rt, 0), l, md, x, y);
    else ins(get_o(rt, 1), md + 1, r, x, y);
    upd(rt);
    // if(y == 99994) cout << rt->mn << " " << l << " " << r << " " << md << endl;
}
int que(Poi *rt, int l, int r, int ql, int qr) {
    if(!rt || ql > qr || qr < l || ql > r) return n + 1;
    if(ql <= l && qr >= r) return rt->mn;
    int res = n + 1;
    if(ql <= md) res = min(res, que(rt->ch[0], l, md, ql, qr));
    if(qr > md) res = min(res, que(rt->ch[1], md + 1, r, ql, qr));
    return res;
}

bool chk(int x) {
    poi_tot = 0;
    Poi *Rt = get_new();
    int pos = n;
    Rof(i, n, 1) {
        // cout << i << endl;
        int tem = min(que(Rt, 0, inf, 0, a[i] - x - 1), que(Rt, 0, inf, a[i] + x + 1, inf));
        if(tem > pos) pos = i;
        ins(Rt, 0, inf, a[i], i);
    }
    For(i, 1, n) {
        if(abs(a[i] - X) <= x) {
            if(i == pos) return 1;
        }
        else break;
    }
    For(i, 1, n) {
        if(abs(a[i] - Y) <= x) {
            if(i == pos) return 1;
        }
        else break;
    }
    return 0;
}

int main() {
    freopen("in.txt", "r", stdin);
    read(n); read(X); read(Y);
    For(i, 1, n) read(a[i]);
    int l = abs(X - Y), r = inf;
    // Poi *rt = get_new();
    // ins(rt, 0, inf, 1, 1);
    // cout << que(rt, 0, inf, 0, inf) << endl;
    while(l < r) {
        // cout << l << " " << r << endl;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    printf("%d\n", l);
    // cout << chk(13571) << endl;
    // cout << (DD)clock() / 1000 << endl;
}
