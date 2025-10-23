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

#define maxn 300
int n, m, Q, f[maxn + 5][maxn + 5][maxn + 5], d[maxn + 5];
vector<pair<int, int> > ch[maxn + 5];

int main() {
    //freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(n); read(m); read(Q);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb({ v, w });
        d[v]++;
    }
    For(i, 1, n) For(j, 1, n) if(i != j) f[j][i][i] = 0;
    queue<int> q;
    For(i, 1, n) if(!d[i]) q.push(i);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto [v, w] : ch[u]) {
            For(i, 1, n) if(i != v) For(j, 1, n) {
                f[i][j][v] = min(f[i][j][v], f[i][j][u] + w);
            }
            d[v]--;
            if(!d[v]) q.push(v);
        }
    }
    int las = 0;
    while(Q--) {
        int u, v, s; read(u); read(v); read(s);
        u = (u + las) % n + 1;
        v = (v + las) % n + 1;
        s = (s + las) % n + 1;
        if(f[s][u][v] == inf) puts("0"), las = 0;
        else printf("%d\n", f[s][u][v]), las = f[s][u][v];
    }
    return 0;
}
