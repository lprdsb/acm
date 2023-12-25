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
#define maxn 50
using namespace std;

int f[maxn + 5][maxn + 5], ok[5];

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
    f[0][0] = 0;
    For(i, 1, 50) f[0][i] = f[i][0] = i & 1;
    For(i, 1, 50) For(j, 1, 50){
        For(o, 0, 3) ok[o] = 0;
        ok[(i + j) & 1] = 1;
        ok[f[i - 1][j]] = 1;
        ok[f[i][j - 1]] = 1;
        For(o, 0, 3) if(!ok[o]){
            f[i][j] = o;
            break;
        }
    }
    For(i, 0, 10){
        For(j, 0, 10) cout << f[i][j] << " ";
        cout << endl;
    }
}
