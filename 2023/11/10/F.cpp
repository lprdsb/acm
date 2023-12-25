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

int T;

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

int get_in(int l1, int r1, int l2, int r2){
    if(l1 > l2) swap(l1, l2), swap(r1, r2);
    if(r1 >= l2) return min(r1, r2) - l2 + 1;
    return 0;
}

int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        int n, k, x; read(n); read(k); read(x);
        int res = 0, pwk1 = fp(k + 1, n), pwk = fp(k, n);
        For(i, max(0, x - k - 2), x + k - 1){
            res = (1ll * res + pwk1 - pwk - fp(k + 1 - get_in(i, i + k, x, x + k - 1), n) + fp(k + 1 - get_in(i, i + k, x, x + k - 1) - (i < x), n)) % mod;
            if(res < 0) res += mod;
        }
        printf("%d\n", res);
    }
    return 0;
}
