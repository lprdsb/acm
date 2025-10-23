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

#define maxn 100000
int T, n, m, p, a[maxn + 5];
vector<int> vec;
LL res = 0;

void mian() {
    read(m); read(n); read(p);
    For(i, 1, m) read(a[i]), a[i]--;
    res = 0;
    vec.resize(0);
    For(i, 1, p) {
        int x, y; read(x); read(y);
        res += a[x] - y + 1ll * (y - a[x] + n - 1) / n * n;
        vec.pb(((a[x] - y) % n + n) % n);
    }
    sort(vec.begin(), vec.end());
    LL mn = res;
    int pre = 0;
    for(auto v : vec) {
        res -= 1ll * (v - pre) * p;
        mn = min(mn, res);
        res += n;
        pre = v;
    }
    printf("%lld\n", mn);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
