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
int T, n, a[maxn + 5], b[maxn + 5], sum[32], now[32];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), b[i] = a[i] ^ b[i - 1];
    For(i, 0, n) For(o, 0, 30) sum[o] += (b[i] >> o) & 1;
    LL res = 0;
    For(i, 1, n) {
        int mx = -1;
        For(o, 0, 30) if((a[i] >> o) & 1) mx = o;
        if(mx == -1) continue;
        res += 1ll * now[mx] * (sum[mx] - now[mx]) + 1ll * (i - now[mx]) * (n - i + 1 - (sum[mx] - now[mx]));
        For(o, 0, 30) now[o] += (b[i] >> o) & 1;
    }
    printf("%lld\n", res);
    For(o, 0, 30) sum[o] = now[o] = 0;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
