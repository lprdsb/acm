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

int T, n, m;

#define maxn 2000
vector<pair<int, int> > ch[maxn + 5];

int d[maxn + 5], deg[maxn + 5];
LL dis[maxn + 5];
int spfa(int s) {
    set<pair<LL, int> > se;
    dis[s] = 0;
    se.insert({ 0, s }); d[s]++;
    while(se.size()) {
        int u = se.begin()->sec; se.erase(se.begin());
        for(auto [v, w] : ch[u]) {
            if(dis[v] > dis[u] + w) {
                d[v]++;
                if(d[v] >= m) return 1;
                dis[v] = dis[u] + w;
                se.insert({ dis[v], v });
            }
        }
    }
    return 0;
}

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb({ v, w });
        deg[v]++;
    }
    For(i, 1, n) if(!d[i]) {
        if(spfa(i)) {
            puts("boo how");
            return;
        }
    }
    For(i, 1, n) dis[i] = Inf;
    spfa(1);
    For(i, 1, n) {
        if(dis[i] == Inf) printf("1000000000 ");
        else printf("%lld ", dis[i]);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(dis, inf, sizeof dis);
    int T; read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            d[i] = deg[i] = 0;
            ch[i].resize(0);
            dis[i] = Inf;
        }
    }
}
