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
void read(T & x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define mod 1000000007
#define maxn 400
struct Poly {
    LL a[maxn + 5], lim = 0;
} tmp, tmp1;
Poly operator * (cst Poly &x, cst Poly &y) {
    Poly res = {};
    res.lim = x.lim + y.lim;
    For(i, 0, x.lim) For(j, 0, y.lim) {
        res.a[i + j] += x.a[i] * y.a[j] % mod;
        if(res.a[i + j] >= mod) res.a[i + j] -= mod;
    }
    return res;
}
Poly operator + (cst Poly &x, cst Poly &y) {
    Poly res = {};
    res.lim = max(x.lim, y.lim);
    For(i, 0, x.lim) {
        res.a[i] += x.a[i];
        if(res.a[i] >= mod) res.a[i] -= mod;
    }
    For(i, 0, y.lim) {
        res.a[i] += y.a[i];
        if(res.a[i] >= mod) res.a[i] -= mod;
    }
    return res;
}
LL fp(LL x, LL y) {
    LL res = 1;
    while(y) {
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

Poly f[maxn + 5][2], g[2][maxn + 5], h;
int n, b[maxn + 5], cnt = 0, L[maxn + 5], R[maxn + 5];
LL inv[maxn + 5], invi[maxn + 5];

int chk(Poly &x) {
    For(i, 0, x.lim) if(x.a[i]) return 1;
    return 0;
}

LL sol(int l, int r) {
    For(i, 2, n - 1) {
        if(r <= L[i]) {
            f[i][0].lim = f[i][1].lim = 0;
            f[i][0].a[0] = 0; f[i][1].a[0] = 1;
        }
        else if(l >= R[i]) {
            f[i][0].lim = f[i][1].lim = 0;
            f[i][0].a[0] = 1; f[i][1].a[0] = 0;
        }
        else {
            f[i][0].lim = f[i][1].lim = 1;
            f[i][0].a[0] = mod - L[i] * inv[i] % mod; f[i][0].a[1] = inv[i];
            f[i][1].a[0] = R[i] * inv[i] % mod; f[i][1].a[1] = mod - inv[i];

        }
    }
    h.lim = 0; h.a[0] = 0;
    int o = 0;
    For(i, 0, n) {
        g[0][i].lim = 0, g[0][i].a[0] = i == 0;
        g[1][i].lim = g[1][i].a[0] = 0;
    }
    for(int i = 2; i < n; i += 2) {
        For(j, 0, n) if(chk(g[o][j])) {
            For(o1, 0, 1) For(o2, 0, 1) {
                if(j || o1 || o2) {
                    int to = j + o1 + o2 - 1;
                    if(to <= n) {
                        tmp.lim = f[i][o1].lim + f[i + 1][o2].lim;
                        For(p, 0, tmp.lim) tmp.a[p] = 0;
                        For(i1, 0, f[i][o1].lim) For(i2, 0, f[i + 1][o2].lim) {
                            int t = i1 + i2;
                            tmp.a[t] += f[i][o1].a[i1] * f[i + 1][o2].a[i2] % mod;
                            if(tmp.a[t] >= mod) tmp.a[t] -= mod;
                        }
                        tmp1.lim = tmp.lim + g[o][j].lim;
                        For(p, 0, tmp1.lim) tmp1.a[p] = 0;
                        For(i1, 0, tmp.lim) For(i2, 0, g[o][j].lim) {
                            int t = i1 + i2;
                            tmp1.a[t] += tmp.a[i1] * g[o][j].a[i2] % mod;
                            if(tmp1.a[t] >= mod) tmp1.a[t] -= mod;
                        }

                        For(p, g[o ^ 1][to].lim + 1, tmp1.lim) g[o ^ 1][to].a[p] = 0;
                        if(g[o ^ 1][to].lim < tmp1.lim) g[o ^ 1][to].lim = tmp1.lim;
                        For(p, 0, tmp1.lim) {
                            g[o ^ 1][to].a[p] += tmp1.a[p];
                            if(g[o ^ 1][to].a[p] >= mod) g[o ^ 1][to].a[p] -= mod;
                        }

                        For(p, h.lim + 1, tmp1.lim) h.a[p] = 0;
                        if(h.lim < tmp1.lim) h.lim = tmp1.lim;
                        For(p, 0, tmp1.lim) {
                            h.a[p] += tmp1.a[p];
                            if(h.a[p] >= mod) h.a[p] -= mod;
                        }
                    }
                }
                else g[o ^ 1][0] = g[o ^ 1][0] + g[o][j] * f[i][0] * f[i + 1][0];
            }
            g[o][j].lim = 0;
            g[o][j].a[0] = 0;
        }
        o ^= 1;
    }
    LL res = 0, pl = l, pr = r;
    For(i, 0, h.lim) {
        res += (pr - pl + mod) * h.a[i] % mod * invi[i + 1] % mod;
        if(res >= mod) res -= mod;
        pl = pl * l % mod;
        pr = pr * r % mod;
    }
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxn) invi[i] = fp(i, mod - 2);
    read(n); n *= 2;
    For(i, 1, n) read(L[i]), read(R[i]);
    For(i, 1, n) b[++cnt] = L[i], b[++cnt] = R[i];
    For(i, 1, n) inv[i] = fp(R[i] - L[i], mod - 2);
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    // cout << sol(0, 1) << endl;
    LL res = 0;
    For(i, b[1] == 0, cnt - 1) {
        // cout << i << endl;
        res += sol(b[i], b[i + 1]);
        if(res >= mod) res -= mod;
    }
    res += (L[1] + R[1]) * fp(2, mod - 2) % mod;
    if(res >= mod) res -= mod;
    printf("%lld\n", res);
}
