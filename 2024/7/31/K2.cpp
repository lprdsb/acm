#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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

#define maxn 1000
int n, a[maxn + 5];
LL f[maxn + 5][maxn + 5][75], bas = 30;
int g[maxn + 5][maxn + 5][75];

LL dfs(int l, int r, int c) {
    if(abs(c) > bas) return Inf;
    if(g[l][r][c + bas]) return f[l][r][c + bas];
    assert(l < r);
    // g[l][r][c + bas] = 1;
    int L = l + 1, R = r;
    // cout << l << " " << r << endl;
    while(L < R) {
        int md = L + R >> 1;
        if(dfs(l, md - 1, c - 1) + a[md] >= dfs(md, r, c + 1) - a[md]) R = md;
        else L = md + 1;
    }

    For(L1, max(l + 1, L - 1), min(r, L + 1)) {
        LL t1 = dfs(l, L1 - 1, c - 1), t2 = dfs(L1, r, c + 1);
        LL tem = (t2 - t1) / 2;
        tem = max(tem, a[L1 - 1] + 1ll);
        tem = min(tem, 1ll * a[L1]);
        For(tt, max(a[L1 - 1] + 1ll, tem - 1), min((LL)a[L1], tem + 1)) {
            LL ttt = max(t1 + tt, t2 - tt);
            if(!g[l][r][bas + c] || ttt < f[l][r][bas + c]) {
                f[l][r][bas + c] = ttt;
                g[l][r][bas + c] = 1;
            }
        }
    }

    // if(L)
    return f[l][r][bas + c];
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) For(j, -bas, bas) {
        f[i][i][bas + j] = 1ll * j * a[i];
        g[i][i][bas + j] = 1;
    }
    // cout << f[1][4][bas] << endl;
    printf("%lld\n", dfs(1, n, 0));
}
