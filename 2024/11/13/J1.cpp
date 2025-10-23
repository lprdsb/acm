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
#define maxn 100
using namespace std;

int n, a[maxn + 5], as = 0;
char s[maxn + 5];

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

namespace c1 {
    int f[maxn + 5][maxn + 5];
    int sol() {
        memset(f, 0, sizeof f);
        int asi = 0;
        For(o, 1, n) {
            For(i, 1, o) For(j, o + 1, n) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if(a[i] == a[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 2);
            }
            // if(f[o][n] == 54) cout << o << endl;
            asi = max(asi, f[o][n]);
            For(i, 1, o) For(j, o + 1, n) f[i][j] = 0;
        }
        return asi;
    }
}

namespace c2 {
    int f[maxn + 5][maxn + 5][maxn + 5];
    int sol() {
        memset(f, 0, sizeof f);
        int asi = 0;
        For(o1, 1, n) For(o2, o1 + 1, n) {
            For(i, 1, o1) For(j, o1 + 1, o2) For(p, o2 + 1, n) {
                f[i][j][p] = max(f[i - 1][j][p], max(f[i][j - 1][p], f[i][j][p - 1]));
                if(a[i] == a[j] && a[i] == a[p]) f[i][j][p] = max(f[i][j][p], f[i - 1][j - 1][p - 1] + 3);
            }
            asi = max(asi, f[o1][o2][n]);
            For(i, 1, o1) For(j, o1 + 1, o2) For(p, o2 + 1, n) f[i][j][p] = 0;
        }
        return asi;
    }
}

namespace c3 {
    int t[maxn + 5], tot = 0, asi = 0, f[2][maxn + 5];
    void dfs(int now, int r) {
        if(now > r) {
            memset(f, -inf, sizeof f);
            f[0][tot] = 0;
            int o = 0;
            For(i, 1, n) {
                o ^= 1;
                f[o][0] = f[o ^ 1][0];
                For(j, 1, tot) {
                    f[o][j] = f[o ^ 1][j];
                    if(a[i] == t[j]) f[o][j] = f[o ^ 1][j - 1 ? j - 1 : tot] + 1;
                }
            }
            if(f[o][tot] != tot) {
                asi = max(asi, f[o][tot]);
            }
            return;
        }
        dfs(now + 1, r);
        t[++tot] = a[now];
        dfs(now + 1, r);
        tot--;
    }
    int sol() {
        asi = 0;
        For(i, 0, n / 16)
            dfs(i * 16 + 1, min(n, (i + 1) * 16));
        // cout << asi << endl;
        return asi;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        scanf("%s", s + 1); n = strlen(s + 1);
        For(i, 1, n) a[i] = s[i] - 'a';
        as = 0;
        as = max(as, c1::sol());
        as = max(as, c2::sol());
        as = max(as, c3::sol());
        printf("%d\n", as);
    }
    return 0;
}