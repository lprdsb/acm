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
int n, m, a[maxn + 5];

int poi_tot = 0;
struct Poi {
    Poi *ch[2];
    int sum;
} poi[80 * maxn + 5];
Poi *hd[2][maxn + 5];
Poi *get_new() {
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
#define md (l + r >> 1)
void ins(Poi *rt1, Poi *rt2, int l, int r, int x) {
    // cout << (rt1 == hd[0][0]->ch[0]) << endl;
    *rt1 = *rt2;
    rt1->sum++;
    if(l == r) return;
    if(x <= md) {
        rt1->ch[0] = get_new();
        ins(rt1->ch[0], get_o(rt2, 0), l, md, x);
    }
    else {
        rt1->ch[1] = get_new();
        ins(rt1->ch[1], get_o(rt2, 1), md + 1, r, x);
    }
}
int find(Poi *rt1, Poi *rt2, int l, int r, int x) {
    if(l == r) return l;
    int sum = 0;
    if(rt1 && rt1->ch[0]) sum += rt1->ch[0]->sum;
    if(rt2 && rt2->ch[0]) sum += rt2->ch[0]->sum;
    // cout << l << " " << md << " " << x << " " << sum << endl;
    if(x > sum) {
        x -= sum;
        if(rt1) rt1 = rt1->ch[1];
        if(rt2) rt2 = rt2->ch[1];
        return find(rt1, rt2, md + 1, r, x);
    }
    else {
        if(rt1) rt1 = rt1->ch[0];
        if(rt2) rt2 = rt2->ch[0];
        return find(rt1, rt2, l, md, x);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    hd[0][0] = hd[1][n + 1] = get_new();
    For(i, 1, n) {
        hd[0][i] = get_new();
        ins(hd[0][i], hd[0][i - 1], 0, n - 1, a[i]);
    }
    Rof(i, n, 1) {
        hd[1][i] = get_new();
        ins(hd[1][i], hd[1][i + 1], 0, n - 1, a[i]);
    }
    // cout << hd[1][4]->ch[0]->sum << endl;
    For(i, 1, m) {
        int l, r; LL k; read(l); read(r); read(k);
        if(k > n - (r - l + 1)) printf("%lld\n", n - 1 + (k - n + (r - l + 1)));
        else printf("%d\n", find(hd[0][l - 1], hd[1][r + 1], 0, n - 1, k));
    }
    return 0;
}
