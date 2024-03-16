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
        int n, k;
        read(n); read(k);
        For(i, 1, k - 3) printf("1 ");
        n -= k - 3;
        k = 3;
        if(n & 1) {
            printf("1 ");
            printf("%d %d\n", (n - 1) / 2, (n - 1) / 2);
        }
        else {
            int tem = (n & -n);
            if(tem == n) printf("%d %d %d\n", n / 2, n / 4, n / 4);
            else printf("%d %d %d\n", tem, (n - tem) / 2, (n - tem) / 2);
        }
    }
}
