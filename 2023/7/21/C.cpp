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
bitset<200> a[maxn + 5], b[maxn + 5], as;

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
    read(n); read(m);
    For(i, 1, m){
        int u, v; read(u); read(v);
        a[u][v] = !a[u][v];
        a[v][u] = !a[v][u];
    }
    // cout << a[1][2] << endl;
    For(i, 1, n){
        int fl = 0;
        bitset<200> tem = a[i];
        if(tem.count() & 1) tem[i] = tem[n + 1] = 1;
        For(j, 1, n){
            if(tem[j]) tem ^= b[j];
            if(tem[j]){
                For(p, j + 1, n) if(tem[p]) tem ^= b[p];
                For(p, 1, j - 1) if(b[p][j]) b[p] ^= tem;
                b[j] = tem;
                fl = 1;
                break;
            }
        }
        if(!fl && tem.count()){
            puts("-1");
            return 0;
        }
    }
    For(i, 1, n) printf("%d ", b[i][n + 1] != 0);
    return 0;
}
