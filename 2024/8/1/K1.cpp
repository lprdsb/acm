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
int n, a[maxn + 5], f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], h[maxn + 5];

int main() {
    freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    memset(f, inf, sizeof f); f[0][0] = 0;
    For(i, 1, n) For(j, 1, n) {
        int mx = 0, mn = inf;
        Rof(p, i, 1) {
            mx = max(mx, a[p]);
            mn = min(mn, a[p]);
            if(f[i][j] > f[p - 1][j - 1] + mx - mn) {
                f[i][j] = f[p - 1][j - 1] + mx - mn;
                g[i][j] = p;
            }
        }
    }
    // For(j, 1, n) {
    //     For(i, 1, n) cout << g[i][j] << " ";
    //     cout << endl;
    // }
    For(i, 1, n) cout << f[n][i] << endl;
}
