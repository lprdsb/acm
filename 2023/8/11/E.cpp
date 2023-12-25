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
#define maxn 1005
#define mod 998244353
using namespace std;

int n, m, fac[maxn + 5], ifac[maxn + 5];
char s[maxn + 5];

struct Int{
    int a[maxn + 5];
    int& operator [] (cst int &ind){return a[ind];}
} L, R, bas, B;
Int operator + (Int _x, Int _y){
    For(i, 1, maxn){
        _x[i] += _y[i];
        if(_x[i] >= 10) _x[i + 1]++, _x[i] -= 10;
    }
    return _x;
}
Int operator + (Int _x, int _y){
    _x[1] += _y;
    int now = 1;
    while(_x[now] >= 10){
        _x[now + 1]++;
        _x[now] -= 10;
        now++;
    }
    return _x;
}
Int operator - (Int _x, Int _y){
    For(i, 1, maxn){
        _x[i] -= _y[i];
        if(_x[i] < 0) _x[i + 1]--, _x[i] += 10;
    }
    return _x;
}
Int operator * (Int _x, int y){
    For(i, 1, maxn) _x[i] *= y;
    For(i, 1, maxn){
        _x[i + 1] += _x[i] / 10;
        _x[i] %= 10;
    }
    return _x;
}


template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
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

int c(int x, int y){return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;}

int f[maxn + 5][35][25], g[25][305], h[55][25];
int sol(){
    f[1][0][0] = 1;
    For(t, -30, 9) For(res, 0, m - 1){
        h[30 + t][res] = 0;
        For(j, max(B[1], -t), min(30, 9 - t))
            h[30 + t][res] = (h[30 + t][res] + f[1][j - B[1]][(res + (t + j) * (t + j - 1)) % m]) % mod;
    }
    For(now, 2, maxn){
        For(up, 0, 20) For(res, 0, m - 1){
            f[now][up][res] = 0;
            For(t, -30, 9) if(10 * up + t >= 0)
                f[now][up][res] = (f[now][up][res] + 1ll * g[n][10 * up + t] * h[30 + t][res] % mod) % mod;
        }
        For(t, -30, 9) For(res, 0, m - 1){
            h[30 + t][res] = 0;
            For(j, max(B[now], -t), min(30, 9 - t))
                h[30 + t][res] = (h[30 + t][res] + f[now][j - B[now]][(res + (t + j) * (t + j - 1)) % m]) % mod;
        }
    }
    return f[maxn][0][0];
}

int main(){
	// freopen("in.txt", "r", stdin);
    g[0][0] = 1;
    For(i, 1, 20) For(j, 0, 200) For(p, 0, 9) if(j >= p) g[i][j] = (g[i][j] + g[i - 1][j - p]) % mod;
    
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    read(n); read(m);
    int len;
    scanf("%s", s + 1); len = strlen(s + 1); 
    For(i, 1, len) L[i] = s[len - i + 1] - '0';
    scanf("%s", s + 1); len = strlen(s + 1);
    For(i, 1, len) R[i] = s[len - i + 1] - '0';
    bas = L * n;
    int res = 0;
    For(i, 0, n){
        B = bas + (R - L + 1) * i;
        res = (res + 1ll * ((i & 1) ? -1 : 1) * c(n, i) * sol() % mod + mod) % mod;
    }
    printf("%d\n", res);
    return 0;
}
