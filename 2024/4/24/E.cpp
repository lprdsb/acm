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
int pri[maxn + 5], vis[maxn + 5], cnt = 0;
vector<int> vec[maxn + 5];

#define mod 1000000007
int as[maxn + 5], sum = 0, num[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    For(i, 1, cnt) for(int j = pri[i]; j <= maxn; j += pri[i]) vec[j].pb(pri[i]);
    for(int i = 4; i <= maxn; i += 4) vec[i].pb(4);
    For(i, 1, maxn) {
        for(auto j : vec[i]) {
            sum = (sum - 1ll * num[j] * (j == 4 ? 2 : j - 1) % j + mod) % mod;
            num[j]++;
            sum = (sum + 1ll * num[j] * (j == 4 ? 2 : j - 1) % j) % mod;
        }
        as[i] = (1ll * as[i - 1] + sum) % mod;
    }
    // cout << as[314159] << endl;
    int T; read(T);
    while(T--) {
        int n; read(n);
        printf("%d\n", as[n]);
    }
}
