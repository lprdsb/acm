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

LL exgcd(LL a, LL &x, LL b, LL &y, LL c) {
    if(!b) {
        x = c / a;
        y = 0;
        return a;
    }
    LL xx, yy, gc = exgcd(b, xx, a % b, yy, c);
    x = yy;
    y = xx - a / b * yy;
    return gc;
}
int T;
LL n, m, a, b, c;


void mian() {
    read(n); read(m); read(a); read(b); read(c);
    if(a > b) swap(n, m), swap(a, b);
    LL x0, y0, gc = exgcd(a, x0, b, y0, c);
    if(c % gc) {
        printf("%lld\n", n + m);
        return;
    }
    LL t1 = b / gc, t2 = a / gc;
    LL tem = ((x0 % t1 + t1) % t1 - x0) / t1;
    x0 += tem * t1; y0 -= tem * t2;
    if(y0 > m) {
        tem = (y0 - m + t2 - 1) / t2;
        x0 += tem * t1; y0 -= tem * t2;
    }
    if(x0 > n || y0 > m || y0 < 0) {
        printf("%lld\n", n + m);
        return;
    }
    vector<LL> vec;
    For(i, x0, n) {
        LL now = n / (i + eps), to = n / now;
        vec.pb((to - x0) / t1);
        i = to;
    }
    For(i, 0, y0) {
        LL now = m / (i + eps), to = m / now;
        vec.pb((y0 - i) / t2);
        i = to;
    }
    LL r = min((n - x0) / t1, y0 / t2);
    LL res = n + m;
    for(auto k : vec) {
        k = min(k, r);
        k = max(k, 0ll);
        if(x0 + t1 * k == 0 || y0 - t2 * k == 0) continue;
        assert(x0 + t1 * k >= 0 && y0 - t2 * k >= 0);
        assert(x0 + t1 * k <= n && y0 - t2 * k <= m);
        // assert(k >= 0);
        res = min(res, n + m - (x0 + y0 + k * (t1 - t2)) * min(n / (x0 + t1 * k), m / (y0 - t2 * k)));
    }
    if(c % a == 0) res = min(res, n + m - c / a * (n / (c / a)));
    if(c % b == 0) res = min(res, n + m - c / b * (m / (c / b)));
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
