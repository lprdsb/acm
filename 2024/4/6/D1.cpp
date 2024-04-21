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
    LL n, k; read(n); read(k);
    if(n == k) {
        puts("YES\n1\n1");
    }
    else if(n % 2) {
        if(k <= (n + 1) / 2) {
            printf("YES\n2\n%lld 1\n", n - k + 1);
        }
        else puts("NO");
    }
    else {
        if(k < n / 2) {
            printf("YES\n2\n%lld 1\n", n - k + 1);
        }
        else if(k == n / 2) printf("YES\n1\n2\n");
        else puts("NO");
    }
}

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
