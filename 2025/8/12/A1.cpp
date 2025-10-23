#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define LL long long
#define maxn 200000


int T, n, ch[maxn + 5][2], f[maxn + 5][35];

void dfs(int u) {
    // cout << u << " " << f[u] << endl;
    if(!u) return;
    For(o, 0, 1) dfs(ch[u][o]);
    int v1 = ch[u][0], v2 = ch[u][1];
    For(i, 0, 29) {
        f[u][i + 1] = inf;
        if(i) f[u][i + 1] = min(f[u][i + 1], min(f[v1][i - 1] + f[v2][i], f[v1][i] + f[v2][i - 1]));
        f[u][i + 1] = min(f[u][i + 1], f[v1][i] + f[v2][i]);
    }
    // if(u == 8) {
    //     For(i, 0, len[u]) cout << f[u][i] << " "; cout << endl;
    // }
    f[u][0] = f[u][1] + 1;
}

void mian() {
    scanf("%d", &n);
    For(i, 1, n) For(o, 0, 1) scanf("%d", &ch[i][o]);
    // cout << f[0][30] << endl;
    // cout << f[0][2] << endl;
    dfs(1);
    int mn = n;
    For(i, 0, 30) mn = min(mn, f[1][i]);
    printf("%d\n", mn);
}

int main() {
    memset(f, inf, sizeof f);
    // freopen("in.txt", "r", stdin);
    f[0][0] = 0;
    f[0][1] = 1;
    For(i, 2, 31) f[0][i] = f[0][i - 1] + f[0][i - 2] + 1;
    scanf("%d", &T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i][0] = ch[i][1] = 0;
            For(j, 0, 30) f[i][j] = inf;
        }

    }
}