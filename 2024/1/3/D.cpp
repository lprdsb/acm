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
int T, n, phi[maxn + 5], pri[maxn + 5], vis[maxn + 5], cnt = 0;
vector<int> vec[maxn + 5];
int sum[maxn + 5], a[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    phi[1] = 1;
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i, phi[i] = i - 1;
        for(int j = 1; j <= cnt && pri[j] * i <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            else phi[i * pri[j]] = phi[i] * (pri[j] - 1);
        }
    }
    For(i, 1, maxn) for(int j = i; j <= maxn; j += i) vec[j].pb(i);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) read(a[i]);
        sort(a + 1, a + n + 1);
        LL res = 0;
        For(i, 1, n) {
            for(auto j : vec[a[i]]) res += 1ll * sum[j] * phi[j] * (n - i);
            for(auto j : vec[a[i]]) sum[j]++;
        }
        printf("%lld\n", res);
        For(i, 1, maxn) sum[i] = 0;
    }
    return 0;
}
