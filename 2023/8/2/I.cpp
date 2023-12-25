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
#define maxn 400
using namespace std;

int P, t, n;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int I[maxn + 5], B[maxn + 5][maxn + 5], A[maxn + 5], fac[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(t); read(P);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    I[1] = 1;
    For(i, 2, maxn){
        I[i] = fac[i];
        For(j, 1, i - 1) I[i] = (I[i] - 1ll * I[j] * fac[i - j] % P + P) % P;
    }
    B[0][0] = 1;
    For(i, 1, maxn) For(j, 1, maxn) For(p, 1, i) B[i][j] = (B[i][j] + 1ll * B[i - p][j - 1] * fac[p] % P) % P;
    // A[0] = 1;
    A[1] = 1;
    A[2] = 2;
    A[3] = 0;
    For(i, 4, maxn){
        A[i] = fac[i];
        For(j, 1, i - 1) A[i] = (A[i] - 2ll * I[j] * fac[i - j] % P + P) % P;
        For(j, 3, i - 1) A[i] = (A[i] - 1ll * A[j] * B[i][j] % P + P) % P; 
    }
    while(t--){
        read(n);
        printf("%d\n", A[n]);
    }
    return 0;
}
