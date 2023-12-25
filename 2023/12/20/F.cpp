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

#define maxn 200000
int T, n;
vector<int> ch[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int f[maxn + 5], sz[maxn + 5];
void dfs(int u) {
    int mx = 0;
    sz[u] = 1;
    for(auto v : ch[u]) {
        dfs(v);
        sz[u] += sz[v];
        if(!mx || f[v] > f[mx]) mx = v;
    }
    int fl = 1;
    for(auto v : ch[u]) if(v != mx) f[mx] -= sz[v];
    f[u] = max(0, f[mx]);
    f[u]++;
}

int main() {
    //freopen("in", "r", stdin);
    cout << (1 >> 2) << endl;
    read(T);
    while(T--) {
        read(n);
        For(i, 2, n) {
            int p; read(p);
            ch[p].pb(i);
        }
        dfs(1);
        printf("%d\n", (int)(n - f[1]) / 2);
        For(i, 1, n) ch[i].resize(0);
    }
}
