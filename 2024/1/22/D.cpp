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

int n, p, m;

int main() {
    //freopen("in", "r", stdin);
    read(n); read(p); read(m);
    LL now = 0, pre = 1, res = 0;
    For(i, 1, n) {
        int x, y; read(x); read(y);
        res += min(x - pre, max(0ll, now / p));
        now -= (x - pre) * p; pre = x;
        now += y;
    }
    res += min(m + 1 - pre, max(0ll, now / p));
    // cout << res << endl;
    printf("%d\n", m - res);
}
