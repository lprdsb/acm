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

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        int n; read(n);
        if(n == 1) puts("1\n1");
        else if(n == 2) puts("2\n1 2");
        else if(n == 3) puts("2\n1 2 2");
        else if(n == 4) puts("3\n1 2 2 3");
        else if(n == 5) puts("3\n1 2 2 3 3");
        else {
            puts("4");
            For(i, 1, n) printf("%d ", i % 4 + 1);
            puts("");
        }
    }
}
