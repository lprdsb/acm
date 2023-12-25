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
#define mod 998244353
using namespace std;

int T;
LL n;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int fp(LL x, LL y) {
    int res = 1;
    x %= mod;
    while (y) {
        if (y & 1) res = 1ll * res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

map<LL, int> ma;
int sol(LL len) {
    if (ma.count(len)) return ma[len];
    if (len == 1) return 1;
    // cout << len << endl;
    return ma[len] = (1ll * fp(2, len) - fp(2, len / 2) - fp(2, (len + 1) / 2) + 1 + 2ll * mod) % mod;
}

int main() {
    // cout << sol(1) << endl;
    // freopen("in.txt", "r", stdin);
    read(T);
    while (T--) {
        read(n);
        LL len[2] = { n, n + 1 }, sum[2] = { 1, 0 }, cnt[2] = { 1, 0 };
        int res = 0;
        while (len[1] != 1) {
            res = (res + 1ll * sol(len[0]) * sum[0] % mod + 1ll * sol(len[1]) * sum[1] % mod) % mod;
            LL leni[2] = { len[0] / 2, len[0] / 2 + 1 }, sumi[2] = {}, cnti[2] = {};
            if (len[0] % 2 == 0) {
                sumi[0] = (4 * sum[0] + cnt[0] + 2 * sum[1] + cnt[1]) % mod;
                sumi[1] = (2 * sum[1]) % mod;
                cnti[0] = (2 * cnt[0] + cnt[1]) % mod;
                cnti[1] = cnt[1];
            }
            else {
                if (len[0] == 1) sum[0] = cnt[0] = 0;
                sumi[0] = (2 * sum[0] + cnt[0]) % mod;
                sumi[1] = (4 * sum[1] + cnt[1] + 2 * sum[0]) % mod;
                cnti[0] = cnt[0];
                cnti[1] = (cnt[0] + 2 * cnt[1]) % mod;
            }
            For(o, 0, 1) sum[o] = sumi[o], cnt[o] = cnti[o], len[o] = leni[o];
        }
        res = (res + sum[1]) % mod;
        printf("%d\n", res);
    }
}
