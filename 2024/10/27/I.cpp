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
int n, s, t;
struct Seg {
    int l, r, h;
} seg[maxn + 5];
vector<int> vec[maxn + 5];
int dis[2][maxn + 5], vis[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(s); read(t);
    For(i, 1, n) {
        int l, r, h; read(l); read(r); read(h);
        seg[i] = { l, r, h };
        vec[h].pb(i);
    }
    memset(dis, inf, sizeof dis);
    int o = 0; dis[o][seg[s].l] = 0;
    int pre = seg[s].h;
    Rof(h, seg[s].h, 1) if(vec[h].size()) {
        For(i, 1, maxn) {
            if(!vis[i]) dis[o ^ 1][i] = dis[o][i] + pre - h;
            vis[i] = 0;
        }
        for(auto i : vec[h]) {
            auto [l, r, h] = seg[i];
            For(j, l, r) vis[j] = 1 + (i == t);
        }
        For(i, 1, maxn) if(vis[i]) dis[o ^ 1][i] = min(dis[o ^ 1][i], dis[o ^ 1][i - 1] + 1);
        Rof(i, maxn, 1) if(vis[i]) dis[o ^ 1][i] = min(dis[o ^ 1][i], dis[o ^ 1][i + 1] + 1);

        int res = inf;
        For(i, 1, maxn) {
            if(vis[i] == 2) res = min(res, dis[o ^ 1][i]);
            dis[o][i] = inf;
        }
        if(res != inf) {
            printf("%d\n", res);
            return 0;
        }
        for(auto i : vec[h]) {
            auto [l, r, h] = seg[i];
            vis[l] = vis[r] = 0;
        }
        pre = h;
        o ^= 1;
    }
    puts("-1");
}
