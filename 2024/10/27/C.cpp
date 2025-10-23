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

#define maxn 500
LL f[maxn * maxn + 5], n;
LL v;

int main() {
    memset(f, inf, sizeof f);
    //freopen("in", "r", stdin);
    f[0] = 0;
    read(n); read(v);
    For(i, 1, n) {
        LL vi, wi; read(vi); read(wi);
        Rof(j, maxn * maxn, wi) f[j] = min(f[j], f[j - wi] + vi);
    }
    int res = 0;
    For(i, 0, maxn * maxn) if(f[i] <= v) res = max(res, i);
    printf("%d\n", res);
}
