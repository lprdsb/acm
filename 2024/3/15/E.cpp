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

int T, n, k;

int main() {
    //freopen("in", "r", stdin);、
    read(T);
    while(T--) {
        read(n); read(k);
        for(int i = 1; i <= n; i += k) {
            int l = i, r = min(l + k - 1, n);
            int len = r - l + 1;
            Rof(j, (len + 1) >> 1, 1) printf("%d ", i + j - 1);
            Rof(j, r, i + ((len + 1) >> 1)) printf("%d ", j);
        }
        printf("\n%d\n", (n - 1) / k + 1);
        for(int i = 1; i <= n; i += k) {
            int l = i, r = min(l + k - 1, n);
            For(j, l, r) printf("%d ", (i - 1) / k + 1);
        }
        puts("");
    }
}
