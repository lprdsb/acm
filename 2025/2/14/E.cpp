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

int n, m, q;
LL V;

#define maxn 100000
struct DSU {
    int fa[maxn + 5];
    void init() {
        For(i, 1, n) fa[i] = -1;
    }
    int find(int x) {
        assert(fa[x]);
        return fa[x] < 0 ? x : fa[x] = find(fa[x]);
    }
    void add(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(fa[u] > fa[v]) swap(u, v);
        fa[u] += fa[v];
        fa[v] = u;
    }
} dsu[62];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(q); read(V); V <<= 1;
    For(o, 0, 61) dsu[o].init();
    For(i, 1, m) {
        LL u, v, w; read(u); read(v); read(w); w = (w << 1) | 1;
        Rof(o, 61, 1) if(!((V >> (o - 1)) & 1) && ((w >> (o - 1)) & 1) && ((w & V) >> o) == (V >> o)) dsu[o].add(u, v);
    }
    while(q--) {
        int u, v; read(u); read(v);
        int fl = 0;
        For(o, 1, 61) if(dsu[o].find(u) == dsu[o].find(v)) {
            fl = 1;
            break;
        }
        if(fl) puts("Yes");
        else puts("No");
    }
}
