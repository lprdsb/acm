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

#define maxn 200000
int T, n, a[maxn + 5], b[2 * maxn + 5];
LL f[2 * maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), b[i] = a[i];
    LL res = Inf;
    For(o, 1, 3) {
        For(i, 1, n) b[i] = a[(o + i - 2 + n) % n + 1];
        f[0] = 0;
        For(i, 1, n) {
            f[i] = Inf;
            if(i >= 2) f[i] = min(f[i], f[i - 2] + abs(b[i] - b[i - 1]));
            if(i >= 3) f[i] = min(f[i], f[i - 3] + max(b[i], max(b[i - 1], b[i - 2])) - min(b[i], min(b[i - 1], b[i - 2])));
        }
        res = min(res, f[n]);
    }
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
