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

#define maxn 300000
int n, q, a[maxn + 5], fa[2][maxn + 5], id[maxn + 5];

int find(int o, int x) { return fa[o][x] == x ? x : fa[o][x] = find(o, fa[o][x]); }

vector<pair<int, int> > vec[maxn + 5];

struct Opt {
    int l1, l2, r1, r2;
} opt[maxn + 5];
vector<pair<int, int> > Q[maxn + 5];

int as[maxn + 5];
vector<pair<int, int> > ask[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y) { while(x <= n) tr[x] += y, x += x & -x; }
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]), id[a[i]] = i;
    For(i, 0, n + 1) For(o, 0, 1) fa[o][i] = i;
    For(i, 1, n) {
        int l = find(0, id[i] - 1), r = find(1, id[i] + 1);
        if(r == n + 1) opt[i].l1 = -1;
        else {
            opt[i].l1 = l + 1; opt[i].l2 = r - 1; opt[i].r1 = r;
            Q[i].pb({ i, r });
            fa[0][id[i]] = l; fa[1][id[i]] = r;
        }
    }
    For(i, 0, n + 1) fa[0][i] = i;
    Rof(i, n, 1) {
        fa[0][id[i]] = find(0, id[i] + 1);
        for(auto [k, v] : Q[i]) opt[k].r2 = find(0, v) - 1;
    }
    For(i, 1, n) if(opt[i].l1 != -1) {
        vec[opt[i].l1].pb({ opt[i].r1, 1 });
        vec[opt[i].l1].pb({ opt[i].r2 + 1, -1 });
        vec[opt[i].l2 + 1].pb({ opt[i].r1, -1 });
        vec[opt[i].l2 + 1].pb({ opt[i].r2 + 1, 1 });
    }
    read(q);
    For(i, 1, q) {
        int l, r; read(l); read(r);
        ask[l].pb({ i, r });
    }
    For(i, 1, n) {
        for(auto [k, v] : vec[i]) ins(k, v);
        for(auto [k, v] : ask[i]) as[k] = que(v) != 0;
    }
    For(i, 1, q) puts(as[i] ? "Yes" : "No");
    return 0;
}
