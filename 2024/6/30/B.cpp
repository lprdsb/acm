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

#define maxn 100000
int n, a[maxn + 5];
LL sum = 0;
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    int mx = 0, mmx = 0;
    sum = 0;
    For(i, 1, n) {
        mx = max(mx, a[i]);
        sum += mx - a[i];
        mmx = max(mmx, mx - a[i]);
    }
    printf("%lld\n", sum + mmx);
}

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
