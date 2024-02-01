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
#define maxn 250000
int n, m, a[maxn + 5], vis[maxn + 5], vis1[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m) read(a[i]), vis[a[i]] = 1;
    int pos = 0;
    For(i, 1, m) if(a[i] > a[i + 1]) {
        pos = i;
        break;
    }
    For(i, 1, a[1]) if(!vis[i]) {
        puts("0");
        return 0;
    }
    For(i, 1, pos) vis1[a[i]] = 1;
    int res = 1, now = 0;
    For(i, a[1], a[pos]) {
        if(vis1[i]) {
            now++;
            continue;
        }
        if(vis[i]) continue;
        res = 1ll * res * now % mod;
        now++;
    }
    now++;
    For(i, a[pos] + 1, n) if(!vis[i]) {
        res = 1ll * res * now % mod;
        now++;
    }
    printf("%d\n", res);
}
