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

#define mod 998244353
#define maxn 100
#define maxm 10000
int n, m, k, f[3][maxn + 5][maxn + 5];

vector<int> ch[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    int o = 0;
    For(i, 1, n) f[o][i][i] = 1;
    For(len, 0, k - 1) {
        For(i, 1, n) For(j, 1, n) if(f[o][i][j]) {
            
        }
    }
}
