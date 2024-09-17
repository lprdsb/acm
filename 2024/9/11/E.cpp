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

#define mod 10007
#define maxn 30000

int n, m, a[maxn + 5], b[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 0, n) read(a[i]);
    read(m);
    For(i, 0, m) read(b[i]);
    int q; read(q);
    while(q--) {
        int x, y; read(x); read(y);
        int s1 = 0, s2 = 0;
        int tx = 1, ty = 1;
        For(i, 0, n) {
            s1 = (s1 + 1ll * tx * a[i] % mod) % mod;
            tx = 1ll * tx * x % mod;
        }

        For(i, 0, m) {
            s2 = (s2 + 1ll * ty * b[i] % mod) % mod;
            ty = 1ll * ty * y % mod;
        }
        printf("%d\n", 1ll * s1 * s2 % mod);
    }
}
