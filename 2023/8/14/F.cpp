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
#define maxn 60
#define mod 1000000007
using namespace std;

int T, N, M, X, Y, B[maxn + 5], ok[2][maxn + 5][maxn + 5], cnt[1 << 16], num[maxn + 5], fac[maxn + 5], ifac[maxn + 5], vis[1 << 16], c[maxn + 5][maxn + 5];
vector<pair<int, int> > to[1 << 16][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
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

inline void add(int &x, cst int &y){
    LL tem = x + y;
    if(tem >= mod) tem -= mod;
    x = tem;
}

vector<int> sta;
int f[2][1 << 16];
int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 0, (1 << 16) - 1) cnt[i] = cnt[i >> 1] + (i & 1);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    For(i, 0, maxn) For(j, 0, i) c[i][j] = 1ll * fac[i] * ifac[j] % mod * ifac[i - j] % mod;
    read(T);
    while(T--){
        read(N); read(M); read(X); read(Y);
        For(i, 1, M) read(B[M - i + 1]);
        For(i, 1, X){
            int u, v; read(u); read(v);
            ok[0][u][v] = 1;
        }
        For(i, 1, Y){
            int u, v; read(u); read(v);
            ok[1][u][v] = 1;
        }
        
        int tot = 0;
        For(i, 1, M) tot += B[i] != 0;
        For(i, 0, (1 << tot) - 1) vis[i] = 0;
        sta.resize(0);
        For(i, 0, (1 << tot) - 1){
            vis[i] = 1;
            For(j, 1, tot) if(!((i >> (j - 1)) & 1) && ((i >> j) & 1) && B[j] == B[j + 1]){
                vis[i] = 0;
                break;
            }
            if(vis[i]) sta.pb(i);
        }
        for(auto i : sta){
            For(j, 1, M) to[i][j].resize(0);
            For(j, 1, tot) if(!((i >> (j - 1)) & 1) && vis[i | (1 << (j - 1))]) For(p, 1, M)
                if(!ok[1][p][B[j]]) to[i][p].pb({j, i | (1 << (j - 1))});
        }
        // cout << sta.size() << endl;
        int as = 0;
        For(o1, 0, (1 << N) - 1){
            For(i, 1, M) num[i] = cnt[o1];
            For(i, 1, N) if((o1 >> (i - 1)) & 1) For(j, 1, M) if(ok[0][i][j]) num[j]--;
            int o2 = 0;
            for(int i : sta) f[0][i] = 0;
            f[0][0] = 1;
            For(i, 1, M){
                int o3 = o2;
                o2 ^= 1;
                for(int j : sta) f[o2][j] = 0;
                for(int j : sta) if(f[o3][j]){
                    for(auto p : to[j][i]) add(f[o2][p.sec], 1ll * f[o3][j] * c[B[p.fir] + num[i] - 1][num[i] - 1] % mod);
                    if(!ok[1][i][0]) add(f[o2][j], f[o3][j]);
                }
            }
            int res = f[o2][(1 << tot) - 1];
            if((N - cnt[o1]) & 1) res = mod - res;
            add(as, res);
        }
        // For(i, 1, M) as = 1ll * as * ifac[B[i]] % mod;
        printf("%d\n", as);

        For(i, 0, N) For(j, 0, M) ok[0][i][j] = ok[1][j][i] = 0;
    }
    return 0;
}
