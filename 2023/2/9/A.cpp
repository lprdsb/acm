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

int m, ma[10][10];

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
    read(m);
    For(i, 1, m){
        int u, v; read(u); read(v);
        ma[u][v] = ma[v][u] = 1;
    }
    For(i, 1, 5) For(j, i + 1, 5) For(p, j + 1, 5){
        int tem = ma[i][j] + ma[j][p] + ma[i][p];
        if(tem == 3 || tem == 0){
            puts("WIN");
            return 0;
        }
    }
    puts("FAIL");
    return 0;
}
