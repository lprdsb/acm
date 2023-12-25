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

int n, a[2 * maxn + 5];
bitset<2 * maxn + 5> f;

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
    read(n);
    For(i, 1, n) read(a[i]);
    if(!a[1]){
        puts("0");
        return 0;
    }
    f[a[1] - 1] = 1;
    LL sum = a[1];
    LL as = a[1];
    For(i, 2, 2 * n){
        sum += a[i];
        if(f[0]) as = max(as, sum - i + 1);
        f |= f << a[i];
        f >>= 1;
    }
    printf("%lld\n", as);
    return 0;
}
