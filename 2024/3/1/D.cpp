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
LL x, y;

void mian() {
    read(x); read(y);
    LL tem = 0;
    int fl = 0;
    Rof(o, 62, 0) {
        if(((x >> o) & 1) && !((y >> o) & 1)) {
            if(fl) {
                printf("2\n%lld ", x);
                x = tem | (((1ll << o) - 1) & y);
                printf("%lld %lld\n", x, y);
                return;
            }
            tem |= 1ll << o;
            fl = 1;
        }
        if(((x >> o) & 1) && ((y >> o) & 1)) {
            printf("1\n%lld %lld\n", x, y);
            return;
        }
        if(!((x >> o) & 1) && ((y >> o) & 1)) {
            puts("-1");
            return;
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
