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

int T, n, b, x;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

map<int, int> ma;
void mian() {
    int mx = 0;
    read(n); read(b); read(x);
    For(i, 1, n) {
        int t; read(t);
        ma[t]++;
        mx = max(mx, t);
    }
    LL res = 0;
    For(i, 1, mx) {
        LL sum = -1ll * x * (i - 1);
        for(auto [k, v] : ma) {
            LL tem1 = k % i, tem2 = i - tem1, tem3 = k / i;
            sum += v * b * (tem3 * tem3 * tem2 * (tem2 - 1) / 2 + (tem3 + 1) * (tem3 + 1) * tem1 * (tem1 - 1) / 2 + tem3 * (tem3 + 1) * tem1 * tem2);
        }
        res = max(res, sum);
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        ma.clear();
    }
}
