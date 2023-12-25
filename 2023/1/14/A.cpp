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
#define maxn 100000
using namespace std;

int mod, n, a[maxn + 5], sum = 0;
map<int, bool> ma;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return asi;
}

bool chk(int x, int d){
    LL tem = x;
    int o = min(10000, n - 1);
    For(i, 1, o){
        tem += d;
        if(tem >= mod) tem -= mod; 
        if(x == tem || !ma[tem]) return 0;
    }
    return 1;
}

int main(){
	//freopen("in", "r", stdin);
    read(mod); read(n);
    For(i, 1, n) read(a[i]), sum = (1ll * sum + a[i]) % mod, ma[a[i]] = 1;
    if(n == 1) printf("%d 0\n", a[1]);
    else if(n == mod) puts("0 1");
    else{
        int tem = fp(1ll * n * (n - 1) % mod, mod - 2), fl = 0;
        For(i, 1, n){
            int d = (2ll * sum % mod - 2ll * n % mod * a[i] % mod + mod) % mod * tem % mod;
            if(!d) continue;
            if(chk(a[i], d)){
                fl = 1;
                printf("%d %d\n", a[i], d);
                break;
            }
        }
        if(!fl) puts("-1");
    }
    return 0;
}
