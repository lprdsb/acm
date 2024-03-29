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

int n, c, w[25][25], vis[25], mn[25];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(c);
    For(i, 0, n - 1) For(j, 0, n - 1) read(w[i][j]);
    int all = (1 << n) - 1;
    LL res = inf;
    For(mask, 1, all) {
        For(i, 0, n - 1) vis[i] = 0, mn[i] = inf;
        mn[__builtin_ctz(mask)] = 0;
        LL sum = c * __builtin_popcount(mask);
        For(_, 1, n) {
            int p = -1;
            For(i, 0, n - 1) if(!vis[i] && mn[i] != inf && (p == -1 || mn[p] > mn[i])) p = i;
            if(p == -1) {
                sum = inf;
                break;
            }
            sum += mn[p];
            vis[p] = 1;
            For(i, 0, n - 1) if(!vis[i] && w[p][i] && (((mask >> p) & 1) || ((mask >> i) & 1))) mn[i] = min(mn[i], w[p][i]);
        }
        res = min(res, sum);
    }
    printf("%lld\n", res);
}
