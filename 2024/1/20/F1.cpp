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

#define mod 1000000007
#define maxn 1000

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int n, a[maxn + 5], cnt[3] = { 0, 0, 0 };
int f[maxn + 5][maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]), cnt[a[i]]++;
    f[0][0] = 0;
    For(i, 1, n) {
        f[i][0] = 1;
        Rof(j, i - 1, 0) {
            int tem = fp(i, mod - 2);
            f[j][i - j] = (f[j][i - j] + 1ll * j * (1ll - f[j - 1][i - j] + mod) % mod * tem % mod);
            if(i - j) f[j][i - j] = (f[j][i - j] + 1ll * (i - j) * (1ll - f[j + 1][i - j - 1] + mod) % mod * tem % mod) % mod;
        }
    }
    // cout << f[0][1] << endl;
    printf("%d\n", f[cnt[1]][cnt[2]]);
}
