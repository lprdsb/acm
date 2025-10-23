#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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

LL T, x, y, z, k;

void mian() {
    LL res = Inf, now = 0, d = 0;
    x = 1; y = 1; z = 100000000; k = 100000000;
    read(x); read(y); read(z); read(k);
    if(k <= 10000) {
        while(z > 0) {
            if(z <= d) {
                res = min(res, now + y);
                break;
            }
            For(i, 1, k) {
                res = min(res, now + 1ll * (z + d + i - 1) / (d + i) * y + 1ll * i * x);
            }
            now += x * k + y;
            d += k;
            z -= d;
        }
    }
    else {
        while(z > 0) {
            // cout << z << endl;
            For(i, d + 1, d + k) {
                LL tmp = z / i;
                For(o, -1, 0) if(i + o <= d + k && i + o > d) {
                    res = min(res, now + 1ll * (z + i + o - 1) / (i + o) * y + 1ll * (i + o - d) * x);
                }
                if(!tmp) break;
                i = z / tmp;
            }
            // For(i, d + k, d + k) {
            //     res = min(res, now + 1ll * (z + i - 1) / (i)*y + 1ll * (i - d) * x);
            // }
            now += x * k + y;
            d += k;
            z -= d;
            res = min(res, now + (z + d - 1) / d * y);
        }
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    T = 100;
    read(T);
    while(T--) {
        mian();
    }
}
