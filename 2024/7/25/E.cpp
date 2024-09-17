#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int N = 3e5 + 7, MX = 3e5, M = 1e5;
int f[N], cnt[N], g[N];
const int P = 998244353, gi = 3, ig = 332748118;
namespace poly {
    int fac[N], inv[N], iv[N];
    // int a[N], cnt[N];
    int w[N], rev[N];
    int len, lim;

    int qw(int a, int b) {
        int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
        return ans;
    }

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
        static int tf[N], ln[N];;
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

// int len;
// void solve() {
//     fs(i, 1, len)
// }

#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define maxn 100000
char s[maxn + 5];
int to[maxn + 5], ch[maxn + 5][2], b[maxn + 5];

signed main() {
    poly::init();
    // freopen("in.txt", "r", stdin);
    // init();
    // pre(5, 32);
    // f[0] = 1;f[2] = 1;g[0] = 1;g[5] = 1;
    // NTT(f, 32, 1);NTT(g, 32, 1);
    // fs(i, 0, 31)f[i] = (ll)f[i] * g[i] % P;
    // NTT(f, 32, 0);
    // // EXP(f, g, 5);
    // fs(i, 0, 11)cout << f[i] << ' ';
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    // cout << len << endl;
    For(i, 1, len) ch[i - 1][s[i] - 'a'] = i;
    // cout << ch[0][0] << endl;
    to[1] = 0;
    For(i, 1, len) {
        For(o, 0, 1) {
            if(ch[i][o]) to[i + 1] = ch[to[i]][o];
            else ch[i][o] = ch[to[i]][o];
        }
    }
    // cout << ch[1][0] << endl;
    For(i, 1, len) b[i] = i - ch[i - 1][!(s[i] - 'a')];
    // For(i, 1, len) cout << b[i] << " "; cout << endl;
    fs(i, 1, len)++cnt[b[i]];
    fs(i, 1, M) {
        // if(i <= 10) cout << "//" << i << ' ' << cnt[i] << endl;
        for(int jj = 1, j = i;j <= M;j += i, ++jj) {
            if(jj & 1) {
                f[j] = (f[j] + (ll)cnt[i] * poly::iv[jj]) % P;
            }
            else {
                f[j] = (f[j] + P - (ll)cnt[i] * poly::iv[jj] % P) % P;
            }
        }
    }
    // fs(i, 1, 100)cout << f[i] << ' ';
    // cout << endl;
    poly::EXP(f, g, n);
    For(i, 0, len - 1) printf("0 ");
    For(i, len, n) printf("%d ", g[i - len]); puts("");
    // For(i, 0, n) cout << g[i] << " "; cout << endl;
}