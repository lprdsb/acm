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

int T;
LL n;

#define cc __builtin_popcountll

void mian() {
    read(n);
    int ok = 0;
    if(cc(n) & 1) {
        puts("second");
        fflush(stdout);
        LL x, y;
        while(666) {
            read(x); read(y);
            if(!x) return;
            if(x < 0) exit(0);
            if(cc(x) & 1) swap(x, y);
            LL tem = 1;
            while((tem << 1) <= x) tem <<= 1;
            ok++;
            assert(ok <= 63);
            printf("%lld %lld\n", tem, x - tem);
            fflush(stdout);
        }
    }
    else {
        puts("first");
        fflush(stdout);
        LL x = n, y;
        LL tem = 1;
        while((tem << 1) <= x) tem <<= 1;
        ok++;
        printf("%lld %lld\n", tem, x - tem);
        fflush(stdout);
        while(666) {
            read(x); read(y);
            if(!x) return;
            if(x < 0) exit(0);
            if(cc(x) & 1) swap(x, y);
            LL tem = 1;
            while((tem << 1) <= x) tem <<= 1;
            ok++;
            assert(ok <= 63);
            printf("%lld %lld\n", tem, x - tem);
            fflush(stdout);
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
