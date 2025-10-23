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
#define P 998244353

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}
int T, n, a[2][maxn + 5], b[2][maxn + 5];
map<int, int> ma[2];


void mian() {
    read(n); int q; read(q);
    For(o, 0, 1) {
        For(i, 1, n) read(a[o][i]), b[o][i] = a[o][i];
        sort(b[o] + 1, b[o] + n + 1);
        For(i, 1, n) ma[o][b[o][i]] = i;
    }
    int res = 1;
    For(i, 1, n) res = 1ll * res * min(b[0][i], b[1][i]) % P;
    printf("%d ", res);
    while(q--) {
        int o, x; read(o); read(x); o--;
        int t = ma[o][a[o][x]];
        res = 1ll * res * fp(min(b[0][t], b[1][t]), P - 2) % P;
        if(b[o][t - 1] == a[o][x]) ma[o][a[o][x]]--;
        else ma[o].erase(a[o][x]);
        b[o][t]++;
        a[o][x]++;
        if(ma[o].find(a[o][x]) == ma[o].end()) ma[o][a[o][x]] = t;

        res = 1ll * res * min(b[0][t], b[1][t]) % P;
        printf("%d ", res);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(o, 0, 1) ma[o].clear();
    }
}
