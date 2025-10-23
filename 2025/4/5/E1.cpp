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

#define P 1000000007

#define maxn 5000
int T, n, a[maxn + 5], inv2 = (P + 1) / 2, C[maxn + 5][maxn + 5], fac[maxn + 5];

int fa[maxn + 5];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int b[maxn + 5], s[maxn + 5], cnt[maxn + 5];
void mian() {
    read(n);
    For(i, 0, n + 1) b[i] = -1, s[i] = 0;
    For(i, 1, n) read(a[i]);
    For(i, 1, n) {
        if(a[i] != -1) b[a[i]] = i, s[i]++;
    }
    For(i, 1, n + 1) s[i] += s[i - 1];
    int c = s[n];
    // For(i, 1, c) cnt[i] = c - i + 1;
    int l = n + 1, r = 0, res = 0, ok = 0;
    For(mex, 0, n - 1) {
        if(b[mex] != -1) {
            int tl = min(l, b[mex]), tr = max(r, b[mex]);
            l = tl; r = tr;
        }
        else ok++;
        For(i, 1, l - 1) if(a[i] == -1) cnt[max(0, s[r] - s[l] + 1)]++, cnt[s[n] - s[i] + 1]--;
        For(i, 1, n) cnt[i] += cnt[i - 1];
        if(l <= r) {
            For(i, 2, n) if(ok >= 2) res = (res + 2ll * C[ok][2] * C[i - 2][ok - 2] % P * fac[ok - 2] % P * fac[s[n] - i] % P * cnt[i] % P) % P;
            For(i, 1, l - 1) if(a[i] == -1) {
                int t = s[r] - s[i - 1];
                res = (res + 1ll * C[ok][1] * C[t - 1][ok - 1] % P * fac[ok - 1] % P * fac[s[n] - t] % P) % P;
            }
            For(i, r + 1, n) if(a[i] == -1) {
                int t = s[i] - s[l - 1];
                res = (res + 1ll * C[ok][1] * C[t - 1][ok - 1] % P * fac[ok - 1] % P * fac[s[n] - t] % P) % P;
            }
            int t = s[r] - s[l - 1];
            res = (res + 1ll * C[t][ok] % P * fac[ok] % P * fac[s[n] - t] % P) % P;
        }
        else {
            if(ok >= 2) For(i, mex, n) res = (res + 2ll * C[ok][2] * C[i - 2][ok - 2] % P * fac[ok - 2] % P * fac[s[n] - i] % P * cnt[i] % P) % P;
            else res = ()
        }
    }
    cout << res << endl;
}

int main() {
    C[0][0] = 1;
    For(i, 1, maxn) {
        C[i][0] = 1;
        For(j, 1, maxn) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}


