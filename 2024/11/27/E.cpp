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

LL a, b;

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

int main() {
    //freopen("in", "r", stdin);
    read(a); read(b);
    LL x, y, gc = exgcd(a, x, b, y, 1);
    x = (x % b + b) % b;
    printf("%lld\n", x);
}
