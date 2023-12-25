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

#define maxn 100000
int T, n, a[maxn + 5][3], f[maxn + 5][8];

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
    read(T);
    while(T--) {
        read(n);
        For(o, 0, 2) For(i, 1, n) read(a[i][o]);
        For(i, 1, n) For(mask, 0, 7) {
            f[i][mask] = f[i - 1][mask];
            For(o, 0, 2) if((mask >> o) & 1) {
                f[i][mask] = max(f[i][mask], f[i - 1][mask ^ (1 << o)] + a[i][o]);
            }
        }
        // cout << f[2][2] << endl;
        printf("%d\n", f[n][7]);
    }
    return 0;
}
