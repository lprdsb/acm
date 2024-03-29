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

#define maxn 5000
int n, m, k, a[maxn + 5], b[maxn + 5], c[maxn + 5], f[maxn + 5][maxn + 5], to[maxn + 5];
vector<int> vec[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, n) read(a[i]), read(b[i]), read(c[i]), to[i] = i;
    For(i, 1, m) {
        int u, v; read(u); read(v);
        if(to[v] < u) to[v] = u;
    }
    For(i, 1, n) vec[to[i]].pb(i);
    memset(f, -inf, sizeof f);
    f[0][0] = 0;
    For(i, 1, n) {
        if(k < a[i]) {
            puts("-1");
            return 0;
        }
        For(j, 0, k - a[i]) f[i][j] = f[i - 1][j];
        for(auto v : vec[i]) Rof(j, maxn, 1) f[i][j] = max(f[i][j], f[i][j - 1] + c[v]);
        k += b[i];
    }
    int res = 0;
    For(i, 1, k) res = max(res, f[n][i]);
    printf("%d\n", res);
    return 0;
}
