#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define pb push_back
#define LL long long
#define LLL __int128_t
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define cst const
using namespace std;

#define maxn 200000
#define maxm 600000

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
        for(LL i = 1; i <= x; i *= pri[y]) {
            res = (res + 1ll * (i == 1 ? 1 : (1ll * i % P * (i % P) % P - i % P + P) % P) * get_f(x / i, y + 1) % P) % P;
        }
        return res;
    }

    void mian(LL _n) {
        cnt = tot = 0;
        For(i, 1, maxn) vis[i] = 0;
        For(o, 0, 2) For(i, 0, maxn) s[o][i] = g[o][i] = 0;
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
            // g[1][tot] = 1ll * now % P * ((now + 1) % P) % P * inv2 % P;
            // g[2][tot] = 1ll * now % P * ((now + 1) % P) % P * (2ll * now % P + 1) % P * inv6 % P;
            i = n / now;
        }
        For(o, 1, cnt) {
            For(i, 1, tot) {
                if(1ll * pri[o] * pri[o] <= id[i]) {
                    int tmp = 1;
                    For(o1, 0, 0) {
                        g[o1][i] = (g[o1][i] - 1ll * (g[o1][To(id[i] / pri[o])] - s[o1][o - 1] + P) % P * tmp % P + P) % P;
                        tmp = 1ll * tmp * pri[o] % P;
                    }
                }
                else break;
            }
        }
        // printf("%d\n", get_f(n, 1));
    }

    LL get_val(LL up) {
        return g[0][To(up)] - 1;
    }
}


LL sol(LL up) {
    LL n = 0;
    Rof(o, 62, 0) {
        LLL to = n | (1ll << o);
        if(to * to < up) n = to;
    }
    n++;
    Min25::mian(n);
    LL res = 0, pre = 0;
    LL t = n;
    For(i, 2, t) {
        if(i * i > t) break;
        if(t % i == 0) {
            while(t % i == 0) t /= i;
            if((LLL)n * n - i > up) res--;
        }
    }
    if(t > 1 && (LLL)n * n - t > up) res--;
    For(i, 1, n) {
        LL now = n / i, to = n / now;
        LL tmp = Min25::get_val(to);
        res += now * (tmp - pre);
        pre = tmp;
        i = to;
    }
    return res;
}

int chk(int x) {
    LL n = 0;
    Rof(o, 62, 0) {
        LLL to = n | (1ll << o);
        if(to * to < x) n = to;
    }
    n++;
    return x == n * n;
}

LL l, r;
int main() {
    scanf("%lld%lld", &l, &r);
    // cout << sol(r) << endl;
    // Min25::mian(l);
    // cout << Min25::get_val(l) << endl;
    // Min25::mian(r);
    // cout << Min25::get_val(r) << endl;
    printf("%lld\n", sol(r) - sol(l - 1));
    // int res = 0;
    // For(i, l, r) {
    //     int t = i;
    //     int fl = 0;
    //     For(j, 2, i) {
    //         if(j * j > t) break;
    //         if(t % j == 0) {
    //             while(t % j == 0) t /= j;
    //             if(chk(i + j)) {
    //                 fl = 1;
    //                 break;
    //             }
    //         }
    //     }
    //     if(t > 1 && chk(i + t)) fl = 1;
    //     res += fl;
    // }
    // cout << res << endl;
}