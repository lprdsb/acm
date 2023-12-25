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
#define maxn 100000
using namespace std;

int n, a[maxn + 5], f[maxn + 5][35], g[maxn + 5][35], q, to[maxn + 5];

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
    memset(f, -1, sizeof -1);
    read(n);
    to[1] = 1;
    For(i, 0, 20){
        to[1 << i] = i;
        if((1 << i) > n) break;
    }
    For(i, 1, n) read(a[i]);
    Rof(i, n, 1){
        f[i][0] = a[i];
        int now = 1;
        For(j, 1, 20){
            if(i + now > n || f[i + now][j - 1] == -1) continue;
            g[i][j] = g[i][j - 1] + g[i + now][j - 1];
            f[i][j] = f[i][j - 1] + f[i + now][j - 1];
            if(f[i][j] >= 10) f[i][j] -= 10, g[i][j]++;
            now <<= 1;
        }
    }
    read(q);
    while(q--){
        int l, r, lim; read(l); read(r);
        printf("%d\n", g[l][to[r - l + 1]]);
    }
    return 0;
}
