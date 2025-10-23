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

#define P 1000000007

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

#define maxn 200000
int n, a[4], fac[maxn + 5], ifac[maxn + 5];

int c(int x, int y) { return 1ll * fac[x] * ifac[y] % P * ifac[x - y] % P; }

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    ifac[maxn] = fp(fac[maxn], P - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
    read(n);
    For(i, 1, n) {
        int x; read(x);
        a[(x + 1) % 4]++;
    }
    // cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
    int tem = 0;
    for(int i = 1; i <= a[3]; i += 2) tem = (1ll * tem + c(a[3], i)) % P;
    // cout << c(5, 2) << endl;
    int res = (1ll * fp(2, a[1]) * tem % P - 1 + P) % P;
    printf("%d\n", res);
}
