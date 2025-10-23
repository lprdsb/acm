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

#define maxn 500
int n;
LL f[maxn + 5][maxn + 5], a[maxn + 5], ch[maxn + 5][2], pre[maxn + 5][maxn + 5];

int dfs(int l, int r) {
    if(l > r) return -1;
    int u = pre[l][r];
    ch[u][0] = dfs(l, u - 1);
    ch[u][1] = dfs(u + 1, r);
    return u;
}


int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    // For(i, 1, n) f[i][i] = a[i];
    For(i, 1, n) a[i] += a[i - 1];
    For(i, 1, n) For(j, i, n) f[i][j] = Inf;
    For(len, 1, n) {
        For(l, 1, n - len + 1) {
            int r = l + len - 1;
            For(i, l, r) {
                LL tmp = f[l][i - 1] + f[i + 1][r] + a[r] - a[l - 1];
                if(tmp < f[l][r]) {
                    f[l][r] = tmp;
                    pre[l][r] = i;
                }
            }
        }
    }
    printf("%lld\n", f[1][n]);
    dfs(1, n);
    For(i, 1, n) printf("%d %d\n", ch[i][0], ch[i][1]);
}
