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

#define maxn 5000
int T, n, a[maxn + 5];
LL f[maxn + 5];
LL ma[2 * maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    memset(f, inf, sizeof f);
    memset(ma, -1, sizeof ma);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) {
            char c; cin >> c;
            a[i] = c == '+' ? 1 : -1;
        }
        For(i, 1, n) a[i] += a[i - 1];
        f[0] = 0;
        LL las = 0;
        ma[maxn] = 0;
        For(i, 1, n) {
            if(ma[maxn + a[i]] != -1) f[i] = ma[maxn + a[i]];
            f[i] = min(f[i], 1ll * i + las);
            if(ma[maxn + a[i]] == -1 || ma[maxn + a[i]] > f[i]) ma[maxn + a[i]] = f[i];
            las = min(las, f[i] - i);
        }
        printf("%lld\n", f[n]);
        For(i, 1, n) f[i] = Inf;
        For(i, -maxn, maxn) ma[maxn + i] = -1;
    }
    return 0;
}
