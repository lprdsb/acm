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
#define Inf 100000000000
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

#define maxm 100000
int poi_tot = 0;
struct Poi {
    Poi *ch[2];
    int sum;
} poi[80 * maxm + 5];
Poi *get_new() {
    poi[++poi_tot] = {};
    assert(poi_tot <= 80 * maxm);
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
Poi *ins(Poi *rt, LL l, LL r, LL qx, int y) {
    if(qx < l || qx > r) return rt;
    Poi *rt1 = get_new();
    if(rt) {
        rt1->sum = rt->sum;
        For(o, 0, 1) rt1->ch[o] = rt->ch[o];
    }
    rt1->sum += y;
    if(l == r) return rt1;
    LL md = l + r >> 1;
    if(qx <= md) rt1->ch[0] = ins(rt ? rt->ch[0] : 0, l, md, qx, y);
    else rt1->ch[1] = ins(rt ? rt->ch[1] : 0, md + 1, r, qx, y);
    return rt1;
}
int que(Poi *rt, LL l, LL r, LL ql, LL qr) {
    if(!rt || ql > qr) return 0;
    if(ql <= l && qr >= r) return rt->sum;
    int sum = 0;
    LL md = l + r >> 1;
    if(ql <= md) sum += que(rt->ch[0], l, md, ql, qr);
    if(qr > md) sum += que(rt->ch[1], md + 1, r, ql, qr);
    return sum;
}

#define maxn 30000
int n, len;
LL k;
LL a[maxn + 5], b[maxn + 5], c[maxn + 5];

LL s[3][maxn + 5];
Poi *Rt[maxn + 5][2];
LL get_s(LL lim) {
    LL res = 0;
    Rof(i, n - len + 1, 1) res += que(Rt[i][0], -Inf, Inf, -Inf, lim - s[1][i]) + que(Rt[i][1], -Inf, Inf, -Inf, lim - s[0][i]);
    return res;
}
void init() {
    Rof(i, n - len + 1, 1) {
        Rt[i - 1][0] = ins(Rt[i][0], -Inf, Inf, s[2][i], 1);
        if(i + len - 1 <= n - len + 1) {
            Rt[i - 1][0] = ins(Rt[i - 1][0], -Inf, Inf, s[2][i + len - 1], -1);
            Rt[i - 1][1] = ins(Rt[i][1], -Inf, Inf, s[0][i + len - 1], 1);
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(len); read(k);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]), b[i] -= a[i];
    For(i, 1, n) read(c[i]), c[i] -= a[i];
    For(i, 1, n) {
        c[i] += c[i - 1];
        b[i] += b[i - 1];
    }
    For(i, 1, n - len + 1) {
        s[0][i] = b[i + len - 1] - b[i - 1];
        s[1][i] = c[i + len - 1] - b[i + len - 1] - b[i - 1];
        s[2][i] = b[i - 1] + b[i + len - 1] - c[i - 1];
    }
    init();
    LL l = 0, r = Inf;
    while(l < r) {
        LL md = l + r >> 1;
        if(get_s(md) >= k) r = md;
        else l = md + 1;
    }
    For(i, 1, n) l += a[i];
    printf("%lld\n", l);
    return 0;
}
