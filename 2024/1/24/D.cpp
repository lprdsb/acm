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

#define mod 998244353

int T;
LL n;

int fp(int x, LL y) {
    y %= (mod - 1);
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

map<LL, pair<int, int> > ma;
void sol(LL len) {
    if(ma.count(len)) return;
    if(len == 1) {
        ma[len] = { 1, 0 };
        return;
    }
    pair<int, int> pa = { 0, 0 };
    LL ls, rs = len >> 1;
    ls = len - rs;
    sol(ls); sol(rs);
    pa.fir = (2ll * ma[ls].fir + 2ll * ma[rs].fir) % mod;
    pa.sec = (1ll * ma[ls].sec + ma[rs].fir + ma[rs].sec) % mod;
    pa.fir = (1ll * pa.fir + fp(2, len) - fp(2, ls) - fp(2, rs) + 1 + 2ll * mod) % mod;
    ma[len] = pa;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        sol(n);
        printf("%d\n", (ma[n].fir + ma[n].sec) % mod);
    }
    return 0;
}
