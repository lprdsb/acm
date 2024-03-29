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

LL n, k;

LL sol(LL l, LL r) {
    if(r > n) r = n;
    if(l > r) return 0;
    if(r == n) return r - l + 1;
    return r - l + 1 + sol(l << 1, r << 1 | 1);
}

bool chk(LL x) {
    LL res = sol(x, x);
    if(!(x & 1)) res += sol(x + 1, x + 1);
    return res >= k;
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(k);
    LL l = 1, r = (n >> 1) + 10;
    while(l < r) {
        LL md = l + r >> 1;
        if(!chk(md * 2)) r = md;
        else l = md + 1;
    }
    LL res = 2 * (l - 1);

    l = 1, r = (n >> 1) + 10;
    while(l < r) {
        LL md = l + r >> 1;
        if(!chk(md * 2 - 1)) r = md;
        else l = md + 1;
    }
    res = max(res, 2 * (l - 1) - 1);
    printf("%lld\n", res);
    return 0;
}
