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

int T;
LL x;

void mian() {
    read(x);
    LL sq = sqrt(x), res = Inf;
    For(i, max(2ll, sq - 100), sq + 100) {
        int len = i - 1;
        if(len % 2 == 0) {
            if(x % 2 == 0) res = min(res, (x % len != 0) + x / len + i);
        }
        else {
            if((x % len) & 1) res = min(res, x / len + 1 + i);
            else res = min(res, x / len + 2 * (x % len != 0) + i);
        }
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
