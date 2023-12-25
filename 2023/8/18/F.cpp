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
#define maxn 300
#define mod 1000000007
using namespace std;

int n, t, k, m, a[maxn + 5], bas, cnt[2000];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int f[2][20][2050];
void add(int &x, int y){
    LL tem = x + y;
    if(tem >= mod) tem -= mod;
    x = tem;
}
int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(t); read(k); read(m); bas = (1 << (k - 1)) - 1;
    For(i, 0, bas) cnt[i] = cnt[i >> 1] + (i & 1);
    For(i, 1, n){
        int x; read(x);
        a[x]++;
    }
    f[0][0][0] = 1;
    int o = 0;
    For(i, 1, t){
        o ^= 1;
        For(j, 0, n) For(p, 0, bas) if(f[o ^ 1][j][p]){
            if(cnt[p] + 1 <= m && j + a[i]){
                if(k > 1) add(f[o][j + a[i] - 1][((p << 1) & bas) | 1], 1ll * f[o ^ 1][j][p] * (j + a[i]) % mod);
                else add(f[o][j + a[i] - 1][0], 1ll * f[o ^ 1][j][p] * (j + a[i]) % mod);
            }
            add(f[o][j + a[i]][(p << 1) & bas], f[o ^ 1][j][p]);
            f[o ^ 1][j][p] = 0;
        }
    }
    int res = 0;
    For(i, 0, bas) add(res, f[o][0][i]);
    printf("%d\n", res);
    return 0; 
}
