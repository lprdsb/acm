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

#define mod 998244353
#define maxn 300
int n, m, k, du[maxn + 5];
struct Mat {
    int a[maxn + 5][maxn + 5];
} tra, mul;
Mat operator * (cst Mat x, cst Mat y) {
    Mat res = {};
    For(i, 1, maxn) For(j, 1, maxn) {
        int tem = x.a[i][j];
        For(p, 1, maxn) {
            res.a[i][p] += 1ll * tem * y.a[j][p] % mod;
            if(res.a[i][p] >= mod) res.a[i][p] -= mod;
        }
    }
    return res;
}

#define maxm 100000
pair<int, int> edge[maxm + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, m) {
        int u, v; read(u); read(v); edge[i] = { u, v };
        du[u]++; du[v]++;
    }
    For(i, 1, m) {
        int u = edge[i].fir, v = edge[i].sec;
        tra.a[u][v]++; tra.a[v][u]++;
        tra.a[n + u][v] += 1 - du[u]; tra.a[n + v][u] += 1 - du[v];
    }
    For(i, 1, n) {
        tra.a[i][2 * n + i] = 1;
        tra.a[n + i][2 * n + i] = 1 - du[i];
        tra.a[2 * n + i][n + i] = 1;
    }
    // For(i, 1, 3 * n) {
    //     For(j, 1, 3 * n) cout << tra.a[i][j] << " ";
    //     cout << endl;
    // }
    For(i, 1, 3 * n) For(j, 1, 3 * n) {
        if(tra.a[i][j] >= mod) tra.a[i][j] -= mod;
        if(tra.a[i][j] < 0) tra.a[i][j] += mod;
    }
    For(i, 1, 3 * n) mul.a[i][i] = 1;
    while(k) {
        if(k & 1) mul = tra * mul;
        tra = tra * tra;
        k >>= 1;
    }
    // For(i, 1, k) mul = mul * tra;
    // res = (tra * tra) * res;
    // res = tra * tra * tra * tra * tra;
    // For(i, 1, 3 * n) {
    //     For(j, 1, 3 * n) cout << mul.a[i][j] << " ";
    //     cout << endl;
    // }
    int as = (1ll * mul.a[1][n] - 1ll * du[n] * mul.a[1][n + n] % mod + mod) % mod;
    // For(i, 1, n) {
    //     as += mul.a[i][i];
    //     if(as >= mod) as -= mod;
    //     as -= 1ll * du[i] * mul.a[i][n + i] % mod;
    //     if(as < 0) as += mod;
    // }
    // cout << mul.a[1][1] << endl;
    printf("%d\n", as);
    return 0;
}