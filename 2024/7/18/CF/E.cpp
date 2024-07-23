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

int k, n, num[30];
void mian() {
    read(k);
    For(i, 1, k) {
        read(n);
        For(j, 1, n - 1) {
            int x; read(x);
        }
        For(o, 0, 20) num[o] += (n >> o) & 1;
    }
    int res = 0;
    Rof(o, 20, 0) {
        if(num[o] == 1) res |= 1 << o;
        if(num[o] >= 2) {
            res |= (1 << (o + 1)) - 1;
            break;
        }
    }
    printf("%d\n", res);
    For(o, 0, 20) num[o] = 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
