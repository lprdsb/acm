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
using namespace std;

int n, h, a[maxn + 5];
LL f[maxn + 5], g[maxn + 5][maxn + 5], val[maxn + 5][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void chkmn(LL &x, LL y){
    if(x == -1 || x > y) x = y;
}

LL get_val(int x, int h1, int h2){
    if(val[x][x + 1] == -1 || val[x][x + 1] > min(h1, h2)) return -1;
    return max(h1, h2) + val[x][x + 1];
}

LL sol(int l, int r){
    if(l == r) return h;
    LL asi = -1;
    For(i, l, r - 1){
        LL tem = get_val(i, h - (a[i] - a[l]), h - (a[r] - a[i + 1]));
        if(tem == -1 || g[l][i] == -1 || g[i + 1][r] == -1) continue;
        chkmn(asi, g[l][i] + g[i + 1][r] + a[i] - a[l] + a[r] - a[i + 1] + tem);
    }
    return asi;
}

int main(){
	freopen("in.txt", "r", stdin);
    memset(g, -1, sizeof g);
    memset(f, -1, sizeof f);
    read(n); read(h);
    For(i, 1, n) read(a[i]), g[i][i] = 0;
    For(i, 1, n) For(j, i + 1, n){
        val[i][j] = (a[j] - a[i] - 1) >> 1;
        if(val[i][j] > h) val[i][j] = -1;
    }
    For(o, 2, n) For(i, 1, n - o + 1) if(a[i + o - 1] - a[i] <= h) For(j, i, i + o -  2){
        if(val[i][j + o - 1] != -1 || g[i][j] != -1 || g[j][i + o - 1] != -1) continue;
        chkmn(g[i][i + o - 1], g[i][j] + g[j][i + o - 1] + val[i][j + o - 1]);
    }
    f[0] = 0;
    For(i, 1, n) For(j, 1, i) if(f[j - 1] != -1)
        chkmn(f[i], f[j - 1] + sol(j, i));
    printf("%lld\n", f[n]);
    return 0;
}
