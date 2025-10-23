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
int T, n, m, id[maxn + 5], d[maxn + 5];
vector<pair<int, int> > as;
vector<int> ch[2][maxn + 5];
pair<int, int> pa[2 * maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, n) {
        id[i] = 0;
        d[i] = 0;
        ch[0][i].resize(0);
        ch[1][i].resize(0);
    }
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[0][u].pb(v);
        ch[1][v].pb(u);
        d[u]++;
        d[v]--;
        pa[i] = { u, v };
    }
    set<pair<int, int> > se;
    For(i, 1, n) se.insert({ -d[i], i });
    int tot = 0;
    while(se.size()) {
        int u = se.begin()->second; se.erase(se.begin());
        id[u] = ++tot;
        for(auto v : ch[1][u]) if(!id[v]) {
            se.erase({ -d[v], v });
            d[v]--;
            se.insert({ -d[v], v });
        }
        for(auto v : ch[0][u]) if(!id[v]) {
            se.erase({ -d[v], v });
            d[v]++;
            se.insert({ -d[v], v });
        }
    }
    as.resize(0);
    For(i, 1, m) if(id[pa[i].fir] < id[pa[i].sec]) as.pb(pa[i]);
    printf("%d\n", as.size());
    for(auto [u, v] : as) printf("%d %d\n", u, v);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
