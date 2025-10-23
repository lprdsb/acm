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
    if((n & -n) == n) {
        printf("%d\n", 2 * n - 1);
        For(i, 1, n - 3) if(i != 1 && i != 3) printf("%d ", i);
        printf("%d %d %d %d %d\n", 1, 3, n - 2, n - 1, n);
    }
    else {
        int tmp = 1;
        while(2 * tmp <= n) tmp <<= 1;
        if(n % 2 == 1) {
            printf("%d\n", n);
            if(n != tmp + 1) {
                For(i, 1, n - 3) if(i != tmp - 1) printf("%d ", i);
                printf("%d %d %d %d\n", n - 2, n - 1, tmp - 1, n);
            }
            else {
                For(i, 1, n - 2) if(i != 1 && i != 3) printf("%d ", i);
                printf("%d %d %d %d\n", 1, 3, n - 1, n);
            }
        }
        else {
            printf("%d\n", (tmp << 1) - 1);
            For(i, 1, n) if(i != tmp && i != tmp - 1 && i != tmp + 1) printf("%d ", i);
            printf("%d %d %d\n", tmp, tmp + 1, tmp - 1);
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
