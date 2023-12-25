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

LL t, a, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL gcd(LL x, LL y){return y ? gcd(y, x % y) : x;}

LL get_phi(LL x){
    LL res = 1;
    for(LL i = 2; i * i <= x; ++i){
        if(x % i == 0){
            res *= (i - 1);
            x /= i;
            while(x % i == 0){
                x /= i;
                res *= i;
            }
        }
    }
    if(x != 1) res *= x - 1;
    return res;
}

LL fp(LL x, LL y, LL mod){
    int fl = 0;
    LL res = 1;
    if(x >= mod) x %= mod, fl = 1;
    while(y){
        if(y & 1){
            res = (__int128_t)res * x % mod;
        }
        x = (__int128_t)x * x % mod;
        y >>= 1;
    }
    return res;
}

LL sol(LL mod1, LL mod2){
    if(mod1 * mod2 == 1) return 1;
    LL gc = gcd(mod1, mod2);
    // cout << mod1 << " " << mod2 << " " << gc << " " << get_phi(gc) << endl;
    assert(get_phi(mod1) / get_phi(gc) * gc <= mod1);
    LL res = fp(a, sol(get_phi(mod1) / get_phi(gc) * gc, get_phi(mod2)), mod1 * mod2) + mod1 * mod2;
    return res;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(a); read(m);
        LL phi = get_phi(m), tem = m / gcd(phi, m), res = sol(phi, tem) - phi * tem;
        if(res <= phi) res += phi * tem;
        printf("%lld\n", res);
        // cout << fp(a, res, m) << " " << res % m << endl;
    }
    return 0;
}
