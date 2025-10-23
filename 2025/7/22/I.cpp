#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int P = 998244353, gi = 3, ig = 332748118;
const int N = 6e5 + 7, MX = 6e5;
int f[N], ex[N];
int a[N];
int t, k;
int n = 200000;

int qw(int a, int b) {
    int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
    return ans;
}

namespace POLY {
    int fac[N], inv[N], iv[N];
    int w[N], rev[N];
    int len, lim;


    void pre(int deg) {
        lim = 1;len = 0;
        while(lim < deg + 1) {
            lim <<= 1, ++len;
        }
        fs(i, 0, lim - 1)rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
    }

    void pre(int len, int lim) {
        fs(i, 0, lim - 1)rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
    }
    void init() {
        w[0] = 1;
        fac[0] = 1;fs(i, 1, MX)fac[i] = (ll)fac[i - 1] * i % P;
        inv[MX] = qw(fac[MX], P - 2);fn(i, MX - 1, 0)inv[i] = (ll)inv[i + 1] * (i + 1) % P;
        iv[1] = 1;fs(i, 2, MX)iv[i] = (ll)(P - P / i) * iv[P % i] % P;
    }

    void NTT(int *a, int lim, int type) {
        int ng = type ? gi : ig;
        fs(i, 0, lim - 1)if(i < rev[i])swap(a[i], a[rev[i]]);
        for(int l = 1, le = 2;l < lim;l <<= 1, le <<= 1) {
            w[1] = qw(ng, (P - 1) / le);
            fs(i, 2, l - 1)w[i] = (ll)w[i - 1] * w[1] % P;
            for(int i = 0;i < lim;i += le) {
                int *f1 = a + i, *f2 = f1 + l;
                for(int k = 0;k < l;++k) {
                    int y = (ll)w[k] * f2[k] % P;
                    f2[k] = (f1[k] - y) % P;
                    f1[k] = (f1[k] + y) % P;
                }
            }
        }
        fs(i, 0, lim - 1)(a[i] < 0) && (a[i] += P);
        if(type)return;
        int iv = P - (P - 1) / lim;
        fs(i, 0, lim - 1)a[i] = (ll)a[i] * iv % P;
    }

    void INV(int *f, int *f0, int deg) {
        static int tf[N];
        f0[0] = qw(f[0], P - 2);
        int len = 1, l = 1, lim = 2;
        while(l <= deg) {
            l <<= 1, lim <<= 1, ++len;
            pre(len, lim);
            fs(i, 0, l - 1)tf[i] = f[i];
            NTT(tf, lim, 1);NTT(f0, lim, 1);
            fs(i, 0, lim - 1)f0[i] = (2 - (ll)f0[i] * tf[i] % P + P) * f0[i] % P;
            NTT(f0, lim, 0);
            fs(i, l, lim - 1)f0[i] = 0;
        }
        fs(i, deg + 1, l - 1)f0[i] = 0;
        fs(i, 0, lim - 1)tf[i] = 0;
    }

    void DIF(int *f, int *df, int deg) {
        fs(i, 0, deg - 1)df[i] = (ll)f[i + 1] * (i + 1) % P;
        df[deg] = 0;
    }

    void INT(int *f, int *sf, int deg) {
        fn(i, deg, 1)sf[i] = (ll)f[i - 1] * iv[i] % P;
        sf[0] = 0;
    }

    void LN(int *f, int *ln, int deg) {
        static int df[N];
        INV(f, ln, deg - 1);
        DIF(f, df, deg);
        pre((deg - 1) << 1);
        NTT(ln, lim, 1);NTT(df, lim, 1);
        fs(i, 0, lim - 1)ln[i] = (ll)ln[i] * df[i] % P;
        NTT(ln, lim, 0);
        INT(ln, ln, deg);
        fs(i, deg + 1, (deg - 1) << 1)ln[i] = 0;
        fs(i, 0, lim - 1)df[i] = 0;
    }

    void EXP(int *f, int *f0, int deg) {
        static int tf[N], ln[N];
        f0[0] = 1;int lim = 2, len = 1, l = 1;
        while(l <= deg) {
            l <<= 1, lim <<= 1, ++len;
            LN(f0, ln, l - 1);
            fs(i, 0, l - 1)tf[i] = f[i];
            pre(len, lim);
            NTT(tf, lim, 1);NTT(f0, lim, 1);NTT(ln, lim, 1);
            fs(i, 0, lim - 1)f0[i] = (ll)f0[i] * (1 - ln[i] + tf[i] + P) % P;
            NTT(f0, lim, 0);
            fs(i, l, lim - 1)f0[i] = 0;
            fs(i, 0, lim - 1)ln[i] = 0;
        }
        fs(i, deg + 1, l - 1)f0[i] = 0;
        fs(i, 0, lim - 1)tf[i] = 0;
    }
}

void solve() {
    POLY::init();
    // f[1] = 1;
    // POLY::EXP(f, ex, 10);
    // fs(i, 0, 11)cout << (ll)ex[i] * POLY::fac[i] % P << " ";
    // cout << endl;
    scanf("%d%d", &t, &k);++k;
    fs(i, 1, n)f[i] = qw(POLY::iv[i], k);
    fs(i, 1, 10)cout << (ll)f[i] * qw(i, k) % P << ' ';
    cout << endl;
    POLY::EXP(f, ex, n + 1);
    fs(i, 1, t)scanf("%d", &a[i]);
    fs(i, 1, t) {
        printf("%lld\n", (ll)ex[a[i]] * qw(POLY::fac[a[i]], k) % P);
    }
}

signed main() {
    int T = 1;
    // scanf("%d", &T);
    while(T--) {
        solve();
    }
}