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
#define maxn 1000
int n, m;
vector<pair<int, int> > ch[maxn + 5];
DD dis[maxn + 5];
int d[maxn + 5];
int spfa(DD lim) {
    set<pair<DD, int> > se;
    For(i, 0, n) dis[i] = INFINITY;
    For(i, 0, n) d[i] = 0;
    dis[0] = 0;
    se.insert({ 0, 0 }); d[0]++;
    while(se.size()) {
        // cout << u << endl;
        int u = se.begin()->sec; se.erase(se.begin());
        for(auto [v, w] : ch[u]) {
            if(dis[v] > dis[u] + w - lim) {
                d[v] = d[u] + 1;
                if(d[v] >= n + 5) return 1;
                dis[v] = dis[u] + w - lim;
                se.insert({ dis[v], v });
            }
        }
    }
    return 0;
}

void mian() {
    read(n); read(m);
    For(i, 1, n) ch[0].pb({ i, 0 });
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb({ v, w });
    }
    // cout << spfa(4) << endl;
    double l = 0, r = 2000000;
    while(r - l > 1e-6) {
        double md = (l + r) / 2;
        if(spfa(md)) r = md;
        else l = md;
    }
    if(l > 1000000) puts("0.0000");
    else printf("%.4lf\n", l);
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
        For(i, 0, n) ch[i].resize(0);
    }
}
