#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
typedef long long ll;
using namespace std;

const int N = 1e6 + 7;
vector<int>G[N];
int siz[N];
int rt;
int n;
int cnt[N];
int vol[N], tot;

void dfs(int u, int fa) {
    siz[u] = 1;
    for(int v : G[u]) {
        if(v ^ fa) {
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
    bool ok = true;
    for(int v : G[u])if(siz[v] > n / 2)ok = false;
    if(n - siz[u] > n / 2)ok = false;
    if(ok)rt = u;
}

void solve() {
    scanf("%d", &n);
    fs(i, 2, n) {
        int x;
        scanf("%d", &x);
        G[i].emplace_back(x);G[x].emplace_back(i);
    }
    dfs(1, 0);
    int hhh = rt;
    dfs(rt, 0);rt = hhh;
    ll ans = 0;
    fs(i, 1, n)ans = ans + siz[i];
    for(int v : G[rt])cnt[siz[v]]++;
    fs(i, 1, n) {
        if(cnt[i]) {
            int num = 1;
            while(cnt[i] >= num) {
                vol[++tot] = num * i;
                cnt[i] -= num;
                num <<= 1;
            }
            vol[++tot] = cnt[i] * i;
        }
    }
    bitset<N / 2>dp;dp[0] = 1;
    fs(i, 1, tot)dp |= (dp << vol[i]);
    fn(i, (n - 1) / 2, 0) {
        if(dp[i]) {
            ans = ans + (ll)i * (n - 1 - i);
            break;
        }
    }
    printf("%lld\n", ans);
}

signed main() {
    int T = 1;while(T--) {
        solve();
    }
}