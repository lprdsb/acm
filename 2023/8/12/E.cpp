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
#define maxn 3000
using namespace std;

LL t, n, a[maxn + 5], b[maxn + 5], k;
LL f[maxn + 5][maxn + 5][5];// 0 (-1 -1) (-1 1) (1 -1) (1 1)

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void chkmx(LL &x, LL y){
    if(x < y) x = y;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(k);
        For(i, 0, n) For(j, 0, k) For(o, 0, 4) f[i][j][o] = -Inf;
        f[0][0][0] = 0;
        For(i, 1, n) read(a[i]);
        For(i, 1, n) read(b[i]);
        For(i, 1, n){
            For(j, 0, k){
                f[i][j][0] = f[i - 1][j][0];
                if(j){
                    chkmx(f[i][j][0], f[i - 1][j - 1][0] + 2ll * abs(a[i] - b[i]));

                    chkmx(f[i][j][0], f[i - 1][j - 1][1] + a[i] + b[i]);
                    chkmx(f[i][j][0], f[i - 1][j - 1][2] - a[i] + b[i]);
                    chkmx(f[i][j][0], f[i - 1][j - 1][3] + a[i] - b[i]);
                    chkmx(f[i][j][0], f[i - 1][j - 1][4] - a[i] - b[i]);

                    chkmx(f[i][j][1], f[i - 1][j - 1][1]);
                    chkmx(f[i][j][2], f[i - 1][j - 1][2]);
                    chkmx(f[i][j][3], f[i - 1][j - 1][3]);
                    chkmx(f[i][j][4], f[i - 1][j - 1][4]);

                    chkmx(f[i][j][1], f[i - 1][j - 1][0] - a[i] - b[i]);
                    chkmx(f[i][j][2], f[i - 1][j - 1][0] - a[i] + b[i]);
                    chkmx(f[i][j][3], f[i - 1][j - 1][0] + a[i] - b[i]);
                    chkmx(f[i][j][4], f[i - 1][j - 1][0] + a[i] + b[i]);
                }
            }
        }
        printf("%lld\n", f[n][k][0]);
    }
    return 0;
}
