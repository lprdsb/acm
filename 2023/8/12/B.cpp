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

int t, n;

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
        read(n);
        int mn1 = inf, mn2 = inf;
        LL res = 0;
        For(i, 1, n){
            int m; read(m);
            int mmn1 = inf, mmn2 = inf;
            For(j, 1, m){
                int x; read(x);
                if(x < mmn1) swap(x, mmn1);
                if(x < mmn2) swap(x, mmn2);
            }
            mn1 = min(mn1, mmn1);
            mn2 = min(mn2, mmn2);
            res += mmn2;
        }
        printf("%lld\n", res - mn2 + mn1);
    }
    return 0;
}
