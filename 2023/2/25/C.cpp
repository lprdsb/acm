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
#define maxn 400000
using namespace std;

int t, n, m, v[maxn + 5], a[maxn + 5];
LL as = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL c(int x){
    return 1ll * x * (x - 1) / 2;
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m);
        as = 0;
        For(i, 1, n + m) v[i] = 0;
        For(i, 1, n) read(a[i]), v[a[i]] = m + 1;
        For(i, 1, m){
            int pp, vv; read(pp); read(vv);
            v[a[pp]] -= m - i + 1;
            v[vv] += m - i + 1;
            a[pp] = vv;
        }
        For(i, 1, n + m) as += c(v[i]) + 1ll * v[i] * (m + 1 - v[i]);
        printf("%lld\n", as);
    }
    return 0;
}
