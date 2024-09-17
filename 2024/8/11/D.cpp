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

#define maxn 200000
int T, n, m;
int dis[maxn + 5], as[maxn + 5];
vector<int> ch[maxn + 5], ch1[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[v].pb(u);
        ch1[u].pb(v);
    }
    dis[1] = 0;
    For(i, 2, n) {
        dis[i] = dis[i - 1] + 1;
        for(auto v : ch[i]) dis[i] = min(dis[i], dis[v] + 1);
    }
    // cout << dis[5] << endl;
    multiset<int> se;
    Rof(i, n, 1) {
        for(auto v : ch1[i]) se.erase(se.find(-(v - dis[i] - 1)));
        // if(i == 6) cout << -*se.begin() << endl;
        if(se.size() && -*se.begin() > i) as[i] = 1;
        else as[i] = 0;
        for(auto v : ch[i]) se.insert(-(i - dis[v] - 1));
    }
    For(i, 1, n - 1) printf("%d", !as[i]);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            ch1[i].resize(0);
        }
    }
}
