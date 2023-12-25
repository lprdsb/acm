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
#define mod 1000000007
#define maxn 100000
using namespace std;

int m, pri[maxn + 5], vis[maxn + 5], cnt = 0, miu[maxn + 5], as = 1, inv[maxn + 5];

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

int main(){
	//freopen("in", "r", stdin);
    read(m);
    miu[1] = 1;
    For(i, 2, m){
        if(!vis[i]) pri[++cnt] = i, miu[i] = mod - 1;
        for(int j = 1; j <= cnt && pri[j] * i <= m; ++j){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
            else miu[i * pri[j]] = mod - miu[i];
        }
    }
    For(i, 1, m) inv[i] = fp(m - m / i, mod - 2);
    For(i, 1, m) if(miu[i]){
        int tem = 0;
        For(j, 2, m){
            if(i * j > m) break;
            int now = m / j, to = min(m, m / now);
            tem = (tem + 1ll * (to - j + 1) * (now / i) % mod * inv[i * j] % mod) % mod;
            j = to;
        }
        as = (as + 1ll * miu[i] * tem % mod) % mod;
    }
    printf("%d\n", as);
    return 0;
}
