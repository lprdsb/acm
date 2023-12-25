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
#define maxn 3000000
#define mod 998244353
using namespace std;

int n, res = 0;
LL a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    sort(a + 1, a + n + 1);
    For(o, 0, 32){
        int f = 0, g[2][2], h[2][2];
        For(i, 0, 1) For(j, 0, 1) g[i][j] = h[i][j] = 0;
        int oo = 1;
        Rof(i, n, 1){
            oo ^= 1;
            g[oo][0] = g[oo][1] = h[oo][0] = h[oo][1] = 0;
            int ty = (a[i] >> o) & 1;
            For(p, 0, 1){
                g[oo][p] = (1ll * g[oo ^ 1][p] + g[oo ^ 1][p ^ ty] + h[oo ^ 1][p ^ ty]) % mod;
                h[oo][p] = (1ll * h[oo ^ 1][p] + h[oo ^ 1][p ^ ty] % mod) % mod;
            }
            g[oo][ty] = (1ll * g[oo][ty] + a[i]) % mod;
            h[oo][ty] = (1ll * h[oo][ty] + a[i]) % mod;
            // if(o == 0 && i == n - 1){
            //     cout << g[oo][0] << " " << h[oo][0] << endl;
            // }
            f = (f + 1ll * a[i] * (g[oo ^ 1][1 ^ ty] + h[oo ^ 1][1 ^ ty] + ty * a[i]) % mod) % mod;
        }
        // if(o == 0) cout << f << endl;
        res = (res + (1ll << o) * f % mod) % mod;
    }
    printf("%d\n", res);
    return 0;
}
