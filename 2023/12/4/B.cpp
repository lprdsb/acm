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
    int T;
    read(T);
    while(T--){
        LL n, l, t;
        LL p;
        read(n); read(p); read(l); read(t);
        int ok = (n - 1) / 7 + 1;
        if(1ll * (ok / 2) * (l + 2 * t) >= p) printf("%lld\n", n - (p + 2 * t + l - 1) / (2 * t + l));
        else if((ok & 1) && 1ll * (ok / 2) * (l + 2ll * t) + l + t >= p) printf("%lld\n", n - (ok / 2 + 1));
        else printf("%lld\n", n - (ok / 2) - (ok & 1) - (p - 1ll * (ok / 2) * (2ll * t + l) - (ok & 1) * (l + t) + l - 1) / l);
    }
    return 0;
}
