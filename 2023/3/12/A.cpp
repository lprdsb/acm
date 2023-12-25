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
#define mod 998244353
using namespace std;

int t, n;

struct Mat{
    int a[2][2];
} tra = {{{26, 24}, {1, 0}}};
Mat operator * (cst Mat &x, cst Mat &y){
    Mat asi = {};
    asi.a[0][0] = (1ll * x.a[0][0] * y.a[0][0] + 1ll * x.a[0][1] * y.a[1][0]) % mod;
    asi.a[0][1] = (1ll * x.a[0][0] * y.a[0][1] + 1ll * x.a[0][1] * y.a[1][1]) % mod;
    asi.a[1][0] = (1ll * x.a[1][0] * y.a[0][0] + 1ll * x.a[1][1] * y.a[1][0]) % mod;
    asi.a[1][1] = (1ll * x.a[1][0] * y.a[0][1] + 1ll * x.a[1][1] * y.a[1][1]) % mod;
    return asi;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

Mat fp(Mat x, int y){
    Mat asi = {{{1, 0}, {0, 1}}};
    while(y){
        if(y & 1) asi = asi * x;
        x = x * x;
        y >>= 1;
    }
    return asi;
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n);
        if(n == 1) puts("26");
        else if(n == 2) puts("676");
        else{
            Mat tem = fp(tra, n - 2);
            printf("%d\n", (676ll * tem.a[0][0] + 26ll * tem.a[0][1]) % mod);
        }
    }
    return 0;
}
