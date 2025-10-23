#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define LL long long
#define maxn 200000


int T, n, ch[maxn + 5][2];
int g[40 * maxn + 5], len[maxn + 5], *f[maxn + 5], tot = 0;

int h[maxn + 500];

void dfs(int u) {
    For(o, 0, 1) {
        int v = ch[u][o];
        if(v) dfs(v);
    }
    if(len[ch[u][0]] == len[ch[u][1]]) len[u] = len[ch[u][0]];
    else {
        if(len[ch[u][0]] > len[ch[u][1]]) swap(ch[u][0], ch[u][1]);
        len[u] = len[ch[u][0]] + 1;
    }
    len[u]++;
}

void dfs1(int u) {
    // cout << u << " " << f[u] << endl;
    if(ch[u][0]) {
        f[ch[u][0]] = f[u] + 1;
        dfs1(ch[u][0]);
    }
    int *F = f[u] + 1;
    if(!ch[u][0]) F = f[0];
    int v = ch[u][1];
    if(v) {
        f[v] = &g[tot];
        tot += len[v] + 10;
        assert(tot <= 30 * maxn);
        dfs1(v);
    }
    For(i, 0, len[u] - 1) {
        h[i] = inf;
        if(i) h[i] = min(h[i], min(F[i - 1] + f[v][i], F[i] + f[v][i - 1]));
        h[i] = min(h[i], F[i] + f[v][i]);
    }
    For(i, 1, len[u]) f[u][i] = h[i - 1];
    // if(u == 8) {
    //     For(i, 0, len[u]) cout << f[u][i] << " "; cout << endl;
    // }
    f[u][0] = f[u][1] + 1;
}

void mian() {
    scanf("%d", &n);
    For(i, 1, n) For(o, 0, 1) scanf("%d", &ch[i][o]);
    len[0] = 30;
    f[0] = &g[0];
    f[0][0] = 0;
    f[0][1] = 1;
    For(i, 2, 31) f[0][i] = f[0][i - 1] + f[0][i - 2] + 1;
    // cout << f[0][30] << endl;
    // cout << f[0][2] << endl;
    tot = 32;
    dfs(1);
    f[1] = &g[tot];
    tot += len[1] + 10;
    dfs1(1);
    int mn = n;
    For(i, 0, len[1]) mn = min(mn, f[1][i]);
    printf("%d\n", mn);
}

int main() {
    memset(f, inf, sizeof f);
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i][0] = ch[i][1] = 0;
        For(i, 0, tot) g[i] = inf;
        tot = 0;
    }
}