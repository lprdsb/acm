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

#define maxn 4000000
int T, n, m;
int pri[maxn + 5], cnt = 0, vis[maxn + 5], to[maxn + 5], mx[maxn + 5];

void mian() {
    read(n); read(m);
    LL res = 0;
    For(i, 2, n + m) {
        int j = mx[i];
        int r = n / j, l = i / j - m / j;
        l = max(1, l);
        r = min(i / j - 1, r);
        res += max(0, r - l + 1);
    }
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i, to[i] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            to[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    For(i, 1, maxn) {
        int tem = i; mx[i] = 1;
        while(tem != 1) {
            int p = to[tem], cc = 0;
            while(tem % p == 0) tem /= p, cc++;
            For(j, 1, (cc + 1) / 2) mx[i] *= p;
        }
    }
    read(T);
    while(T--) {
        mian();
    }
}
