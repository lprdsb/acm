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

int a[maxn + 5][maxn + 5], b[maxn + 5];
int n, m, d[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool sol(){
    For(i, 1, n){
        For(j, 1, m) if(a[i][j]){
            For(p, 1, n) if(p != i && a[p][j]){
                For(q, 1, m) a[p][q] ^= a[i][q];
                b[p] ^= b[i];
            }
            break;
        }
    }
    For(i, 1, n){
        int fl = 0;
        For(j, 1, m) if(a[i][j]){
            fl = 1;
            break;
        }
        if(!fl) if(b[i]) return 0;
    }
    return 1;
}

int main(){
	freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF){
        For(i, 1, n) read(d[i]), b[i] = d[i] & 1;
        For(i, 1, m){
            int u, v; read(u); read(v);
            a[u][i] = a[v][i] = 1;
        }
        For(i, 1, n){
            For(j, 1, m) cout << a[i][j] << " "; cout << b[i] << endl;
        }
        puts(sol() ? "Yes" : "No");
        For(i, 1, n) For(j, 1, m) a[i][j] = 0;
    }
    return 0;
}
