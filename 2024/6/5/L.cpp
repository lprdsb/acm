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
int n, m, q, a[maxn + 5];
vector<int> ch[maxn + 5];

int dis[105][maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    memset(dis, inf, sizeof dis);
    read(n); read(m), read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    For(o, 1, 100) {
        queue<int> q;
        For(i, 1, n) if(a[i] == o) {
            dis[o][i] = 0;
            q.push(i);
        }
        while(q.size()) {
            int u = q.front(); q.pop();
            for(auto v : ch[u]) if(dis[o][v] == inf) {
                dis[o][v] = dis[o][u] + 1;
                q.push(v);
            }
        }
    }
    For(i, 1, n) For(o, 1, 100) dis[o][i] = min(dis[o][i], dis[o - 1][i]);
    while(q--) {
        int x, y; read(x); read(y);
        if(dis[y][x] != inf) printf("%d\n", dis[y][x]);
        else puts("-1");
    }
}
