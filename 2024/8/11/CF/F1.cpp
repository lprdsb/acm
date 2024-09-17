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

#define maxn 20000000
int vis[maxn + 5], pri[maxn + 5], cnt = 0, T, n, m, a, b, f[205][205];

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

void mian() {
    read(n); read(m); read(a); read(b);
    // cout << "asd" << endl;
    int t1 = n, t2;
    if(n <= 200) t1 = t2 = 0;
    else {
        // cout << t1 << " " << t2 << endl;
        while(vis[t1]) t1--;
        t2 = t1 - 1;
        while(vis[t2]) t2--;
    }
    LL res = 0;
    f[0][0] = 1;
    For(i, 0, n - t1) For(j, 0, m - t2) if(f[i][j]) {
        f[i + 1][j] |= gcd(t1 + i + 1, t2 + j) == 1;
        f[i][j + 1] |= gcd(t1 + i, t2 + j + 1) == 1;
        res = max(res, 1ll * a * (t1 + i) + 1ll * b * (t2 + j));
        res = max(res, 1ll * b * (t1 + i) + 1ll * a * (t2 + j));
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxn) {
        // cout << i << endl;
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && 1ll * i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    // cout << "asd" << endl;
    read(T);
    while(T--) {
        mian();
        For(i, 0, 200) For(j, 0, 200) f[i][j] = 0;
    }
}
