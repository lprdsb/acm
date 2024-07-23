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

#define maxn 3000
int n, m;
DD f[maxn + 5], g[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 0, m) f[i] = inf;
    f[1] = 1;
    For(i, 0, n - 2) {
        For(j, 0, m) g[j] = inf;
        For(j, 0, m - 1) {
            // if(i >= n - 30) {
            For(p, 1, min(m - j, (m - j) / (n - i - 1))) g[j + p] = min(g[j + p], f[j] + (DD)2 * (j + p) / p - 1);
            // }
            // else g[j + 1] = f[j] + (DD)2 * (j + 1) / 1 - 1;
        }
        For(i, 0, m) f[i] = g[i];
    }
    DD res = inf;
    For(i, 0, m) res = min(res, f[i]);
    printf("%.10lf\n", res);
}
