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

int T, n;
LL k;
map<LL, int> ma;
void mian() {
    read(n); read(k);
    For(i, 1, n) {
        LL x; read(x);
        ma[x]++;
    }
    int now = 0;
    LL pre = 0;
    for(auto [kk, vv] : ma) {
        if(k >= (kk - pre) * now) {
            k -= (kk - pre) * now;
            pre = kk;
            now += vv;
        }
        else break;
    }
    LL mx = pre + k / now;
    int cnt = n - (now - k % now);
    if(cnt == n) cnt = 0;
    printf("%lld\n", n * mx + cnt - n + 1);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        ma.clear();
    }
}
