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

void mian() {
    int n; read(n);
    if(n == 1) puts("-1");
    else if(n == 2) puts("66");
    else if(n == 3) puts("-1");
    else {
        if(n % 2 == 0) {
            For(i, 1, n - 2) printf("3");
            puts("66");
        }
        else {
            For(i, 1, n - 5) printf("3");
            puts("36366");
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
