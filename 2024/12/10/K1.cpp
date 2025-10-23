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

#define maxn 100000
LL lc, gc;
int n, m;
int to[maxn + 5];
char s[maxn + 5], t[maxn + 5];
vector<int> sum[maxn + 5];

LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }

LL bas = 0;
LL sol(LL lim) {
    if(lim == -1) return 0;
    if(lim >= lc) return lim / lc * bas + sol(lim % lc);
    LL res = 0;
    For(i, 0, min((LL)n - 1, lc - 1)) {
        LL l = 0, r = m;
        while(l < r) {
            LL md = l + r >> 1;
            if(i + md * n >= lim) r = md;
            else l = md + 1;
        }
        l--;
        res += sum[s[i] - '0'][i % gc][to[i % m] + l] - sum[s[i] - '0'][i % gc][to[i % m] - 1];
    }
    return res;
}

LL l, r;
int main() {
    // freopen("in.txt", "r", stdin);
    read(l); read(r); l--; r--;
    scanf("%s", s); n = strlen(s);
    scanf("%s", t); m = strlen(t);
    gc = gcd(n, m); lc = 1ll * n * m / gc;
    LL len = m / gc;
    For(i, 0, gc - 1) sum[i].resize(2 * len + 1);
    For(o, 0, 25) {
        For(i, 0, gc - 1) {
            For(j, 1, 2 * len) sum[i][j] = i;
            int now = i;
            For(j, 1, len) {
                if(t[now] - '0' == o)
                    sum[t[now] - '0'][i][j]++;
                sum[t[now] - '0'][i][j + len]++;
                to[now] = j;
                now = (now + n) % m;
            }
            For(o, 0, 25) For(j, 1, 2 * len) sum[o][i][j] += sum[o][i][j - 1];
        }
        For(i, 0, n - 1) bas += sum[s[i] - '0'][i % gc][len];
        LL res = 0;
        printf("%lld\n", sol(r) - sol(l - 1));
    }
    // For(i, l, r) res += s[i % n] == t[i % m];
    // For(i, 0, lc - 1) res += s[i % n] == t[i % m];
    // cout << res << endl;
    // cout << sol(r) << endl;
    return 0;
}
