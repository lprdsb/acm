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
using namespace std;

int ma[600][600], s, t, n, m, f[600];

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
    read(n); read(m); read(s); read(t);
    For(i, 1, m){
        int u, v; read(u); read(v);
        if(u > v) swap(u, v);
        ma[u][v] = 1;
    }
    memset(f, -1, sizeof f);
    f[s] = 0;
    For(i, s + 1, t){
        int mn = 600;
        For(j, s, i - 1) if(f[j] != -1 && ma[j][i] && f[j] < mn) mn = f[j];
        if(mn == 600) continue;
        f[i] = mn + 1;
    }
    printf("%d\n", f[t]);
    return 0;
}
