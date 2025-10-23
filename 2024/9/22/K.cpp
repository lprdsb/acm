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

#define maxn 200
#define mod 998244353
int n, a[maxn + 5], b[maxn + 5], f[maxn * maxn + 5][maxn + 5], c[maxn + 5][maxn + 5], fac[maxn + 5], tot = 0;
LL k;
struct Trie {
    int ch[maxn * maxn + 5][2], sz[maxn * maxn + 5], tot = 0;
} tr[2];

int dfs(int u1, int u2, int o) {
    if(!u1 || !u2) return 0;
    int id = ++tot;
    if(o == -1) {
        For(i, 0, min(tr[0].sz[u1], tr[1].sz[u2])) f[id][i] = 1ll * c[tr[0].sz[u1]][i] * c[tr[1].sz[u2]][i] % mod * fac[i] % mod;
        return id;
    }
    int a1 = tr[0].sz[tr[0].ch[u1][0]], b1 = tr[0].sz[tr[0].ch[u1][1]], a2 = tr[1].sz[tr[1].ch[u2][0]], b2 = tr[1].sz[tr[1].ch[u2][1]];
    if((k >> o) & 1) {
        int id1 = dfs(tr[0].ch[u1][0], tr[1].ch[u2][1], o - 1);
        int id2 = dfs(tr[0].ch[u1][1], tr[1].ch[u2][0], o - 1);
        For(i, 0, min(a1, b2)) For(j, 0, min(a2, b1))
            f[id][i + j] = (f[id][i + j] + 1ll * f[id1][i] * f[id2][j] % mod) % mod;
    }
    else {
        int id1 = dfs(tr[0].ch[u1][0], tr[1].ch[u2][0], o - 1);
        int id2 = dfs(tr[0].ch[u1][1], tr[1].ch[u2][1], o - 1);
        For(i, 0, min(a1, a2)) For(j, 0, min(b1, b2)) For(p, 0, min(a1 - i, b2 - j)) For(q, 0, min(a2 - i, b1 - j)) {
            int tmp = 1ll * c[a1 - i][p] * c[b2 - j][p] % mod * fac[p] % mod * c[b1 - j][q] % mod * c[a2 - i][q] % mod * fac[q] % mod;
            f[id][i + j + p + q] = (f[id][i + j + p + q] + 1ll * f[id1][i] * f[id2][j] % mod * tmp % mod) % mod;
        }
    }
    return id;
}

int main() {
    // freopen("in.txt", "r", stdin);
    f[0][0] = 1;
    c[0][0] = 1;
    For(i, 1, maxn) {
        c[i][0] = 1;
        For(j, 1, maxn) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    read(n); read(k);
    For(o, 0, 1) {
        tr[o].tot = 1;
        For(i, 1, n) {
            // cout << i << endl;
            LL x; read(x);
            int now = 1;
            Rof(o1, 59, 0) {
                int to = (x >> o1) & 1;
                if(!tr[o].ch[now][to]) tr[o].ch[now][to] = ++tr[o].tot;
                now = tr[o].ch[now][to];
                tr[o].sz[now]++;
            }
        }
    }
    // cout << "asd" << endl;
    int id = dfs(1, 1, 59);
    For(i, 1, n) printf("%d\n", f[id][i]);
    return 0;
}
