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
int n, m, q;
pair<int, pair<int, int> > edge[maxn + 5];

LL as[maxn + 5];
vector<pair<int, int> > ch[maxn + 5];
vector<int> ve[maxn + 5], vv[maxn + 5], vec[maxn + 5];

set<pair<int, int> > se;

int fa[maxn + 5];
int find(int x) {
    if(fa[x] < 0) return x;
    return fa[x] = find(fa[x]);
}

int du[maxn + 5], vis[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(q);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        if(u > v) swap(u, v);
        edge[i] = { w, {u, v} };
    }
    sort(edge + 1, edge + m + 1);
    int mm = 0;
    For(i, 1, m) {
        if(se.find({ edge[i].sec.fir, edge[i].sec.sec }) == se.end()) {
            edge[++mm] = edge[i];
        }
        se.insert({ edge[i].sec.fir, edge[i].sec.sec });
    }
    m = mm;
    For(i, 1, m) {
        int u = edge[i].sec.fir, v = edge[i].sec.sec;
        du[u]++; du[v]++;
    }
    For(i, 1, m) {
        int u = edge[i].sec.fir, v = edge[i].sec.sec;
        if(du[u] > du[v]) swap(u, v);
        ch[u].pb({ i, v });
    }
    For(_, 1, q) {
        int k; read(k);
        For(i, 1, k) {
            int u; read(u); vis[u] = 1;
            vec[_].pb(u);
        }
        for(auto u : vec[_]) for(auto [i, v] : ch[u]) if(vis[v]) ve[i].pb(_);
        for(auto u : vec[_]) vis[u] = 0;
    }
    For(i, 1, m) {
        for(auto k : ve[i]) vv[k].pb(i);
    }
    For(i, 1, n) fa[i] = -1;
    For(_, 1, q) {
        int cnt = vec[_].size();
        LL res = 0;
        for(auto id : vv[_]) {
            int u = edge[id].sec.fir, v = edge[id].sec.sec, w = edge[id].fir;
            u = find(u); v = find(v);
            if(u != v) {
                if(fa[u] > fa[v]) swap(u, v);
                fa[v] += fa[u];
                fa[u] = v;
                cnt--;
                res += w;
            }
        }
        if(cnt == 1) printf("%lld\n", res);
        else puts("-1");
        for(auto v : vec[_]) fa[v] = -1;
    }
}
