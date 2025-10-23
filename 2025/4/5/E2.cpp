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

#define maxn 5000
#define P 1000000007
int T, n, a[maxn + 5], fac[maxn + 5], ifac[maxn + 5], b[maxn + 5];
int sum[maxn + 5];

vector<int> vec[maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

void mian() {
    read(n);
    For(i, 1, n) {
        read(a[i]);
        if(a[i] != -1) b[a[i]] = i;
    }
    int mn = n, c = 0, cnt = 0;
    For(i, 1, n) cnt += a[i] == -1;
    For(i, 1, n) {
        int mn1 = mn, c1 = c;
        sum[c1]++;
        vec[mn1].pb(c1);
        Rof(j, n, i + 1) {
            if(a[j] != -1) mn1 = min(mn1, a[j]);
            else c1++;
            sum[c1]++;
            vec[mn1].pb(c1);
        }
        if(a[i] != -1) mn = min(mn, a[i]);
        else c++;
    }
    int res = 0, t = cnt;
    For(lim, 0, n) {
        for(auto i : vec[lim]) sum[i]--;
        t -= b[lim] == -1;
        For(i, 0, t) res = (res + 1ll * sum[i] * fac[t] % P * fac[cnt - i] % P * ifac[t - i] % P) % P;
    }
    printf("%d\n", res);
}

int main() {
    memset(a, -1, sizeof a);
    memset(b, -1, sizeof b);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    ifac[maxn] = fp(fac[maxn], P - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n) {
            a[i] = b[i] = -1;
            vec[i].resize(0);
            sum[i] = 0;
        }
    }
}
