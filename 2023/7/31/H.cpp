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
#define maxn 200
#define maxm 100000
using namespace std;

int n, m, cnt = 0, sz[maxm + 5];
LL f[maxn + 5][maxn + 5][maxn + 5], a[maxn + 5], b[maxn + 5], g[maxn + 5][maxn + 5], as = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]), read(b[i]);
    For(i, 1, m){
        int x; read(x);
        if(m - i + 1 <= 200) sz[++cnt] = x;
    }
    For(i, 1, 200) For(l, 1, n) For(r, l, n){
        f[i][l][r] = f[i][l][r - 1];
        if(i >= a[r]) f[i][l][r] = max(f[i][l][r], f[i - a[r]][l][r - 1] + b[r]);
        // if(i == 7)
    }
    // cout << f[7][2][4] << endl;
    For(i, 1, n){
        For(j, 1, cnt){
            For(p, 1, i){
                g[i][j] = max(g[i][j], g[p - 1][j - 1] + f[sz[j]][p][i]);
                as = max(as, g[i][j]);
            }
        }
    }
    printf("%lld\n", as);
    return 0;
}
