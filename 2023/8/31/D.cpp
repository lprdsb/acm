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
#define maxn 200000
using namespace std;

int t, n, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int f[maxn + 5], g[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n) read(a[i]);
        g[1] = 1;
        For(i, 2, n) g[i] = g[i - 1] + (a[i] >= a[i - 1]);
        f[n] = 1; f[n + 1] = 1;
        Rof(i, n - 1, 1) f[i] = f[i + 1] + (a[i] >= a[i + 1]);
        int res = n;
        For(i, 0, n) res = min(res, g[i] + f[i + 1] - 1);
        printf("%d\n", res);
    }
    return 0;
}
