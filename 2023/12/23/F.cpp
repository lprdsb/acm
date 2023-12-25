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

#define maxn 200000
int T, a[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define mod 998244353
int n;
void sol() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 2, n) if(a[i] < a[i - 1] || a[i] - a[i - 1] > 2) {
        puts("0");
        return;
    }
    if(a[n] != n || a[1] >= 2) {
        puts("0");
        return;
    }
    int res = 1, now = 0, tt = 0;
    For(i, 1, n) {
        if(a[i] - a[i - 1] == 0) {
            now++;
            tt++;
        }
        else if(a[i] - a[i - 1] == 1) {
            res = 1ll * res * (now + tt + 1) % mod;
        }
        else {
            res = 1ll * res * now % mod * tt % mod;
            now--;
            tt--;
        }
        if(now < 0 || tt < 0) {
            puts("0");
            return;
        }
    }
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        sol();
    }
}
