#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define DD double
#define inf 1000000000
#define eps 0.000001
#define maxn 1000000
#define mod 1000000007
#define P 1000000007
using namespace std;

LL n, ord[maxn + 1];
int sq, pri[maxn + 101], vis[maxn + 101], cnt_pri = 0;
int cnt_g = 0, g1[maxn + 1], g2[maxn + 1], id1[maxn + 1], id2[maxn + 1], sum1[maxn + 1], sum2[maxn + 1];
int inv2, inv6;

void read(LL &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int fp(int x, int y) {
    int ansi = 1;
    while(y) {
        if(y & 1) ansi = 1ll * ansi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ansi;
}

int get_f(LL x) { return x == 1 ? 1 : 1ll * x % mod * (x % mod - 1 + mod) % mod; }

int get_s(LL x, int y) {
    int to = ((x <= sq) ? id1[x] : id2[n / x]);
    if(pri[y] >= x) return 1;
    if(1ll * pri[y] * pri[y] >= x) return (1ll * g2[to] - g1[to] - sum2[y] + sum1[y] + 1ll + 2ll * mod) % mod;
    int ansi = 0;
    for(LL i = 1; i <= x; i *= pri[y + 1])
        ansi = (ansi + 1ll * get_f(i) % mod * get_s(x / i, y + 1) % mod) % mod;
    return ansi;
}

int get_f1(LL x, int y) {
    int to = ((x <= sq) ? id1[x] : id2[n / x]);
    // if(pri[y] >= x) return 1;
    // if(1ll * pri[y] * pri[y] >= x) return (1ll * g2[to] - g1[to] - sum2[y] + sum1[y] + 1ll + 2ll * mod) % mod;
    if(pri[y] >= x) return 1;
    if(1ll * pri[y] * pri[y] >= x) return ((1ll * g2[to] - g1[to]) - (1ll * sum2[y] - sum1[y]) + 2ll * P + 1) % P;
    int res = 0;
    for(LL i = 1; i <= x; i *= pri[y + 1])
        res = (res + 1ll * (i == 1 ? 1 : (1ll * i % P * (i % P - 1) % P + P) % P) * get_f1(x / i, y + 1) % P) % P;
    return res;
}

int main() {
    freopen("in.txt", "r", stdin);
    read(n); sq = sqrt(n); inv2 = fp(2, mod - 2); inv6 = fp(6, mod - 2);
    sum1[0] = sum2[0] = 1;
    for(int i = 2; i <= sq + 100; ++i) {
        if(!vis[i]) {
            pri[++cnt_pri] = i;
            sum1[cnt_pri] = (1ll * sum1[cnt_pri - 1] + i) % mod;
            sum2[cnt_pri] = (sum2[cnt_pri - 1] + 1ll * i * i % mod) % mod;
        }
        for(int j = 1; j <= cnt_pri && i * pri[j] <= sq + 100; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    LL l = 1, r;
    for(; l <= n; l = r + 1) {
        r = min(n, n / (n / l)); LL now = n / l;
        ord[++cnt_g] = now;
        if(now <= sq) id1[now] = cnt_g;
        else id2[n / now] = cnt_g;
        now = now % mod;
        g1[cnt_g] = (1 + now) * now % mod * inv2 % mod;
        g2[cnt_g] = now % mod * (now + 1) % mod * (2 * now % mod + 1) % mod * inv6 % mod;
    }
    for(int i = 1; i <= cnt_pri; ++i) {
        for(int j = 1; j <= cnt_g && 1ll * pri[i] * pri[i] <= ord[j]; ++j) {
            int to = ((ord[j] / pri[i] <= sq) ? id1[ord[j] / pri[i]] : id2[n / (ord[j] / pri[i])]);
            g1[j] = (g1[j] - 1ll * (1ll * g1[to] - sum1[i - 1] + mod) % mod * pri[i] % mod + mod) % mod;
            g2[j] = (g2[j] - 1ll * (1ll * g2[to] - sum2[i - 1] + mod) % mod * pri[i] % mod * pri[i] % mod + mod) % mod;
        }
    }
    // cout << g2[1] << endl;
    //	cout << g2[1] << endl;
    printf("%d\n", get_f1(n, 0));
    printf("%d\n", get_s(n, 0));
    return 0;
}
