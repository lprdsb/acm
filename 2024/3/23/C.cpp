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

#define maxn 200000
int n, x, bas = maxn, a[maxn + 5];
bitset<2 * maxn + 5> f[3];

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        read(n); read(x);
        For(i, 1, n) read(a[i]); a[n + 1] = 0;
        f[0] = f[1] = f[2] = 0;
        int o = 0;
        f[o][bas] = 1;
        int fl = 0;
        For(i, 0, n) {
            int to1 = o + 1, to2 = o + 2;
            if(to1 >= 3) to1 -= 3;
            if(to2 >= 3) to2 -= 3;
            if(a[i + 1] == 1) f[to1] |= f[o] << 1;
            else if(a[i + 1] == -1) f[to1] |= f[o] >> 1;
            else fl |= f[o][bas + x];
            if(a[i + 2] == 1) f[to2] |= f[o] << 1;
            else if(a[i + 2] == -1) f[to2] |= f[o] >> 1;
            else fl |= f[o][bas + x];
            f[o] = 0;
            o = to1;
        }
        puts(fl ? "Yes" : "No");
    }
}
