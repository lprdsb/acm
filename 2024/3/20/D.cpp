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
int pri[maxn + 5], miu[maxn + 5], vis[maxn + 5], cnt = 0, n, k;

LL sol(int a, int b) {
    a /= k; b /= k;
    if(!a || !b) return 0;
    LL res = 0;
    For(i, 1, min(a, b)) {
        int na = a / i, nb = b / i, ta = a / na, tb = b / nb;
        res += 1ll * (miu[min(ta, tb)] - miu[i - 1]) * na * nb;
        i = min(ta, tb);
    }
    return res;
}

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    //freopen("in", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i, miu[i] = -1;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
            else miu[i * pri[j]] = -miu[i];
        }
    }
    miu[1] = 1;
    For(i, 1, maxn) miu[i] += miu[i - 1];
    read(n);
    For(_, 1, n) {
        int a, b, c, d; read(a); read(b); read(c); read(d); read(k);
        LL res = sol(b, d) - sol(a - 1, d) - sol(b, c - 1) + sol(a - 1, c - 1);
        // LL sum = 0;
        // For(i, a, b) For(j, c, d) sum += gcd(i, j) == k;
        printf("%lld\n", res);
    }
    return 0;
}
