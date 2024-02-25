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

#define maxn 500000
#define mod 998244353
int T, n, m;
int ch[maxn + 5][2], val[maxn + 5];

int tot = 0;
vector<pair<int, int> > vec;
void dfs(int u) {
    if(u == -1) return;
    dfs(ch[u][0]);
    tot++;
    if(val[u] != -1) vec.pb({ val[u], tot });
    dfs(ch[u][1]);
}

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int c(int x, int y) {
    int res = 1;
    For(i, 1, y) res = 1ll * res * (x - i + 1) % mod;
    For(i, 1, y) res = 1ll * res * fp(i, mod - 2) % mod;
    return res;
}

void mian() {
    read(n); read(m);
    For(i, 1, n) {
        read(ch[i][0]); read(ch[i][1]); read(val[i]);
    }
    tot = 0;
    dfs(1);
    pair<int, int> pre = { 1, 0 };
    int res = 1;
    vec.pb({ m, n + 1 });
    for(auto i : vec) {
        res = 1ll * res * c(i.fir - pre.fir + i.sec - pre.sec - 1, i.sec - pre.sec - 1) % mod;
        pre = i;
    }
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        vec.resize(0);
    }
}
