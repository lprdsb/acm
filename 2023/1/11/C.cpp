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

int t;
LL n, x;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL sol(){
    LL tem1 = n, tem2 = x;
    int cnt = 0;
    while(tem1){
        if(tem2 & 1) return -1;
        tem1 >>= 1;
        tem2 >>= 1;
        cnt++;
        if(!(tem1 & 1) && tem1 == tem2) return (tem1 << cnt) + (1ll << cnt);
    }
    return -1;
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n); read(x);
        if(n == x){
            printf("%lld\n", n);
            continue;
        }
        printf("%lld\n", sol());
    }
    return 0;
}
