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

#define maxn 300000
int n, m;
char s[maxn + 5];
#define mod 998244353

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    scanf("%s", s + 1);
    int res = 1;
    For(i, 2, n - 1) if(s[i] == '?') res = 1ll * res * (i - 1) % mod;
    printf("%d\n", (s[1] != '?') * res);
    For(i, 1, m) {
        int p; char c; cin >> p >> c;
        if(s[p] == '?' && p != 1) res = 1ll * res * fp(p - 1, mod - 2) % mod;
        s[p] = c;
        if(s[p] == '?' && p != 1) res = 1ll * res * (p - 1) % mod;
        printf("%d\n", (s[1] != '?') * res);
    }
    return 0;
}
