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

#define P 1000000007
#define maxn 2000
int n, a[maxn + 5], c[maxn + 5][maxn + 5], vis[2][maxn + 5], fac[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    fac[0] = 1;
    For(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % P;
    c[0][0] = 1;
    For(i, 1, n) {
        c[i][0] = 1;
        For(j, 1, i) c[i][j] = (1ll * c[i - 1][j] + c[i - 1][j - 1]) % P;
    }
    For(i, 1, n) read(a[i]);
    int tot = 0;
    For(i, 1, n) {
        if(a[i] != -1) vis[0][a[i]] = 1;
        else vis[1][i] = 1, tot++;
    }
    int cnt = 0;
    For(i, 1, n) if(!vis[0][i] && vis[1][i]) cnt++;
    // cout << vis[]
    int res = 0;
    For(i, 0, cnt) {
        int ok = (i & 1) ? P - 1 : 1;
        res = (res + 1ll * ok * c[cnt][i] % P * fac[tot - i] % P) % P;
    }
    cout << res << endl;
    // cout << cnt << " " << tot << endl;
}
