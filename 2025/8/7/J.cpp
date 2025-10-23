#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long

#define P 998244353

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

#define maxn 1600000

int g = 3, ig = fp(3, P - 2);

vector<int> rev;
vector<int> gpw{ 0, 1 };
void dft(int *f, int lim) {
    if(rev.size() != lim) {
        rev.resize(lim);
        int k = __builtin_ctz(lim) - 1;
        For(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
    }
    For(i, 0, lim - 1) if(rev[i] < i) swap(f[i], f[rev[i]]);
    if(gpw.size() < lim) {
        int k = __builtin_ctz(gpw.size());
        gpw.resize(lim);
        while((1 << k) < lim) {
            int w = fp(g, (P - 1) >> (k + 1));
            For(i, 1 << (k - 1), (1 << k) - 1) {
                gpw[i << 1] = gpw[i];
                gpw[(i << 1) | 1] = 1ll * gpw[i] * w % P;
            }
            k++;
        }
    }
    for(int i = 2; i <= lim; i <<= 1) {
        int ii = i >> 1;
        for(int j = 0; j < lim; j += i) {
            For(p, 0, ii - 1) {
                int t1 = f[j + p], t2 = 1ll * gpw[ii + p] * f[j + ii + p] % P;
                f[j + p] = (t1 + t2) % P;
                f[j + ii + p] = (t1 - t2 + P) % P;
            }
        }
    }
}
void idft(int *f, int lim) {
    reverse(f + 1, f + lim);
    dft(f, lim);
    int inv = fp(lim, P - 2);
    For(i, 0, lim - 1) f[i] = 1ll * f[i] * inv % P;
}

int T;

int a[maxn + 5], b[maxn + 5], la, lb;
char s[maxn + 5];

int mul(int *f, int lf, int *g, int lg, int *res) {
    int len = lf + lg - 1, lim = 1;
    while(lim < len) lim <<= 1;
    dft(f, lim); dft(g, lim);
    For(i, 0, lim - 1) res[i] = 1ll * f[i] * g[i] % P;
    idft(res, lim);
    return lim;
}

int c[maxn + 5];
void mian() {
    scanf("%s", s + 1); la = strlen(s + 1);
    For(i, 1, la) a[la - i] = s[i] - '0';
    // For(i, 0, la - 1) cout << a[i] << " "; cout << endl;
    scanf("%s", s + 1); lb = strlen(s + 1);
    For(i, 1, lb) b[lb - i] = s[i] - '0';
    int Lim = mul(a, la, b, lb, c), lim = Lim;
    while(lim && c[lim - 1] == 0) lim--;
    For(i, 0, lim - 1) {
        int to = abs(c[i]) % 2 != 0;
        int tmp = (c[i] - to) / 2;
        tmp *= -1;
        c[i + 2] += tmp;
        c[i] = to;
    }
    // Rof(i, lim, 0) cout << c[i] << " "; cout << endl;
    int now = lim;
    while((c[now] != 0 && c[now] != 1) || (c[now + 1] != 0 && c[now + 1] != 1)) {
        int to = abs(c[now]) % 2 != 0;
        int tmp = (c[now] - to) / 2;
        tmp *= -1;
        c[now + 2] += tmp;
        c[now] = to;
        lim = now + 3;
        now++;
    }
    assert(!c[lim + 1] && !c[lim + 2]);
    lim += 2;
    // Rof(i, lim, 0) cout << c[i] << " "; cout << endl;
    while(lim && c[lim - 1] == 0) lim--;
    if(lim == 0) puts("0");
    else {
        For(i, 0, lim - 1) assert(c[i] == 0 || c[i] == 1);
        Rof(i, lim - 1, 0) cout << c[i]; cout << endl;
    }
    For(i, 0, min(maxn, max(lim + 100, 2 * Lim))) a[i] = b[i] = c[i] = 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}