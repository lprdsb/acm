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
#define maxn 2000
#define maxm 9000
#define N 1000000
#define mod 998244353
using namespace std;

int n, m, num[maxn + 5], f[maxm + 5], g[500][maxm + 5], ig[500][maxm + 5], ok[maxn + 5], bas = 1 << 13;
int sta[maxn + 5], id[maxn + 5], pri[maxn + 5], vis[maxn + 5], cnt = 0, to[maxn + 5];
int mul[N + 5], as[maxm + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void fwt(int *x, int gi){
    for(int i = 2; i <= bas; i <<= 1){
        int ii = i >> 1;
        for(int j = 0; j < bas; j += i){
            For(p, j, j + ii - 1)
                x[p + ii] = (1ll * x[p + ii] + gi * x[p] + mod) % mod;
        }
    }
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
	//freopen("in.txt", "r", stdin);
    memset(ok, -1, sizeof ok);
    mul[0] = 1;
    For(i, 1, N) mul[i] = 2ll * mul[i - 1] % mod;
    For(i, 0, N) mul[i] = (mul[i] - 1 + mod) % mod;
    For(i, 2, maxn){
        if(!vis[i]) pri[id[to[i] = i] = cnt++] = i;
        for(int j = 0; j < cnt && i * pri[j] <= maxn; ++j){
            vis[i * pri[j]] = 1;
            to[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    For(i, 1, maxn){
        int tem = i, s = 0;
        while(tem != 1){
            int tem1 = to[tem];
            while(tem % tem1 == 0) tem /= tem1;
            if(tem1 <= 41) s |= 1 << id[tem1];
            else ok[i] = id[tem1];
        }    
        sta[i] = s;
    }
    read(n);
    For(i, 1, n){
        int x; read(x);
        num[x]++;
    }
    f[0] = 1;
    For(i, 13, cnt) g[i][0] = 1;
    //cout << bas << endl;
    For(i, 1, maxn){
        if(!num[i]) continue;
        //cout << i << " " << sta[i] << endl;
        if(ok[i] == -1) Rof(o, bas - 1, 0)
            f[o | sta[i]] = (f[o | sta[i]] + 1ll * f[o] * mul[num[i]] % mod) % mod;
        else Rof(o, bas - 1, 0)
            g[ok[i]][o | sta[i]] = (g[ok[i]][o | sta[i]] + 1ll * g[ok[i]][o] * mul[num[i]] % mod) % mod;
    }
    fwt(f, 1);
    For(i, 13, cnt){
        fwt(g[i], 1);
        For(o, 0, bas - 1){
            f[o] = 1ll * f[o] * g[i][o] % mod;
            ig[i][o] = 1ll * (g[i][o] - 1 + mod) * fp(g[i][o], mod - 2) % mod;
        }
    }
    read(m);
    while(m--){
        int as_sta = 0, asi = 0;
        For(i, 0, bas - 1) as[i] = f[i];
        int c; read(c);
        For(i, 1, c){
            int x; read(x);
            if(x <= 41) as_sta |= 1 << id[x];
            else For(j, 0, bas - 1) as[j] = 1ll * as[j] * ig[id[x]][j] % mod;
        }
        fwt(as, -1);
        For(i, 0, bas - 1) if((i & as_sta) == as_sta) asi = (asi + as[i]) % mod;
        printf("%d\n", asi);
    }
    return 0;
}
