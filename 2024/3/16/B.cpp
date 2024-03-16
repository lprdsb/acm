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
int T, n, m;
int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

void mian() {
    read(n); read(m);
    int res = 1;
    For(i, 2, n) {
        if(i * i > n) break;
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            res = 1ll * res * (fp(cnt + 1, m) - fp(cnt, m) + mod) % mod;
        }
    }
    if(n != 1) res = 1ll * res * (fp(2, m) - 1) % mod;
    printf("%d\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
