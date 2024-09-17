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

#define maxn 20
int T, n, m, a[maxn + 5][maxn + 5], w[maxn + 5][maxn + 5], b[maxn + 5][maxn + 5];

int res = inf, f[1 << 17][25], g[25][25];

void chkmn(int &x, int y) {
    if(x > y) x = y;
}
void sol(int N) {
    // cout << (1 << (N + 1)) - 1 << " " << (1 << 16) - 1 << endl;
    For(i, 0, (1 << (N + 1)) - 1) For(j, 1, N) f[i][j] = inf;
    // cout << N << endl;
    For(i, 1, N) f[(1 << (i - 1))][i] = 0;
    For(i, 0, (1 << N) - 2) For(j, 1, N) if(f[i][j] != inf) {
        For(p, 1, N) if(!((i >> (p - 1)) & 1)) chkmn(f[i | (1 << (p - 1))][p], f[i][j] + w[j][p]);
    }
}

void mian() {
    read(n); read(m);
    For(i, 1, n) For(j, 1, m) read(a[i][j]);
    For(i, 1, n) {
        a[i][m + 1] = 0;
        For(j, 1, m) a[i][m + 1] ^= a[i][j];
    }
    For(i, 1, m + 1) {
        a[n + 1][i] = 0;
        For(j, 1, n) a[n + 1][i] ^= a[j][i];
    }
    For(o, 1, m + 1) {
        // cout << o << endl;
        For(i, 1, n + 1) For(j, 1, n + 1) if(i != j) {
            w[i][j] = 0;
            For(p, 1, m + 1) if(p != o) w[i][j] += abs(a[i][p] - a[j][p]);
        }
        sol(n + 1);
        // cout << o << endl;
        For(i, 1, n + 1) {
            int tem = inf;
            For(j, 1, n + 1) if(j != i) chkmn(tem, f[(1 << (n + 1)) - 1 - (1 << (i - 1))][j]);
            g[i][o] += tem;
        }
    }

    For(o, 1, n + 1) {
        For(i, 1, m + 1) For(j, 1, m + 1) if(i != j) {
            w[i][j] = 0;
            For(p, 1, n + 1) if(p != o) w[i][j] += abs(a[p][i] - a[p][j]);
        }
        sol(m + 1);
        For(i, 1, m + 1) {
            int tem = inf;
            For(j, 1, m + 1)  if(j != i) chkmn(tem, f[(1 << (m + 1)) - 1 - (1 << (i - 1))][j]);
            g[o][i] += tem;
        }
    }
    res = inf;
    For(i, 1, n + 1) For(j, 1, m + 1) chkmn(res, g[i][j]);
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + 1) For(j, 1, m + 1) g[i][j] = 0;
    }
}
