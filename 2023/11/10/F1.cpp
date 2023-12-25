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
#define mod 1000000007
using namespace std;

int n, m, k, T;

struct Matrix{
    int _[50][50];
} tra, uni;
void add(int &x, cst int &y){
    x += y;
    if(x >= mod) x -= mod;
}
Matrix operator * (cst Matrix &_x, cst Matrix &_y){
    Matrix res = {};
    For(i, 1, m) For(j, 1, m){
        int tem = _x._[i][j];
        For(p, 1, m) add(res._[i][p], 1ll * tem * _y._[j][p] % mod);
    }
    return res;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

Matrix fp(Matrix x, int y){
    Matrix res = uni;
    while(y){
        if(y & 1) res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

int fp(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 1, 40) uni._[i][i] = 1;
    read(T);
    while(T--){
        read(n); read(m); read(k);
        int res = 0;
        if(m){
            For(i, 1, m) For(j, -min(50, k), min(50, k)) if(i + j >= 1 && i + j <= m) tra._[i][i + j] = 1;
            Matrix tem = fp(tra, n - 1);
            For(i, 1, m) For(j, 1, m) add(res, tem._[i][j]);
        }
        if(res) res = mod - res;
        add(res, 1ll * (m + k) * fp(2ll * k % mod + 1, n - 1) % mod);
        printf("%d\n", res);
        tra = {};
    }
    return 0;
}
