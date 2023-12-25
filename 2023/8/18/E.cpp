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

int t, n, m;
vector<int> ch[605];
bitset<605> f[605];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m);
        For(i, 1, n){
            int k; read(k);
            ch[i].resize(0);
            f[i][i] = 1;
            For(j, 1, k){
                int v; read(v); v++;
                ch[i].pb(n + v);
                f[i][n + v] = 1;
            }
        }
        For(i, 1, m){
            int k; read(k);
            ch[n + i].resize(0);
            f[n + i][n + i] = 1;
            For(j, 1, k){
                int v; read(v); v++;
                ch[n + i].pb(v);
                if(k == 1) f[n + i][v] = 1;
            }
        }
        For(o, 1, 11){
            For(i, 1, n){
                For(j, 1, n + m) if(f[i][j]) f[i] |= f[j];
            }
            For(i, 1, m){
                bitset<605> tem;
                For(j, 1, n + m) tem[j] = 1;
                for(auto j : ch[n + i]) tem &= f[j];
                f[n + i] |= tem;
            }
        }
        // For(i, 1, n) cout << f[2][i] << " "; cout << endl;
        // For(i, 1, m) cout << f[2][n + i] << " "; cout << endl;
        int fl = 1;
        For(i, 1, n + m) if(f[i].count() != n + m){
            fl = 0;
            break;
        }
        puts(fl ? "Yes" : "No");
        For(i, 1, n + m) f[i] = 0;
    }
    return 0;
}