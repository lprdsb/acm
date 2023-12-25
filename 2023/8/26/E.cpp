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
#define maxn 200000
#define mod 998244353
using namespace std;

int t, n, a[maxn + 5];
int tot = 0, ch[40 * maxn + 5][2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int sz[40 * maxn + 5];
void ins(int x){
    int now = 0;
    Rof(i, 29, 0){
        int o = (x >> i) & 1;
        if(!ch[now][o]) ch[now][o] = ++tot;
        now = ch[now][o];
        sz[now]++;
    }
}

int as = 0;
void dfs(int u, int dep){
    // cout << u << " " << ch[u][0] << " " << ch[u][1] << endl;
    For(o, 0, 1) if(ch[u][o]){
        dfs(ch[u][o], dep + o);
    }
    as = (as + 1ll * sz[ch[u][0]] * sz[ch[u][1]] % mod * (2ll * dep % mod + 3) % mod) % mod;
    if(!ch[u][0] && !ch[u][1]) as = (as + 1ll * sz[u] * sz[u] % mod * (dep + 1) % mod) % mod;
}

int fp(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n) read(a[i]), ins(a[i]);
        as = 0;
        dfs(0, 0);
        printf("%d\n", 1ll * as * fp(1ll * n * n % mod, mod - 2) % mod);
        For(i, 0, tot) ch[i][0] = ch[i][1] = sz[i] = 0;
        tot = 0;
    }
    return 0;
}
