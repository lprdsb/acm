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
#define maxn 500
using namespace std;

int t, n, f[2][maxn + 5][maxn + 5][2], a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void chkmn(int &x, int y){if(x > y) x = y;}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n) read(a[i]);
        int o = 0;
        For(i, 0, n) For(j, 0, n) f[o][i][j][0] = f[o][i][j][1] = inf;
        f[o][0][0][0] = 0;
        For(i, 1, n){
            For(j, 0, n) For(p, 0, n) f[o ^ 1][j][p][0] = f[o ^ 1][j][p][1] = inf;
            For(j, 0, n) For(p, 0, n) if(f[o][j][p][0] != inf || f[o][j][p][1] != inf){
                if(a[i] > p) chkmn(f[o ^ 1][j][a[i]][0], min(f[o][j][p][0], f[o][j][p][1]));
                chkmn(f[o ^ 1][j][p][1], f[o][j][p][1] + 1);
                chkmn(f[o ^ 1][j + 1][p][1], f[o][j][p][0] + 1);
            }
            o ^= 1;
        }
        int asi = f[o][0][a[n]][0];
        For(i, 1, n){
            For(j, 1, n) chkmn(asi, min(f[o][i][j][0], f[o][i][j][1]));
            printf("%d ", asi);  
        }
        puts("");
    }
    return 0;
}
