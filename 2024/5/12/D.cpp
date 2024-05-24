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

#define maxn 1000000
int T, n, m, a[maxn + 5], b[maxn + 5], vis[maxn + 5], cnt = 0, id[maxn + 5], col[maxn + 5];
int sz[maxn + 5], tp[maxn + 6], dfn[maxn + 5], tim = 0, dep[maxn + 5], sz_cir[maxn + 5];
vector<int> ch[maxn + 5];

int get_dis(int x, int y) {
    if(col[x] != col[y]) return inf;
    if(dfn[x] >= dfn[y] && dfn[x] <= dfn[y] + sz[y] - 1) return dep[x] - dep[y];
    if(!id[y]) return inf;
    return dep[x] - dep[tp[x]] + (id[y] - id[tp[x]] + sz_cir[col[x]]) % sz_cir[col[x]];
}

bool chk(int dis) {
    int now = 1;
    For(i, 1, n) {
        while(now <= m && get_dis(a[i], now) > dis) now++;
        if(now > m) return 0;
    }
    return 1;
}

void dfs(int u, int c, int ftp) {
    dfn[u] = ++tim;
    sz[u] = 1;
    col[u] = c;
    if(id[u]) ftp = u;
    tp[u] = ftp;
    for(auto v : ch[u]) if(!col[v]) {
        dep[v] = dep[u] + 1;
        dfs(v, c, ftp);
        sz[u] += sz[v];
    }
}

void mian() {
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, m) read(b[i]), ch[b[i]].pb(i);
    For(i, 1, m) if(!col[i]) {
        int now = i;
        cnt++;
        while(!vis[now]) {
            vis[now] = 1;
            now = b[now];
        }
        int tem = b[now], dis = 1;
        id[now] = 1;
        while(tem != now) {
            id[tem] = ++dis;
            tem = b[tem];
        }
        sz_cir[cnt] = dis;
        dfs(now, cnt, 0);
    }
    int l = 0, r = m + 1;
    while(l < r) {
        int md = l + r >> 1;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    if(l == m + 1) puts("-1");
    else printf("%d\n", l);
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, m) {
            vis[i] = id[i] = col[i] = dep[i] = 0;
            ch[i].resize(0);
        }
        tim = cnt = 0;
    }
}
