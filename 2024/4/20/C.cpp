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
int T, n, m, ok[maxn + 5];
pair<int, int> pa[maxn + 5];
vector<pair<int, int> > ch[maxn + 5];

int vis[maxn + 5], tim = 0;
void dfs(int u) {
    vis[u] = ++tim;
    int mn = 0;
    for(auto [v, id] : ch[u]) {
        if(vis[v]) {
            if(!mn || vis[v] < vis[pa[mn].sec]) mn = id;
        }
        else {
            ok[id] = 1;
            dfs(v);
        }
    }
    if(mn) ok[mn] = 1;
}

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb({ v, i });
        pa[i] = { u, v };
    }
    tim = 0;
    dfs(1);
    int sum = 0;
    For(i, 1, m) sum += ok[i];
    if(sum < 2 * n) {
        For(i, 1, m) if(!ok[i]) {
            ok[i] = 1;
            sum++;
            if(sum == 2 * n) break;
        }
    }
    For(i, 1, m) if(!ok[i]) printf("%d %d\n", pa[i].fir, pa[i].sec);
    For(i, 1, m) ok[i] = 0;
    For(i, 1, n) vis[i] = 0, ch[i].resize(0);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
