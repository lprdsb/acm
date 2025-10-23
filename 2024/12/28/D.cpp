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

#define maxn 20000
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
int T, n, a[2][maxn + 5], id[2][maxn + 5], to[2][maxn + 5];


void mian() {
    read(n); int q; read(q);
    For(o, 0, 1) For(i, 1, n) read(a[o][i]);
    For(o, 0, 1) {
        For(i, 1, n) id[o][i] = i;
        sort(id[o] + 1, id[o] + n + 1, [&](int x, int y) {return a[o][x] < a[o][y];});
        For(i, 1, n) to[o][id[o][i]] = i;
    }
    int res = 1;
    For(i, 1, n) res = 1ll * res * min(a[0][id[0][i]], a[1][id[1][i]]) % P;
    printf("%d ", res);
    while(q--) {
        int o, x; read(o); read(x); o--;
        int fl = 0;
        while(666) {
            int t = to[o][x];
            res = 1ll * res * fp(min(a[0][id[0][t]], a[1][id[1][t]]), P - 2) % P;
            if(!fl) {
                fl = 1;
                a[o][x]++;
            }
            int ok = 0;
            if(t + 1 <= n) {
                int k = t + 1;
                res = 1ll * res * fp(min(a[0][id[0][k]], a[1][id[1][k]]), P - 2) % P;
                if(a[o][x] + 1 > a[o][id[o][k]]) {
                    ok = 1;
                    swap(to[o][id[o][k - 1]], to[o][id[o][k]]);
                    swap(id[o][k - 1], id[o][k]);
                }
                res = 1ll * res * min(a[0][id[0][k]], a[1][id[1][k]]) % P;
            }
            res = 1ll * res * min(a[0][id[0][t]], a[1][id[1][t]]) % P;
            if(!ok) break;
        }
        printf("%d ", res);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
