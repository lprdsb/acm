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
int n, m;
vector<int> ch[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int tot, in[41 * maxn + 5], to[2][maxn + 5][20];
int hd[41 * maxn + 5], len = 0;
struct Edge {
    int v, net;
} e[100 * maxn + 5];
void add(int u, int v) {
    if (!u || !v) return;
    e[len] = { v, hd[u] };
    hd[u] = len++;
    in[v]++;
}
int fa[maxn + 5][20], dep[maxn + 5];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    fa[u][0] = pre;
    to[0][u][0] = ++tot;
    to[1][u][0] = ++tot;
    add(to[0][u][0], pre); add(pre, to[1][u][0]);
    For(o, 1, 18) {
        fa[u][o] = fa[fa[u][o - 1]][o - 1];
        to[0][u][o] = ++tot;
        to[1][u][o] = ++tot;
        add(to[0][u][o], to[0][u][o - 1]); add(to[0][u][o], to[0][fa[u][o - 1]][o - 1]);
        add(to[1][u][o - 1], to[1][u][o]); add(to[1][fa[u][o - 1]][o - 1], to[1][u][o]);
    }
    for (auto v : ch[u]) if (v != pre) dfs(v, u);
}

void sol(int ty, int u, int v, int c) {
    if (u == v) return;
    if (dep[u] < dep[v]) swap(u, v);
    if (dep[u] != dep[v]) {
        Rof(o, 18, 0) if (dep[fa[u][o]] > dep[v]) {
            if (!ty) add(c, to[0][u][o]);
            else add(to[1][u][o], c);
            u = fa[u][o];
        }
        if (fa[u][0] != v) {
            if (!ty) add(c, to[0][u][0]);
            else add(to[1][u][0], c);
            u = fa[u][0];
        }
        else return;
    }
    Rof(o, 18, 0) if (fa[u][o] != fa[v][o]) {
        if (!ty) add(c, to[0][u][o]);
        else add(to[1][u][o], c);
        if (!ty) add(c, to[0][v][o]);
        else add(to[1][v][o], c);
        u = fa[u][o];
        v = fa[v][o];
    }
    if (!ty) add(c, to[0][u][0]);
    else add(to[1][u][0], c);
    if (!ty) add(c, to[0][v][0]);
    else add(to[1][v][0], c);
}

int as[maxn + 5];

int q[41 * maxn + 5], r = 0, l = 1;
int main() {
    memset(hd, -1, sizeof hd);
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    tot = n;
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    For(i, 1, m) {
        int op, a, b, c; read(op); read(a); read(b); read(c);
        sol(op - 1, a, c, c);
        sol(op - 1, b, c, c);
        if (a != c) {
            if (op == 1) add(c, a);
            else add(a, c);
        }
        if (b != c) {
            if (op == 1) add(c, b);
            else add(b, c);
        }
    }
    For(i, 1, tot) if (!in[i]) q[++r] = i;
    int cnt = 0;
    while (l <= r) {
        int u = q[l++];
        if (u <= n) as[u] = ++cnt;
        Tra(u, i) {
            int v = e[i].v;
            in[v]--;
            if (!in[v]) q[++r] = v;
        }
    }
    // if (n == 200000) {
    //     cout << "asd";
    //     return 0;
    // }
    if (cnt == n) {
        For(i, 1, n) printf("%d ", as[i]);
    }
    else puts("-1");
    return 0;
}
