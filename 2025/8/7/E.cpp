#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long

int T, n, q, a[10][10], b[10][2], to[50], inv[1005];

vector<pair<int, int> > pa[8][1 << 16];

#define P 1000000007

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

int f[1 << 16][1005], vis[8][1 << 16][8][8], g[1 << 16];

void mian() {
    scanf("%d%d", &n, &q);
    int W = 0;
    For(i, 1, n) For(j, 1, n) scanf("%d", &a[i][j]), W += a[i][j];
    For(i, 1, 2 * n + 2) {
        For(j, 1, n) {
            scanf("%d%d", &b[j][0], &b[j][1]);
        }
        if(b[1][0] == b[2][0]) to[i] = b[1][0];
        else if(b[1][1] == b[2][1]) to[i] = n + b[1][1];
        else if(b[1][0] + b[1][1] == b[n][0] + b[n][1]) to[i] = 2 * n + 2;
        else to[i] = 2 * n + 1;
    }
    // int B = min(12, n);
    f[0][0] = 1;
    For(sta, 1, (1 << (2 * n + 2)) - 1) {
        int s = sta - (sta & (-sta));
        For(i, 0, W) f[sta][i] = f[s][i];
        for(auto [x, y] : pa[n][sta]) if(!vis[n][s][x][y]) {
            Rof(i, W, a[x][y]) f[sta][i] = (f[sta][i] - f[sta][i - a[x][y]] + P) % P;
        }
        int res = 0;
        For(i, 1, W) res = (res - 1ll * f[sta][i] * inv[i] % P + P) % P;
        g[sta] = 1ll * W * res % P;
    }
    while(q--) {
        int s1; scanf("%d", &s1);
        int s2 = 0;
        For(i, 0, 2 * n + 1) s2 |= (((s1 >> i) & 1) << (to[i + 1] - 1));
        printf("%d\n", g[s2]);
    }
}

int main() {
    // cout << "asd" << endl;
    For(i, 1, 1000) inv[i] = fp(i, P - 2);
    For(o, 1, 7) For(sta, 0, (1 << (2 * o + 2)) - 1) {
        For(p, 0, 2 * o + 1) if((sta >> p) & 1) {
            if(p + 1 <= o) For(j, 1, o) pa[o][sta].push_back({ p + 1, j });
            else if(p + 1 <= 2 * o) For(j, 1, o) pa[o][sta].push_back({ j, p - o + 1 });
            else if(p + 1 == 2 * o + 1) For(j, 1, o) pa[o][sta].push_back({ j, j });
            else For(j, 1, o) pa[o][sta].push_back({ o - j + 1, j });
        }
        sort(pa[o][sta].begin(), pa[o][sta].end());
        pa[o][sta].erase(unique(pa[o][sta].begin(), pa[o][sta].end()), pa[o][sta].end());
        for(auto [x, y] : pa[o][sta]) vis[o][sta][x][y] = 1;
    }
    // for(auto [x, y] : pa[2][8]) cout << x << " " << y << endl;
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}