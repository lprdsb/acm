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

int T, n, m, s;
LL t0;

#define maxn 100000
vector<pair<int, int> > ch[maxn + 5];

LL dis[maxn + 5];
int spfa(int s) {
    set<pair<LL, int> > se;
    dis[s] = 0;
    se.insert({ 0, s });
    while(se.size()) {
        int u = se.begin()->sec; se.erase(se.begin());
        for(auto [v, w] : ch[u]) {
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                se.insert({ dis[v], v });
            }
        }
    }
    return 0;
}

void mian() {
    read(n); read(m); read(s); read(t0);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb({ v, w });
        ch[v].pb({ u, w });
    }
    spfa(s);
    vector<pair<int, LL> > as;
    For(i, 1, n) {
        if(dis[i] == Inf) as.pb({ i, -1 });
        else if(dis[i] > t0) as.pb({ i, dis[i] });
    }
    printf("%d\n", as.size());
    for(auto [i, d] : as) printf("%d %lld\n", i, d);

}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(dis, inf, sizeof dis);
    int T = 1;
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            dis[i] = Inf;
        }
    }
}
