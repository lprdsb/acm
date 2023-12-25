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
#define maxn 5000
using namespace std;

int T, n, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int f[maxn + 5][maxn + 5];
int fa[maxn + 5];
int g[2 * maxn + 5];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
int main(){
	// freopen("in.txt", "r", stdin);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    For(i, 0, maxn) fa[i] = i;
    read(T);
    while(T--){
        read(n);
        For(i, 1, n) read(a[i]);
        For(l, 1, n){
            For(r, l, n){
                if(find(a[r]) == a[r]) fa[a[r]] = find(a[r] + 1);
                f[find(0)][r] = l - 1;
            }
            For(i, 0, n) fa[i] = i;
        }
        For(i, 0, n) For(j, 1, n) f[i][j] = max(f[i][j], f[i][j - 1]);
        int res = 0;
        g[0] = n;
        For(i, 0, 2 * n){
            int mx = 0;
            For(j, 0, 2 * n) if(g[j] >= 0 && g[j] > g[mx]) mx = j;
            if(g[mx] <= -1) break;
            res = max(res, mx);
            For(j, 0, n) if((j ^ mx) <= 2 * n && f[j][g[mx]] != -1 && g[j ^ mx] != -2)
                g[j ^ mx] = max(g[j ^ mx], f[j][g[mx]]);
            g[mx] = -2;
        }
        printf("%d\n", res);
        For(i, 0, n) For(j, 1, n) f[i][j] = -1;
        For(i, 0, 2 * n) g[i] = -1;
    }
    return 0;
}
