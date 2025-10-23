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

#define maxn 1000000
int n, q, a[maxn + 5];

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
    read(n); read(q);
    For(i, 1, n) {
        int x; read(x);
        a[x]++;
    }
    For(i, 1, maxn + 1) a[i] += a[i - 1];
    while(q--) {
        int x, y; read(x); read(y);
        int r = x * (y + 1) - 1, l = x * y - 1;
        r = min(r, maxn + 1); r = max(r, 0);
        l = min(l, maxn + 1); l = max(l, 0);
        printf("%d\n", a[r] - a[l]);
    }
    return 0;
}
