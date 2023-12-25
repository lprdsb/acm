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
#define maxn 2000000
#define mod 998244353
using namespace std;

int k, a[maxn + 5], fac[maxn + 5];

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

int sol(int len){
    if(len == 1) return 1;
    int tem = 0, l = len >> 1, cnt = 0;
    for(int i = 1; i <= len; i += 2){
        int t1 = a[i], t2 = a[i + 1];
        if(!t1 && !t2){
            tem++;
            a[(i + 1) / 2] = 0;
            cnt++;
        }
        else if(t1 && t2){
            if(t1 > l && t2 > l) return 0;
            if(t1 <= l && t2 <= l) return 0;
            a[(i + 1) / 2] = min(t1, t2);
        }
        else{
            int ttem = t1 + t2;
            if(ttem <= l) a[(i + 1) / 2] = ttem, cnt++;
            else a[(i + 1) / 2] = 0;
        }
    }
    return 1ll * fp(2, tem) * fac[cnt] % mod * sol(l) % mod;
}

int main(){
	//freopen("in", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    read(k);
    For(i, 1, (1 << k)){
        int x; read(x);
        if(x != -1) a[x] = i;
    }
    printf("%d\n", sol(1 << k));
	return 0;
}
