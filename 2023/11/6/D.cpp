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
#define maxn 1000000
using namespace std;

int pri[maxn + 5], cnt = 0, vis[maxn + 5], f[maxn + 5], g[maxn + 5];
vector<int> d[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int prim[maxn + 5];
vector<pair<int, int> > ch[maxn + 5];

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

bool ma[maxn + 5], ok[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 2, maxn){
        if(!vis[i]){
            pri[++cnt] = i;
            f[i] = i;
            g[i] = 1; 
        }
        for(int j = 1; j <= cnt && pri[j] * i <= maxn; ++j){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0){
                f[i * pri[j]] = f[i];
                g[i * pri[j]] = g[i];
                break;
            }
            else{
                f[i * pri[j]] = f[i] * pri[j];
                g[i * pri[j]] = g[i] + 1;
            }
        }
    }
    f[1] = 1;
    vis[1] = 1;
    For(i, 1, maxn) vis[i] = !vis[i] + vis[i - 1];
    // int mx = 0;
    // For(i, 2, cnt) mx = max(mx, pri[i] - pri[i - 1]);
    // cout << mx << endl;
    // cout << "asd" << endl;

    For(i, 2, maxn) if(f[i] == i) for(int j = i * 2; j <= maxn; j += i) d[j].pb(i);
    memset(prim, inf, sizeof prim);
    int T;
    scanf("%d", &T);
    while(T--){
        int l, r;
        scanf("%d%d", &l, &r);
        if(vis[r] - vis[l - 1] == 0){
            For(i, l, r) For(j, i + 1, r){
                int w = g[i] + g[j] - g[gcd(i, j)];
                ch[i].pb({j, w});
                ch[j].pb({i, w});
            }
            prim[l] = 0;
            LL res = 0;
            For(_, 1, r - l + 1){
                int u = 0;
                For(i, l, r) if(!ma[i] && prim[i] < prim[u]) u = i; 
                res += prim[u];
                // cout << u << " " << prim[u] << endl;
                ma[u] = 1;
                for(auto [v, w] : ch[u]) if(!ma[v] && prim[v] > w) prim[v] = w;
            }
            // cout << T << endl;
            printf("%lld\n", res);
            For(i, l, r){
                prim[i] = inf;
                ma[i] = 0;
                ch[i].resize(0);
            }
            // For(i, l, r) ma[i] = 0;
        }
        else{
            LL res = 0;
            if(l == 1){
                For(i, 2, r) res += g[i];
                printf("%lld\n", res);
                continue;
            }
            For(i, l, r){
                if(!ma[f[i]]) ma[f[i]] = 1;
                else res += g[i];
            }
            For(i, l, r) if(!ok[f[i]]){
                int fl = 0, k = f[i];
                for(auto i : d[k]) if(ma[i]){
                    res += g[k];
                    fl = 1;
                    break;
                }
                if(!fl) res += g[k] + 1;
                ok[f[i]] = 1;
            }
            For(i, l, r) ma[f[i]] = ok[f[i]] = 0;
            printf("%lld\n", res - 2);
        }
    }
}
