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
int T, n, m, deg[maxn + 5];
vector<int> ch[maxn + 5];
map<int, int> ma[maxn + 5];

int st[maxn + 5];
void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        if(u > v) swap(u, v);
        if(u == v) continue;
        deg[u]++;
        ma[u][v] = 1;
        ch[v].pb(u);
    }
    int res = 0, tp = 0;
    st[++tp] = 1;
    For(i, 2, n) {
        while(tp > 1 && !deg[st[tp]]) tp--;
        if(!ma[st[tp]][i]) res++;
        st[++tp] = i;
        for(auto v : ch[i]) deg[v]--;
    }
    printf("%d\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            ma[i].clear();
        }
    }
}
