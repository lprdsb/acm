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

#define maxn 3000
int n, m, k, b[maxn + 5], cnt = 0;
vector<pair<int, int> > ch[maxn + 5];

LL dis[maxn + 5];
LL dij(int x) {
    memset(dis, inf, sizeof dis);
    dis[1] = 0;
    set<pair<LL, int> > se;
    se.insert({ 0, 1 });
    while(se.size()) {
        int u = se.begin()->sec; se.erase(se.begin());
        for(auto [v, w] : ch[u]) {
            w = max(0, w - x);
            if(dis[v] > dis[u] + w) {
                se.erase({ dis[v], v });
                dis[v] = dis[u] + w;
                se.insert({ dis[v], v });
            }
        }
    }
    return dis[n];
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb({ v, w });
        ch[v].pb({ u, w });
        b[++cnt] = w;
    }
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    LL res = Inf;
    For(i, 0, cnt) res = min(res, dij(b[i]) + 1ll * b[i] * k);
    printf("%lld\n", res);
    return 0;
}
