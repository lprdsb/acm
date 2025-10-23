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
int T, n, m, k, vis[maxn + 5];

vector<pair<int, int> > ch[maxn + 5];
LL dis[maxn + 5];

void mian() {
    read(n); read(m); read(k);
    For(i, 1, k) {
        int x; read(x);
        ch[x].pb({ n + x, 0 });
    }
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb({ v, w });
        ch[v].pb({ u, w });
        ch[n + u].pb({ n + v, w });
        ch[n + v].pb({ n + u, w });
    }
    priority_queue<pair<LL, int> > q;
    For(i, 1, 2 * n) dis[i] = Inf;
    dis[1] = 0;
    q.push({ 0, 1 });
    while(q.size()) {
        int u = q.top().sec; q.pop();
        for(auto [v, w] : ch[u]) {
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({ -dis[v], v });
            }
        }
    }
    printf("%lld\n", dis[2 * n] == Inf ? -1 : dis[2 * n]);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, 2 * n) ch[i].resize(0);
    }
}
