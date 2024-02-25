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

int T, n, q;

#define maxn 10000000
bool vis[2][maxn + 5];
int res = 0, all = 0, L = 0;
void sol(int o, int x) {
    if(vis[o][x]) return;
    vis[o][x] = 1;
    if(vis[o ^ 1][x]) res = max(res, x);
    Rof(o1, L, 0) if((x >> o1) & 1) sol(o, x ^ (1 << o1));
}

void mian() {
    read(n); read(q);
    L = log2(n) + 1;
    all = (1 << L) - 1;
    while(q--) {
        int x; read(x);
        x = (x + res) % n;
        sol(0, x); sol(1, all ^ x);
        printf("%d ", res);
    }
    puts("");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        res = 0;
        For(o, 0, 1) For(i, 0, all) vis[o][i] = 0;
    }
}
