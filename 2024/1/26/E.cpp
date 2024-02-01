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

LL n, k;

LL get_phi(LL x) {
    LL res = x;
    For(i, 2, x) {
        if(1ll * i * i > x) break;
        if(x % i == 0) {
            res /= i;
            res *= i - 1;
            while(x % i == 0) x /= i;
        }
    }
    if(x != 1) res /= x, res *= x - 1;
    return res;
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(k);
    n = get_phi(n);
    for(LL i = 3; i <= k; i += 2) {
        n = get_phi(n);
        if(n <= 1) break;
    }
    printf("%lld\n", n % 1000000007);
}
