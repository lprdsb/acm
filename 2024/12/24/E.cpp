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
    int n, m; read(n); read(m);
    if(m >= 2 * n) puts("NO");
    else {
        puts("YES");
        For(i, 1, 2 * n) {
            For(j, 1, m) printf("%d ", (i + j) % (2 * n) / 2 + 1);
            puts("");
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
