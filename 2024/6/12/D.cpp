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

#define maxn 1000000
int n, a[maxn + 5], pri[maxn + 5], vis[maxn + 5], miu[maxn + 5], cnt;
vector<int> vec[maxn + 5];
int sum[maxn + 5], f[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) vis[i] = f[i] = sum[i] = 0;
    For(i, 1, n) {
        vis[a[i]] = 1;
        for(auto j : vec[a[i]]) sum[j]++;
    }
    For(i, 1, n) if(vis[i]) for(int j = 2 * i; j <= n; j += i) vis[j] = 1;
    For(i, 1, n) if(!vis[i]) for(int j = i; j <= n; j += i) f[j] += miu[j / i];
    LL res = 0;
    For(i, 1, n) res += 1ll * sum[i] * sum[i] * f[i];
    printf("%lld\n", res / 2);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxn) for(int j = i; j <= maxn; j += i) vec[j].pb(i);
    miu[1] = 1;
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i, miu[i] = -1;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
            else miu[i * pri[j]] = -miu[i];
        }
    }
    int T; read(T);
    while(T--) {
        mian();
    }
}
