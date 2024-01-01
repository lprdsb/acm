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

int T, m, n;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 2000000
vector<pair<int, int> > ch[maxn + 5];
int cut[maxn + 5];
int dfn[maxn + 5], low[maxn + 5], tim = 0;
int st[maxn + 5], top = 0;
vector<vector<int> > as;
void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++tim;
    st[++top] = u;
    int sz = 0;
    for(auto [v, id] : ch[u]) if(id != pre) {
        if(!dfn[v]) {
            sz++;
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
            if(low[v] == dfn[v]) {
                cut[id] = 1;
                vector<int> vec;
                while(st[top + 1] != v) vec.pb(st[top--]);
                as.pb(vec);
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if(!pre) {
        vector<int> vec;
        while(top) vec.pb(st[top--]);
        as.pb(vec);
    }
}
void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb({ v, i });
        ch[v].pb({ u, i });
    }
    For(i, 1, n) if(!dfn[i]) tarjan(i, 0);
    printf("%d\n", as.size());
    for(auto v : as) {
        printf("%d ", v.size());
        for(auto i : v) printf("%d ", i); puts("");
    }
}

int main() {
    //freopen("in", "r", stdin);
    T = 1;
    while(T--) {
        mian();
    }
}
