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

#define maxn 2000000
int T, n, pri[maxn + 5], vis[maxn + 5], cnt = 0, ma[2000][2000];

int st[maxn + 5], tp = 0;
int x = 1;
void dfs(int u) {
    For(i, 1, x) if(ma[u][i]) {
        ma[u][i] = ma[i][u] = 0;
        dfs(i);
    }
    if(!vis[u]) st[++tp] = u;
    vis[u] = 1;
    st[++tp] = u;
}

void mian() {
    read(n); x = 1;
    while(666) {
        x++;
        int tot = x * (x + 1) / 2;
        if(x % 2 == 0) tot -= x / 2 - 1;
        if(tot >= n - 1) break;
    }
    For(i, 1, x) For(j, 1, x) if(i != j) ma[i][j] = 1;
    if(x % 2 == 0) {
        For(i, 3, x) {
            ma[i][i + 1] = ma[i + 1][i] = 0;
            i++;
        }
    }
    For(i, 1, x) vis[i] = 0;
    tp = 0;
    dfs(1);
    assert(tp >= n);
    Rof(i, tp, tp - n + 1) printf("%d ", pri[st[i]]); puts("");
}

int main() {
    //freopen("in", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    read(T);
    while(T--) {
        mian();
        For(i, 1, x) For(j, 1, x) ma[i][j] = 0;
    }
}
