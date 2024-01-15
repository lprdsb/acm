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

#define mod 1000000007

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int n, m, S, T;
vector<pair<int, int> > vec;

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    vec.pb({ S, 0 }); vec.pb({ T + 1, 0 });
    For(i, 1, m) {
        int x, l, r; read(x); read(l); read(r);
        vec.pb({ l, 1 });
        vec.pb({ r + 1, -1 });
    }
    int res = 1, now = 0, pre = S;
    sort(vec.begin(), vec.end());
    for(auto [k, v] : vec) {
        res = 1ll * res * fp(n - now, k - pre) % mod;
        pre = k;
        now += v;
    }
    printf("%d\n", res);
    return 0;
}
