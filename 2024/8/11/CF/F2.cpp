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

#define maxn 20000000
int vis[maxn + 5], pri[maxn + 5], cnt = 0, T, n, m, a, b, f[205][205], B = 150;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int gc[205][205];
void mian() {
    read(n); read(m); read(a); read(b);
    int t1 = max(n - B, 0), t2 = max(m - B, 0);
    For(i, 0, n - t1) For(j, 0, m - t2) {
        if(t1 + i == 0 && t2 + j == 0) f[i][j] = 1;
        if(t1 + i != t2 + j && !vis[t1 + i] && !vis[t2 + j]) f[i][j] = 1;
        gc[i][j] = gcd(t1 + i, t2 + j);
    }
    LL res = 0;
    For(i, 0, n - t1) For(j, 0, m - t2) if(f[i][j]) {
        f[i + 1][j] |= gc[i + 1][j] == 1;
        f[i][j + 1] |= gc[i][j + 1] == 1;
        res = max(res, 1ll * a * (t1 + i) + 1ll * b * (t2 + j));
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && 1ll * i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    read(T);
    while(T--) {
        mian();
        For(i, 0, B) For(j, 0, B) f[i][j] = 0;
    }
}
