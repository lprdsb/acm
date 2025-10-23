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

#define maxn 5000
#define maxm 500000

int T, n, m, f[2 * maxn + 5][maxn + 5], v[2 * maxm + 5], d[maxn + 5];
// vector<int> ch[maxn + 5];
int *ch[maxn + 5], *ch1[maxn + 5];

pair<int, int> e[maxm + 5];

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        // ch[u].pb(v);
        // ch[v].pb(u);
        e[i] = { u, v };
        d[u]++;
        d[v]++;
    }
    int sd = 0;
    For(i, 1, n) {
        ch[i] = ch1[i] = v + sd;
        sd += d[i];
    }
    For(i, 1, m) {
        int u = e[i].fir, v = e[i].sec;
        *ch1[u] = v; ch1[u]++;
        *ch1[v] = u; ch1[v]++;
    }
    int up = 2 * n;
    For(i, 0, up) For(j, 0, n) f[i][j] = inf;
    f[0][1] = 0;
    For(i, 0, up) For(j, 1, n) if(f[i][j] != inf) {
        int h = d[j];
        for(int p = 0; p < h; ++p) {
            int v = ch[j][p], t = (p - f[i][j]) % h;
            if(t < 0) t += h;
            t++;
            f[i + 1][v] = min(f[i + 1][v], f[i][j] + t);
        }
    }
    // cout << "asd" << endl;
    int res = inf;
    For(i, 0, up) res = min(res, f[i][n]);
    Rof(i, up, 0) if(f[i][n] == res) {
        printf("%d %d\n", f[i][n], f[i][n] - i);
        return;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            d[i] = 0;
        }
    }
}
