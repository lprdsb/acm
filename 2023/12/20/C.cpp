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

#define maxn 200000
int T, n, k, a[maxn + 5], b[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n); read(k);
        For(i, 1, n) read(a[i]);
        For(i, 1, n) read(b[i]);
        LL res = 0, sum = 0, mx = 0;
        For(i, 1, n) if(i <= k) {
            sum += a[i];
            mx = max(mx, 1ll * b[i]);
            res = max(res, sum + (k - i) * mx);
        }
        printf("%lld\n", res);
    }
}
