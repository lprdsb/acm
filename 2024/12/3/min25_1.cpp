#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(LL i = (a), en = (b); i >= en; --i)
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

#define P 1000000007
#define maxn 200000
#define maxm 600000


int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}
int inv2 = fp(2, P - 2), inv6 = fp(6, P - 2);

namespace Min25 {
    LL n;
    int s[3][maxn + 5], pri[maxn + 5], cnt = 0, g[3][maxm + 5], vis[maxn + 5];

    int to[2][maxn + 5], tot = 0;
    LL id[maxm + 5];
    int To(LL x) {
        if(x <= maxn) return to[0][x];
        return to[1][n / x];
    }

    int get_f(LL x, int y) {
        if(pri[y] > x) return 1;
        int t = To(x);
        if(1ll * pri[y] * pri[y] > x) return ((1ll * g[2][t] - g[1][t]) - (1ll * s[2][y - 1] - s[1][y - 1]) + 2ll * P + 1) % P;
        int res = 0;
        for(LL i = 1; i <= x; i *= pri[y])
            res = (res + 1ll * (i == 1 ? 1 : (1ll * i % P * (i % P) % P - i % P + P) % P) * get_f(x / i, y + 1) % P) % P;
        return res;
    }

    void mian(LL _n) {
        n = _n;
        For(o, 0, 2) s[o][0] = 1;
        For(i, 2, maxn) {
            if(!vis[i]) {
                pri[++cnt] = i;
                int tmp = 1;
                For(o, 0, 2) {
                    s[o][cnt] = (s[o][cnt - 1] + tmp) % P;
                    tmp = 1ll * tmp * i % P;
                }
            }
            for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
                vis[i * pri[j]] = 1;
                if(i % pri[j] == 0) break;
            }
        }
        For(i, 1, n) {
            LL now = n / i;
            id[++tot] = now;
            if(now <= maxn) to[0][now] = tot;
            else to[1][n / now] = tot;
            g[0][tot] = now % P;
            g[1][tot] = 1ll * now % P * ((now + 1) % P) % P * inv2 % P;
            g[2][tot] = 1ll * now % P * ((now + 1) % P) % P * (2ll * now % P + 1) % P * inv6 % P;
            i = n / now;
        }
        For(o, 1, cnt) {
            For(i, 1, tot) {
                if(1ll * pri[o] * pri[o] <= id[i]) {
                    int tmp = 1;
                    For(o1, 0, 2) {
                        g[o1][i] = (g[o1][i] - 1ll * (g[o1][To(id[i] / pri[o])] - s[o1][o - 1] + P) % P * tmp % P + P) % P;
                        tmp = 1ll * tmp * pri[o] % P;
                    }
                }
                else break;
            }
        }
        printf("%d\n", get_f(n, 1));
    }
}

LL n;
int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    Min25::mian(n);
}
