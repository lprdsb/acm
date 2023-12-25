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
#define maxn 100
using namespace std;

int n, m;
bitset<maxn + 5> fri[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bitset<maxn + 5> bas[maxn + 5];
bool sol(bitset<maxn + 5> x){
    For(i, 1, n) if(x[i]) x ^= bas[i];
    int fl = 0;
    For(i, 1, n) if(x[i]){
        bas[i] = x;
        return 1;
    }
    return !x[n + 1];
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, m){
        int u, v; read(u); read(v);
        fri[u][v] = 1;
        fri[v][u] = 1;
    }
    For(i, 1, n){
        bitset<maxn + 5> tem = fri[i];
        if(fri[i].count() & 1) tem[i] = 1;
        else tem[n + 1] = 1;
        if(!sol(tem)){
            puts("N");
            return 0;
        }
    }
    puts("Y");
	return 0;
}
