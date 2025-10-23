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

#define P 998244353
#define maxn 200000
int n, m, f[maxn + 5], vis[maxn + 5], l, r;

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(l); read(r);
    For(i, 1, m) {
        int x; read(x);
        vis[x] = 1;
    }
    vis[0] = 1;
    f[0] = 1; f[1] = -1;
    int now = 0;
    For(i, 0, n) {
        now = (now + f[i]) % P;
        // cout << i << " "  << now << endl;
        if(i == n) break;
        if(vis[i]) {
            f[i + l] = (f[i + l] + now) % P;
            f[i + r + 1] = (f[i + r + 1] - now + P) % P;
        }
    }
    printf("%d\n", now);
}
