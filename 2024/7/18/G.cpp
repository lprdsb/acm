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

#define maxn 1000
int n, a[maxn + 5], pri[maxn + 5], cnt = 0, vis[maxn + 5], to[maxn + 5], id[maxn + 5];

int f[1 << 11][2], g[1 << 11][2];

#define mod 1000000007

int mul[1 << 11];

vector<pair<int, int> > opt[maxn + 5];

int main() {
    freopen("in.txt", "r", stdin);
    pri[0] = 1;
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i, to[i] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            to[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    For(i, 1, cnt) id[pri[i]] = i;
    mul[0] = 1;
    For(i, 1, (1 << 11) - 1) {
        For(j, 0, 10) if((i >> j) & 1) mul[i] = 1ll * mul[i ^ (1 << j)] * pri[j + 1] % mod;
    }
    // int sum = 0;
    // For(i, 1, cnt) sum += pri[i] <= 33;
    // cout << sum << endl;

    read(n);
    For(i, 1, n) {
        int x; read(x);
        int mx = 0, sta = 0, sum = 1;
        while(x != 1) {
            int now = to[x], tot = 0;
            mx = max(mx, now);
            while(x % now == 0) {
                tot += 1;
                x /= now;
                if(tot % 2 == 0) sum = 1ll * sum * now % mod;
            }
            if(now < 37 && (tot & 1)) sta |= 1 << (id[now] - 1);
        }
        opt[max(0, id[mx] - 11)].pb({ sta, sum });
    }
    pri[11] = 1;
    int all = (1 << 11) - 1;
    f[0][0] = 1;
    For(i, 0, id[pri[cnt]] - 11) {
        for(auto [sta, sum] : opt[i]) {
            For(o, 0, 1) For(j, 0, all) {
                g[j][o] = (1ll * g[j][o] + f[j][o]) % mod;
                g[j ^ sta][!o] = (1ll * g[j ^ sta][!o] + 1ll * f[j][o] * sum % mod * mul[sta & j] % mod * (o ? pri[11 + i] : 1) % mod) % mod;
            }
            For(o, 0, 1) For(j, 0, all) {
                f[j][o] = g[j][o];
                g[j][o] = 0;
            }
        }
        For(j, 0, all) {
            if(i == 0) f[j][0] = (1ll * f[j][0] + f[j][1]) % mod;
            f[j][1] = 0;
        }
    }
    f[0][0] -= 1;
    if(f[0][0] < 0) f[0][0] += mod;
    printf("%d\n", f[0][0]);
    return 0;
}
