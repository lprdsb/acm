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
#define mod 998244353
#define maxn 1000000
using namespace std;

int n, m, hd[maxn + 5], len = 0;
struct Edge{
    int v, w, net;
} e[2 * maxn + 5];
void add(int u, int v, int w){
    e[len] = {v, w, hd[u]};
    hd[u] = len++;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int dep[maxn + 5], pty[maxn + 5], fa[maxn + 5], tp[maxn + 5], prew[maxn + 5];
void dfs1(int u, int pre){
    dep[u] = dep[pre] + 1;
    fa[u] = pre;
    Tra(u, i){
        int v = e[i].v, w = e[i].w;
        if(v == pre) continue;
        if(!dep[v]) dfs1(v, u);
        else{
            if(dep[v] > dep[u]){
                pty[u] = 1;
                int now = v;
                while(now != u) tp[now] = u, now = fa[now];
                tp[u] = u;
            }
            else pty[u] = 2, prew[u] = w;
        }
    }
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
int inv3 = fp(3, mod - 2);
int get_g(int x){
    int res = fp(2, x - 1);
    if(x & 1) res += 2;
    else res -= 2;
    if(res < 0) res += mod;
    if(res >= mod) res -= mod;
    return 1ll * res * inv3 % mod;
}
int get_h(int x){
    int res = fp(2, x - 1);
    if(x & 1) res--;
    else res++;
    if(res < 0) res += mod;
    if(res >= mod) res -= mod;
    return 1ll * res * inv3 % mod;
}

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int f[maxn + 5][4][2][4][2], g[4][2][4][2];
void dfs2(int u, int pre){
    if(pty[u] == 2){
        if(!prew[u]){
            For(cu, 1, 3) For(o1, 0, 1) f[u][cu][o1][cu][o1] = 1;
        }
        else{
            int gw = get_g(prew[u] + 1), hw = get_h(prew[u] + 1);
            For(cu, 1, 3) For(o1, 0, 1) For(cs, 1, 3){
                if(cu == cs) f[u][cu][o1][cs][o1] = gw;
                else f[u][cu][o1][cs][o1] = hw;
            }
        }
    }
    else{
        if(tp[u]){
            For(cu, 1, 3) For(o1, 0, 1) For(cs, 1, 3) f[u][cu][o1][cs][0] = 1;
        }
        else{
            For(cu, 1, 3) f[u][cu][0][0][0] = 1;
        }
    }
    Tra(u, i){
        int v = e[i].v, w = e[i].w + 2, gw = get_g(w), hw = get_h(w);
        if(v == pre || dep[v] != dep[u] + 1) continue;
        dfs2(v, u);
        if(tp[u]){
            if(tp[v] == tp[u]){
                For(cu, 1, 3) For(o1, 0, 1) For(cs, 1, 3) For(o2, 0, 1){
                    add(g[cu][o1][cs][o2], 1ll * f[u][cu][o1][cs][o2] * gw % mod * f[v][cu][o1][cs][0] % mod);
                    add(g[cu][o1][cs][o2 ^ 1] ,1ll * f[u][cu][o1][cs][o2] * gw % mod * f[v][cu][o1][cs][1] % mod);
                    For(cv, 1, 3) if(cu != cv){
                        add(g[cu][o1][cs][o2], 1ll * f[u][cu][o1][cs][o2] * hw % mod * f[v][cv][o1][cs][0] % mod);
                        add(g[cu][o1][cs][o2 ^ 1], 1ll * f[u][cu][o1][cs][o2] * hw % mod * f[v][cv][o1][cs][1] % mod);
                    }
                }
            }
            else{
                For(cu, 1, 3) For(o1, 0, 1) For(cs, 1, 3) For(o2, 0, 1){
                    add(g[cu][o1][cs][o2], 1ll * f[u][cu][o1][cs][o2] * gw % mod * f[v][cu][0][0][0] % mod);
                    add(g[cu][o1][cs][o2 ^ 1], 1ll * f[u][cu][o1][cs][o2] * gw % mod * f[v][cu][0][0][1] % mod);
                    For(cv, 1, 3) if(cu != cv){
                        add(g[cu][o1][cs][o2], 1ll * f[u][cu][o1][cs][o2] * hw % mod * f[v][cv][0][0][0] % mod);
                        add(g[cu][o1][cs][o2 ^ 1], 1ll * f[u][cu][o1][cs][o2] * hw % mod * f[v][cv][0][0][1] % mod);
                    }
                }
            }
        }
        else{
            For(cu, 1, 3) For(o2, 0, 1){
                add(g[cu][0][0][o2], 1ll * f[u][cu][0][0][o2] * gw % mod * f[v][cu][0][0][0] % mod);
                add(g[cu][0][0][o2 ^ 1], 1ll * f[u][cu][0][0][o2] * gw % mod * f[v][cu][0][0][1] % mod);
                For(cv, 1, 3) if(cu != cv){
                    add(g[cu][0][0][o2], 1ll * f[u][cu][0][0][o2] * hw % mod * f[v][cv][0][0][0] % mod);
                    add(g[cu][0][0][o2 ^ 1], 1ll * f[u][cu][0][0][o2] * hw % mod * f[v][cv][0][0][1] % mod);
                }
            }
        }
        For(cu, 1, 3) For(o1, 0, 1) For(cs, 0, 3) For(o2, 0, 1){
            f[u][cu][o1][cs][o2] = g[cu][o1][cs][o2];
            g[cu][o1][cs][o2] = 0;
        }
    }
    if(pty[u] == 1){
        For(cu, 1, 3) For(o1, 0, 1) For(cs, 1, 3) For(o2, 0, 1) if(cu != cs)
            add(g[cu][0][0][(!o1) ^ o2], f[u][cu][o1][cs][o2]);
        For(cu, 1, 3) For(o2, 0, 1){
            f[u][cu][0][0][o2] = g[cu][0][0][o2];
            g[cu][0][0][o2] = 0;
        }
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 1, m){
        int u, v, w; read(u); read(v); read(w);
        add(u, v, w);
        add(v, u, w);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int res = 0;
    For(cu, 1, 3) res = (res + f[1][cu][0][0][1]) % mod;
    printf("%d\n", res);
    return 0;
}
