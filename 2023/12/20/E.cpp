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

#define maxn 200000
int T, n, a[maxn + 5], b[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int ind[maxn + 5];
int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) ind[i] = i;
        For(i, 1, n) read(a[i]);
        For(i, 1, n) read(b[i]);
        sort(ind + 1, ind + n + 1, [](cst int &_x, cst int &_y) {return a[_x] + b[_x] > a[_y] + b[_y];});
        LL res = 0;
        For(i, 1, n) {
            res -= b[ind[i]];
            if(i & 1) res += a[ind[i]] + b[ind[i]] - 1;
            else res += 1;
        }
        printf("%lld\n", res);
    }
    return 0;
}
