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

int T, n, m;
#define maxn 500000
int vis[maxn + 5];

void mian() {
    read(n); read(m);
    int mx = 0;
    For(i, 1, n) {
        vector<int> vec;
        int l; read(l);
        For(j, 1, l) {
            int x; read(x);
            if(x >= maxn) continue;
            vis[x] = 1;
            vec.pb(x);
        }
        int now = 0;
        while(vis[now]) now++;
        int tmp = now;
        vis[now] = 1;
        while(vis[now]) now++;
        mx = max(mx, now);
        for(auto v : vec) vis[v] = 0;
        vis[tmp] = 0;
    }
    if(mx > m) printf("%lld\n", 1ll * (m + 1) * mx);
    else printf("%lld\n", 1ll * mx * (mx + 1) + 1ll * (m + mx + 1) * (m - mx) / 2);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
