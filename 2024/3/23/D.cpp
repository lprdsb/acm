#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define i128 __int128_t
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
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

LL fp(LL x, LL y, LL P) {
    LL res = 1;
    while(y) {
        if(y & 1) res = (i128)res * x % P;
        x = (i128)x * x % P;
        y >>= 1;
    }
    return res;
}

LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }

int Miller_Rabin(LL x) {
    if(x < 3 || x % 2 == 0) return x == 2;
    LL u = x - 1, pri_bas[8] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
    int t = 0;
    while(u % 2 == 0) u >>= 1, t++;
    For(o, 0, 6) {
        LL now = fp(pri_bas[o], u, x);
        if(now <= 1) continue;
        For(i, 1, t) {
            if(now == x - 1) break;
            if(i == t) return 0;
            now = (i128)now * now % x;
            if(now == 1) return 0;
        }
    }
    return 1;
}

LL Pollard_Rho(LL x) {
    if(x == 4) return 2;
    if(Miller_Rabin(x)) return x;
    default_random_engine de;
    uniform_int_distribution<LL> rd(1, x - 1);
    while(666) {
        LL c = rd(de);
        auto f = [&](LL _x) {return ((i128)_x * _x + c) % x;};
        LL s = 0, t = 0;
        while(666) {
            LL p = 1;
            For(i, 1, 128) {
                s = f(s);
                t = f(f(t));
                if(s == t) break;
                LL tem = (i128)p * abs(s - t) % x;
                if(!tem) break;
                p = tem;
            }
            LL gc = gcd(p, x);
            if(gc > 1) return gc;
            if(s == t) break;
        }
    }
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

vector<LL> vec;
void sol(LL x) {
    LL tem = Pollard_Rho(x);
    if(tem == x) {
        vec.pb(x);
        return;
    }
    sol(tem); sol(x / tem);
}

int main() {
    int T;
    read(T);
    while(T--) {
        LL n, k; read(n); read(k); k %= mod - 1;
        vec.resize(0);
        sol(n);
        sort(vec.begin(), vec.end());
        // for(auto i : vec) cout << i << " "; cout << endl;
        vec.pb(-1);
        int pre = -1;
        int res = 1;
        For(i, 0, vec.size() - 2) if(vec[i] != vec[i + 1]) {
            LL up = k * (i - pre + 1) % (mod - 1);
            // cout << fp((fp(vec[i] % mod, k) - 1 + mod) % mod, mod - 2) % mod << endl;
            res = 1ll * res * ((1ll * fp(vec[i] % mod, up) - 1 + mod) % mod) % mod * fp((1ll * fp(vec[i] % mod, k) - 1 + mod) % mod, mod - 2) % mod;
            pre = i;
        }
        printf("%d\n", res);
    }
    return 0;
}

