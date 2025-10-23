#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long

#define P 998244353

int fp(LL x, LL y) {
    x %= P;
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }
LL G(LL a, LL b, LL c, LL d) {
    if(b > d) swap(a, c), swap(b, d);
    if(gcd(a, c) == 1 || !b || !d) return 1;
    // cout << a << " " << b << " " << c << " " << d << endl;
    LL res = 1, gc = gcd(a, c);
    return 1ll * fp(gc, b) * G(a / gc, b, gc, d - b) % P;
}

int T;
LL a, b, c, d;


void mian() {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    printf("%lld\n", G(a, b, c, d));
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}