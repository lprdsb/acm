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

#define maxn 100000
int n, x[maxn + 5], y[maxn + 5];
void mian() {
    read(n);
    For(i, 1, n) read(x[i]), read(y[i]);
    For(i, 2, n) x[i] -= x[1], y[i] -= y[1];
    For(i, 3, n) {
        if(1ll * x[2] * y[i] - 1ll * y[2] * x[i] != 0) {
            puts("how?");
            return;
        }
    }
    puts("boo how! boo how!");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
