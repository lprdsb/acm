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

#define maxn 300000
int n, m;
LL poi[maxn + 5][2];
map<int, int> ma[maxn + 5];
struct Edge {
    int u, v, w;
} edge[maxn + 5];
vector<int> pp[maxn + 5];
vector<pair<int, int> > ch[maxn + 5];

LL res = 0;
LL sol(vector<int> &vec) {
    LL sum = 0;
    For(i, 0, vec.size() - 1) For(j, i + 1, vec.size() - 1) {
        if(ma[vec[i]].count(vec[j])) sum += ma[vec[i]][vec[j]];
        else sum -= 1000000;
    }
    return sum;
}

int du[maxn + 5], vis[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(poi[i][0]), read(poi[i][1]);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        edge[i] = { u, v, w };
        du[u]++; du[v]++;
        ma[u][v] = ma[v][u] = w;
        res = max(res, 1ll * w);
    }
    For(i, 1, m) {
        auto [u, v, w] = edge[i];
        if(du[u] > du[v]) swap(u, v);
        ch[u].pb({ v, i });
    }
    For(i, 1, n) {
        for(auto [v, id] : ch[i]) vis[v] = id;
        for(auto [v, id] : ch[i]) {
            for(auto [v1, id1] : ch[v]) {
                if(vis[v1]) {
                    pp[vis[v1]].pb(v);
                    pp[id].pb(v1);
                    pp[id1].pb(i);
                    res = max(res, 1ll * edge[id].w + edge[id1].w + edge[vis[v1]].w);
                }
                res = max(res, 1ll * edge[id].w + edge[id1].w - 1000000);
            }
        }
        for(auto [v, id] : ch[i]) vis[v] = 0;
    }
    For(i, 1, m) {
        // cout << pp[i].size() << endl;
        int u = edge[i].u, v = edge[i].v;
        sort(pp[i].begin(), pp[i].end(), [&](cst int &x, cst int &y) {
            return (poi[x][0] - poi[u][0]) * (poi[y][1] - poi[u][1]) - (poi[y][0] - poi[u][0]) * (poi[x][1] - poi[u][1]) >= 0;
            });
        int mx[2] = { -1, -1 };
        For(j, 0, pp[i].size() - 1) {
            int tem = ma[u][pp[i][j]] + ma[v][pp[i][j]];
            For(o, 0, 1) if(tem > mx[o]) swap(tem, mx[o]);
        }
        For(j, 0, pp[i].size() - 1) {
            vector<int> vec{ u, v, pp[i][j] };
            For(p, j + 1, min(j + 2, (int)pp[i].size() - 1)) {
                // if(p == j + 2) cout << "asd" << endl;
                vec.pb(pp[i][p]);
                LL tem = sol(vec);
                res = max(res, tem);
                if(p == j + 1) res = max(res, tem + mx[0] - 4000000);
            }
        }
        if(mx[1] != -1) res = max(res, 1ll * mx[0] + mx[1] + edge[i].w - 1000000);
    }
    printf("%d\n", res);
}
