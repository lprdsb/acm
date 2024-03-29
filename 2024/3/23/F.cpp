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
int n, k;
struct Node {
    int num[10];
} to[10][50], f[2][10];

int main() {
    //freopen("in", "r", stdin);
    int T; read(T); read(k);
    For(i, 0, 9) {
        int tem = i + k;
        while(tem) {
            to[i][0].num[tem % 10]++;
            tem /= 10;
        }
    }
    For(o, 1, 40) {
        For(i, 0, 9) For(j, 0, 9) For(p, 0, 9)
            to[i][o].num[j] = (to[i][o].num[j] + 1ll * to[i][o - 1].num[p] * to[p][o - 1].num[j] % mod) % mod;
    }
    while(T--) {
        LL x;
        read(n); read(x);
        int now = 0;
        memset(f, 0, sizeof f);
        For(i, 0, 9) f[now][i].num[i] = 1;
        // cout << f[now][3].num[0] << endl;
        Rof(o, 40, 0) if((x >> o) & 1) {
            For(i, 0, 9) For(j, 0, 9) For(p, 0, 9) f[now ^ 1][i].num[j] = (f[now ^ 1][i].num[j] + 1ll * f[now][i].num[p] * to[p][o].num[j] % mod) % mod;
            For(i, 0, 9) f[now][i] = {};
            now ^= 1;
        }
        int res = 0;
        while(n) {
            For(i, 0, 9) res = (1ll * res + f[now][n % 10].num[i]) % mod;
            n /= 10;
        }
        printf("%d\n", res);
    }
    return 0;
}
