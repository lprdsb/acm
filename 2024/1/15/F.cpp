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
int n, m, Q, tot = 0, dis[maxn + 5], sx, sy;
vector<int> a[maxn + 5], id[2][maxn + 5];
vector<pair<int, int> > vec;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool chk(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

struct DSU {
    int fa[4 * maxn + 5];
    DSU() { memset(fa, 0, sizeof fa); }
    int find(int x) { return fa[x] <= 0 ? x : fa[x] = find(fa[x]); }
};

vector<pair<int, int> > to;
vector<int> ch[2 * maxn + 5];
void add(int u, int v) {
    ch[u].pb(v);
    ch[v].pb(u);
}

int fa[4 * maxn + 5][25], dep[4 * maxn + 5], as[4 * maxn + 5];

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    Rof(o, 23, 0) if(dep[fa[u][o]] >= dep[v]) {
        u = fa[u][o];
        if(dep[u] == dep[v]) break;
    }
    if(u == v) return u;
    Rof(o, 23, 0) if(fa[u][o] != fa[v][o]) {
        u = fa[u][o];
        v = fa[v][o];
    }
    return fa[u][0];
}

int vis[4 * maxn + 5];
void sol(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    sol(fa[u][0]);
    dep[u] = dep[fa[u][0]] + 1;
    For(o, 1, 23) fa[u][o] = fa[fa[u][o - 1]][o - 1];
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(Q);
    For(i, 1, n) {
        a[i].resize(m + 1);
        id[0][i].resize(m + 1);
        id[1][i].resize(m + 1);
        For(j, 1, m) {
            char c; cin >> c;
            if(c == '#') a[i][j] = 1, sx = i, sy = j;
            if(c == 'v') vec.pb({ i, j });
        }
    }
    For(i, 1, n) For(j, 1, m) id[0][i][j] = ++tot;
    For(i, 1, n) For(j, 1, m) id[1][i][j] = ++tot;
    For(i, 1, n) For(j, 1, m) if(!a[i][j]) {
        if(j < m && !a[i][j + 1]) add(id[0][i][j], id[0][i][j + 1]), add(id[1][i][j], id[1][i][j + 1]);
        if(i < n && !a[i + 1][j]) {
            if(i + 1 == sx && j > sy) add(id[0][i][j], id[1][i + 1][j]), add(id[1][i][j], id[0][i + 1][j]);
            else add(id[0][i][j], id[0][i + 1][j]), add(id[1][i][j], id[1][i + 1][j]);
        }
    }
    memset(dis, -1, sizeof dis);
    queue<pair<int, int> > q;
    for(auto [x, y] : vec) {
        q.push({ x, y });
        dis[id[0][x][y]] = 0;
    }
    while(q.size()) {
        pair<int, int> pa = q.front(); q.pop();
        For(o, 0, 3) {
            int tx = pa.fir + dir[o][0], ty = pa.sec + dir[o][1];
            if(!chk(tx, ty) || dis[id[0][tx][ty]] != -1) continue;
            dis[id[0][tx][ty]] = dis[id[0][pa.fir][pa.sec]] + 1;
            q.push({ tx, ty });
        }
    }
    For(i, 1, n) For(j, 1, m) if(!a[i][j]) to.pb({ i, j }), as[id[0][i][j]] = as[id[1][i][j]] = dis[id[0][i][j]];
    sort(to.begin(), to.end(), [](pair<int, int> _x, pair<int, int> _y) {return dis[id[0][_x.fir][_x.sec]] > dis[id[0][_y.fir][_y.sec]];});
    DSU dsu;
    for(auto [x, y] : to) For(o, 0, 1) {
        int u = dsu.find(id[o][x][y]);
        for(auto v : ch[id[o][x][y]]) if(as[u] <= as[v]) {
            v = dsu.find(v);
            if(u != v) {
                as[++tot] = as[u];
                fa[u][0] = fa[v][0] = dsu.fa[u] = dsu.fa[v] = tot;
                u = tot;
            }
        }
    }
    reverse(to.begin(), to.end());
    For(i, 1, tot) sol(i);
    // int now = id[0][9][1];
    // cout << dep[now] << endl;
    // while(now) cout << now << " " << as[now] << endl, now = fa[now][0];
    while(Q--) {
        int x, y; read(x); read(y);
        printf("%d\n", as[lca(id[0][x][y], id[1][x][y])]);
    }
    return 0;
}
