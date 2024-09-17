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

#define maxn 40
int n, m, ma[maxn + 5][maxn + 5];
vector<int> vec[2][1 << 20];
vector<int> ch[maxn + 5];

int tot = 0;
int dfs(int u, int mask1, int mask2) {
    tot++;
    if(!vec[0][mask1].size() && !vec[1][mask2].size()) return 0;
    int m1 = 0, m2 = 0, res = 0;
    for(auto v : vec[0][mask1]) if(ma[u][v]) m1 |= 1 << (v - 1);
    for(auto v : vec[1][mask2]) if(ma[u][v]) m2 |= 1 << (v - 20 - 1);
    for(auto v : vec[0][mask1]) if(ma[u][v]) res = max(res, dfs(v, mask1 ^ m1, mask2 ^ m2) + 1);
    for(auto v : vec[1][mask2]) if(ma[u][v]) res = max(res, dfs(v, mask1 ^ m1, mask2 ^ m2) + 1);
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ma[u][v] = ma[v][u] = 1;
    }
    For(i, 1, (1 << 20) - 1) For(o, 0, 19) if((i >> o) & 1) {
        if(o + 1 <= n) vec[0][i].pb(o + 1);
    }
    For(i, 1, (1 << 20) - 1) For(o, 0, 19) if((i >> o) & 1) {
        if(20 + o + 1 <= n) vec[1][i].pb(20 + o + 1);
    }
    int res = 0, all = (1 << 20) - 1;
    For(i, 1, n) res = max(res, dfs(i, all, all));
    printf("%d\n", res + 1);
    // cout << tot << endl;
}
