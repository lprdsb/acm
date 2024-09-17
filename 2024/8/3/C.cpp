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

#define maxn 500000
int T, n, a[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    if(n == 1) {
        printf("%lld\n", (1ll << a[1]) - 1);
        return;
    }
    int mx = 0;
    For(i, 2, n) if(!mx || a[i - 1] - a[i] > a[mx - 1] - a[mx]) mx = i;
    int o = (a[mx - 1] - a[mx] + 1);
    LL res = (1ll << (a[mx - 1] - a[mx] + 1)) - (mx - 1);
    For(i, 2, a[mx]) {
        res |= 1ll << (o + 1);
        o++;
    }
    For(i, 0, n - 1) if(__builtin_popcountll(res + i) != a[i + 1]) {
        puts("-1");
        return;
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
