#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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
#define maxn 100000
#define mod 1000000007
using namespace std;

int n;

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

LL P[maxn + 5];
LL sol(LL lim) {
    if(lim == -1) return 0;
    map<LL, LL> ma;
    ma[-lim] = 1;
    For(i, 1, n) {
        LL tem = 0;
        // cout << "asd" << endl;
        // for(auto [k, v] : ma) cout << k << " " << v << endl;
        while(ma.size() && -ma.begin()->fir >= P[i]) {
            pair<LL, LL> pa = *ma.begin();
            ma.erase(ma.begin());
            tem = (tem + (-pa.fir) / P[i] % mod * pa.sec % mod) % mod;
            LL to = -(-pa.fir) % P[i];
            if(to) ma[to] = (1ll * ma[to] + pa.sec) % mod;
        }
        if(tem) ma[-P[i] + 1] = (1ll * ma[-P[i] + 1] + tem) % mod;
    }
    int res = 0;
    for(auto [k, v] : ma) res = (res + (__int128_t)-k * (-k + 1) / 2 % mod * v % mod) % mod;
    return res;
}

LL L, R;

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    read(L); read(R);
    For(i, 1, n) {
        read(P[i]);
        if(P[i] == 1) {
            puts("0");
            return 0;
        }
    }
    printf("%lld\n", (1ll * sol(R) - sol(L - 1) + mod) % mod);
}
