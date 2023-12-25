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

int t, n, c, d, a[maxn + 5];
LL as = Inf;

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
    read(t);
    while(t--){
        as = Inf;
        read(n); read(c); read(d);
        For(i, 1, n) read(a[i]);
        sort(a + 1, a + n + 1);
        int m = unique(a + 1, a + n + 1) - a - 1;
        For(i, 1, m) as = min(as, 1ll * (a[i] - i) * d + 1ll * (n - i) * c);
        printf("%lld\n", min(as, 1ll * n * c + d));
    }
    return 0;
}
