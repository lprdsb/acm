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
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int mod = 998244353;
int fast_power(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return asi;
}

int prime[100001], vis[100001], cnt = 0;
void select_prime(int maxn){
    for(int i = 2; i <= maxn; ++i){
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] <= maxn; ++j){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= cnt; ++i) cout << prime[i] << " "; cout << endl;
}

int factorial[100001], ifactorial[100001];
void c_init(int maxn){
    factorial[0] = 1;
    for(int i = 1; i <= maxn; ++i) factorial[i] = 1ll * factorial[i - 1] * i % mod;
    ifactorial[maxn] = fast_power(factorial[maxn], mod - 2);
    for(int i = maxn - 1; i >= 0; --i) ifactorial[i] = 1ll * ifactorial[i + 1] * (i + 1) % mod;
}
int c(int x, int y){return 1ll * factorial[x] * ifactorial[y] % mod * ifactorial[x - y] % mod;}

int main(){
	//freopen("in", "r", stdin);
    cout << fast_power(2, 10) << endl;
    select_prime(100);
    c_init(100);
    cout << c(10, 2) << endl;
    return 0;
}
