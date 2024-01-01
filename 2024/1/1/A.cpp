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

int T, n1, n2, m, n;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 2000
vector<int> ch[maxn + 5];

int vis[maxn + 5], ok[maxn + 5], cut[maxn + 5];
int dfn[maxn + 5], low[maxn + 5], tim = 0, inst[maxn + 5];

void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++tim;
    int sz = 0;
    for(auto v : ch[u]) if(v != pre) {
        if(!dfn[v]) {
            sz++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u] && pre) cut[u] = 1;
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if(!pre && sz >= 2) cut[u] = 1;
}

void mian() {
    read(n1); read(n2); read(m);
    n = n1 + n2;
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    // if(n1 == 213 && n2 == 41) {
    //     tarjan(1, 0);
    //     int cnt = 0;
    //     For(i, 1, n) cnt += cut[i];
    //     cout << cnt << endl;
    // }
    ok[1] = 1;
    For(i, 1, n1) {
        For(j, 1, n) if(!vis[j] && ok[j] && !cut[j]) {
            vis[j] = 1;
            for(auto v : ch[j]) ok[v] = 1;
            break;
        }
        For(j, 1, n) if(!vis[j]) {
            For(p, 1, n) dfn[p] = low[p] = cut[p] = 0;
            tim = 0;
            tarjan(j, 0);
            break;
        }
        // if(n1 == 213 && n2 == 41) {
        //     if(i == 1) cout << cut[8] << endl;
        // }
    }
    For(i, 1, n) if(vis[i]) printf("%d ", i); puts("");
    For(i, 1, n) if(!vis[i]) printf("%d ", i); puts("");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ok[i] = vis[i] = 0;
            ch[i].resize(0);
        }
    }
}
