#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define ULL unsigned LL
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 6000000
#define mod 998244353
using namespace std;

int t, n, k, fac[maxn + 5], ifac[maxn + 5], f[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return asi;
}

int c(int x, int y){return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;}

ULL val[maxn + 5], val1[maxn + 5];
void add(int l, int r){
    ULL tem = (ULL)rand() * rand() * rand() * rand() * rand() * rand();
    ULL tem1 = (ULL)rand() * rand() * rand() * rand() * rand() * rand();
    val[l] ^= tem;
    val[r + 1] ^= tem;
    val1[l] ^= tem1;
    val1[r + 1] ^= tem1;
}

map<ULL, map<ULL, int> > ma;
int main(){
	// freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * i * fac[i - 1] % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    f[0] = 1;
    for(int i = 2; i <= maxn; i += 2) f[i] = 1ll * c(i, i / 2) * ifac[i / 2 + 1] % mod * fac[i / 2] % mod;
    read(t);
    while(t--){
        read(n); read(k);
        For(i, 0, k){
            int l = 1, r = n;
            if(i) read(l), read(r);
            add(l, r);
        }
        // for(auto i : ma) for(auto j : i.sec) cout << j.sec << " "; cout << endl;
        For(i, 1, n){
            val[i] ^= val[i - 1];
            val1[i] ^= val1[i - 1];
            ma[val[i]][val1[i]]++;
        }
        int asi = 1;
        for(auto i : ma) for(auto j : i.sec){
            asi = 1ll * asi * f[j.sec] % mod;
            // if(n == 6) cout << j.sec << endl;
        }
        printf("%d\n", asi);
        For(i, 1, n + 1) val[i] = val1[i] = 0;
        // for(auto i : ma) i.sec.clear();
        ma.clear();
    }
	return 0;
}
