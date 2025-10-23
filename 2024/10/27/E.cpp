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

#define maxn 10000
int T, n, m;
vector<int> ch[3][maxn + 5];

int st[maxn + 5], tp = 0, vis[maxn + 5], ok[maxn + 5];
void dfs(int u) {
    vis[u] = 1;
    ok[u] = 1;
    for(auto v : ch[0][u]) if(!vis[v]) dfs(v);
    st[++tp] = u;
}

vector<int> poi[maxn + 5];
int col[maxn + 5], d[maxn + 5];
void dfs1(int u, int c) {
    poi[c].pb(u);
    col[u] = c;
    ok[u] = 0;
    for(auto v : ch[1][u]) if(ok[v]) dfs1(v, c);
}


void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[0][u].pb(v);
        ch[1][v].pb(u);
    }
    tp = 0;
    int cnt = 0;
    For(i, 1, n) if(!vis[i]) {
        tp = 0;
        dfs(i);
        Rof(j, tp, 1) if(ok[st[j]]) dfs1(st[j], ++cnt);
    }
    // For(i, 1, n) cout << col[i] << " "; cout << endl;
    // For(u, 1, n) for(auto v : ch[0][u]) if(col[u] != col[v]) ch[2][col[u]].pb(col[v]), d[col[v]]++;
    For(i, 1, cnt) sort(poi[i].begin(), poi[i].end());
    printf("%d\n", cnt);
    For(i, 1, n) if(vis[i]) {
        for(auto v : poi[col[i]]) printf("%d ", v), vis[v] = 0;
        puts("");
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // read(T);
    T = 1;
    while(T--) {
        mian();
        For(i, 1, n) {
            d[i] = 0;
            vis[i] = 0;
            For(o, 0, 2) ch[o][i].resize(0);
        }
    }
}
